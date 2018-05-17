// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/LineMap-private.c.in"

Nucleus_Interpreter_NonNull() static void
build
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *source,
        size_t **lines,
        size_t *numberOfLines
    );

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_LineMap *lineMap,
        Nucleus_Interpreter_String *source
    );

Nucleus_Interpreter_NonNull() static void
build
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *source,
        Nucleus_Interpreter_Size **lines,
        Nucleus_Interpreter_Size *numberOfLines
    )
{
    if (!source || !lines || !numberOfLines)
	{
		Nucleus_Interpreter_ProcessContext_setStatus(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context), Nucleus_Interpreter_Status_InvalidArgument);
		Nucleus_Interpreter_ProcessContext_jump(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
	}
    // Regardless of wether the file is empty, there is one source line (with line index 0) with
	// start offset 0. That is, the number of lines is always greater than or equal to 1.
    
	Nucleus_Interpreter_Size *lines0, *lines2;
    Nucleus_Status status;
	Nucleus_Interpreter_ProcessContext *processContext =
		NUCLEUS_INTERPRETER_PROCESSCONTEXT(context);
	
    // Compute array of line indices.
	lines0 = 
		(Nucleus_Interpreter_Size *)Nucleus_Interpreter_ProcessContext_allocateUnmanagedArrayMemory
											(
												processContext,
												MAX_LINES,
												sizeof(Nucleus_Interpreter_Size)
											);
    lines0[0] = 0;
	Nucleus_Interpreter_Size lineIndex = 0; // The index of the first line.
    Nucleus_Interpreter_JumpTarget jt;
    Nucleus_Interpreter_ProcessContext_pushJumpTarget(processContext, &jt);
    if (!setjmp(jt.environment))
    {
        const Nucleus_Interpreter_Symbol carriageReturn = Nucleus_Interpreter_Symbol_carriageReturn(context),
            lineFeed = Nucleus_Interpreter_Symbol_lineFeed(context),
            end = Nucleus_Interpreter_Symbol_end(context);

        Nucleus_Interpreter_StringIterator *sourceIterator = Nucleus_Interpreter_StringIterator_create(context, source);
        Nucleus_Interpreter_StringIterator_increment(context, sourceIterator);

        Nucleus_Interpreter_Symbol currentSymbol = Nucleus_Interpreter_StringIterator_get(context, sourceIterator);
        while (Nucleus_Interpreter_Symbol_notEqualTo(context, end, currentSymbol))
        {
            // '\r', '\n', '\r\n'
            if (Nucleus_Interpreter_Symbol_equalTo(context, carriageReturn, currentSymbol) ||
                Nucleus_Interpreter_Symbol_equalTo(context, lineFeed, currentSymbol))
            {
                Nucleus_Interpreter_StringIterator_increment(context, sourceIterator);

                Nucleus_Interpreter_Symbol nextSymbol = Nucleus_Interpreter_StringIterator_get(context, sourceIterator);
                if (Nucleus_Interpreter_Symbol_equalTo(context, carriageReturn, currentSymbol) &&
                    Nucleus_Interpreter_Symbol_equalTo(context, lineFeed, nextSymbol))
                {
                    Nucleus_Interpreter_StringIterator_increment(context, sourceIterator);
                    nextSymbol = Nucleus_Interpreter_StringIterator_get(context, sourceIterator);
                }
                currentSymbol = nextSymbol;
                lineIndex++;
                lines0[lineIndex] = Nucleus_Interpreter_StringIterator_getOffset(context, sourceIterator);
            }
            else
            {
                Nucleus_Interpreter_StringIterator_increment(context, sourceIterator);
                currentSymbol = Nucleus_Interpreter_StringIterator_get(context, sourceIterator);
            }
        }
        Nucleus_Interpreter_ProcessContext_popJumpTarget(processContext);
    }
	else
	{
        Nucleus_Interpreter_ProcessContext_popJumpTarget(processContext);
        Nucleus_Interpreter_ProcessContext_deallocateUnmanagedMemory(processContext, lines0);
        Nucleus_Interpreter_ProcessContext_jump(processContext);
    }

	// Create optimized array.
    Nucleus_Interpreter_Size *lines1 = NULL;
    Nucleus_Interpreter_ProcessContext_pushJumpTarget(processContext, &jt);
    if (!setjmp(jt.environment))
	{
		lines1 =
			Nucleus_Interpreter_ProcessContext_allocateUnmanagedArrayMemory
				(
					processContext, 
					lineIndex + 1,
					sizeof(Nucleus_Interpreter_Size)
				);
        Nucleus_Interpreter_ProcessContext_popJumpTarget(processContext);	
	}
	else
	{
        Nucleus_Interpreter_ProcessContext_popJumpTarget(processContext);
        Nucleus_Interpreter_ProcessContext_deallocateUnmanagedMemory(processContext, lines0);
        Nucleus_Interpreter_ProcessContext_jump(processContext);
	}
	Nucleus_copyArrayMemory(lines1, lines0, lineIndex + 1, sizeof(Nucleus_Interpreter_Size));
	Nucleus_Interpreter_ProcessContext_deallocateUnmanagedMemory(processContext, lines0);
	
	// Return optimized array.
    *lines = lines1;
    *numberOfLines = lineIndex + 1;
}

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_LineMap *lineMap,
        Nucleus_Interpreter_String *source
    )
{
    lineMap->source = source;
    build(context, source, &lineMap->lines, &lineMap->numberOfLines);
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_LineMap *
Nucleus_DataLanguage_LineMap_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *source
    )
{
    Nucleus_DataLanguage_LineMap *self = (Nucleus_DataLanguage_LineMap *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_LineMap));
    initialize(context, self, source);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_LineMap_getLineIndex
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_LineMap *lineMap,
        Nucleus_Interpreter_Size offset
    )
{
    Nucleus_Interpreter_Size l = 0,
                             r = (lineMap->numberOfLines) - 1;
    while (l <= r)
    {
        Nucleus_Interpreter_Size m = (l + r) / 2;
        Nucleus_Interpreter_Size o = lineMap->lines[m];
        if (offset > o)
            l = m + 1;
        else if (offset < o)
            r = m - 1;
        else
            return m;
    }
    return l;
}
