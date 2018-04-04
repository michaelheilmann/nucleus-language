#include "Nucleus/DataLanguage/LineMap.h"

#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-StringIterator.h"
#include "Nucleus/Memory.h"

#define MAX_LINES (5012)

Nucleus_DataLanguage_NonNull() static void
build
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source,
        size_t **lines,
        size_t *numberOfLines
    );

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() static void
build
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source,
        size_t **lines,
        size_t *numberOfLines
    )
{
    if (!source || !lines || !numberOfLines) Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_AllocationFailed);
    // Regardless of wether the file is empty, there is one source line (with line index 0) with start offset 0.
    // That is, the number of lines is always greater than or equal to 1.
    
    size_t *lines0;
    Nucleus_Status status;
    
    status = Nucleus_allocateArrayMemory((void **)&lines0, MAX_LINES, sizeof(size_t));
    if (status) Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_AllocationFailed);
    lines0[0] = 0;
    size_t lineIndex = 0; // The index of the first line.
    Nucleus_DataLanguage_JumpTarget jt;
    Nucleus_DataLanguage_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        const Nucleus_DataLanguage_Symbol carriageReturn = Nucleus_DataLanguage_Symbol_carriageReturn(context),
            lineFeed = Nucleus_DataLanguage_Symbol_lineFeed(context),
            end = Nucleus_DataLanguage_Symbol_end(context);

        Nucleus_DataLanguage_StringIterator *sourceIterator = Nucleus_DataLanguage_StringIterator_create(context, source);
        Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator);

        Nucleus_DataLanguage_Symbol currentSymbol = Nucleus_DataLanguage_StringIterator_get(context, sourceIterator);
        while (Nucleus_DataLanguage_Symbol_notEqualTo(context, end, currentSymbol))
        {
            // '\r', '\n', '\r\n'
            if (Nucleus_DataLanguage_Symbol_equalTo(context, carriageReturn, currentSymbol) ||
                Nucleus_DataLanguage_Symbol_equalTo(context, lineFeed, currentSymbol))
            {
                Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator);

                Nucleus_DataLanguage_Symbol nextSymbol = Nucleus_DataLanguage_StringIterator_get(context, sourceIterator);
                if (Nucleus_DataLanguage_Symbol_equalTo(context, carriageReturn, currentSymbol) &&
                    Nucleus_DataLanguage_Symbol_equalTo(context, lineFeed, nextSymbol))
                {
                    Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator);
                    nextSymbol = Nucleus_DataLanguage_StringIterator_get(context, sourceIterator);
                }
                currentSymbol = nextSymbol;
                lineIndex++;
                lines0[lineIndex] = Nucleus_DataLanguage_StringIterator_getOffset(context, sourceIterator);
            }
            else
            {
                Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator);
                currentSymbol = Nucleus_DataLanguage_StringIterator_get(context, sourceIterator);
            }
        }
        Nucleus_DataLanguage_Context_popJumpTarget(context);
    } else {
        Nucleus_DataLanguage_Context_popJumpTarget(context);
        Nucleus_deallocateMemory(lines0);
        Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Context_getStatus(context));
    }
    // Regardless of wether the file is empty or not,
    // there is always
    status = Nucleus_reallocateArrayMemory((void **)&lines0, lineIndex + 1, sizeof(size_t));
    if (status)
    {
        Nucleus_deallocateMemory(lines0);
        Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_AllocationFailed);
    }
    *lines = lines0;
    *numberOfLines = lineIndex+1;
}

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap,
        Nucleus_DataLanguage_String *source
    )
{
    lineMap->source = source;
    build(context, source, &lineMap->lines, &lineMap->numberOfLines);
}

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap
    )
{}

Nucleus_DataLanguage_NonNull() static void
finalize
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap
    )
{
    free(lineMap->lines);
    lineMap->lines = NULL;
}

Nucleus_DataLanguage_NonNull() DL_LineMap *
DL_LineMap_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{
    DL_LineMap *self = (DL_LineMap *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_LineMap));
    initialize(context, self, source);
    ((Nucleus_DataLanguage_HeapObject *)(self))->finalize = (Nucleus_DataLanguage_HeapObject_Visit *)&finalize;
    ((Nucleus_DataLanguage_HeapObject *)(self))->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() size_t
DL_LineMap_getLineIndex
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap,
        size_t offset
    )
{
    size_t l = 0,
           r = (lineMap->numberOfLines) - 1;
    while (l <= r)
    {
        size_t m = (l + r) / 2;
        size_t o = lineMap->lines[m];
        if (offset > o)
            l = m + 1;
        else if (offset < o)
            r = m - 1;
        else
            return m;
    }
    return l;
}
