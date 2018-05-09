// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/SourceIterator-private.c.i"

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceIterator *
Nucleus_DataLanguage_SourceIterator_create
    (
        Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_SourceIterator *self = (Nucleus_DataLanguage_SourceIterator *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_SourceIterator));
    initialize(context, self);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_SourceIterator_getSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{
    Nucleus_Interpreter_Context_assertNotNull(context, sourceIterator);
    return sourceIterator->source;
}

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_Interpreter_Context_assertNotNull(context, sourceIterator);
    Nucleus_Interpreter_Context_assertNotNull(context, source);
    Nucleus_Interpreter_StringIterator_setInput(context, sourceIterator->iterator,
                                                Nucleus_DataLanguage_Source_getString(context, source));
    sourceIterator->source = source;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceIterator_getSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ 
    return
		Nucleus_DataLanguage_SourceLocation_create
			(
				context,
				sourceIterator->source,
                Nucleus_Interpreter_StringIterator_getOffset
					(
						context,
						sourceIterator->iterator
					)
			);
}

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    )
{
    Nucleus_Interpreter_StringIterator_setInput
		(
			context,
			sourceIterator->iterator,
            Nucleus_DataLanguage_Source_getString
				(
					context,
					sourceLocation->source
				)
		);
    for (Nucleus_Interpreter_Size i = 0, n = sourceLocation->offset; i < n; ++i)
    { Nucleus_Interpreter_StringIterator_increment(context, sourceIterator->iterator); }
    sourceIterator->source = sourceLocation->source;
}

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ Nucleus_Interpreter_StringIterator_increment(context, sourceIterator->iterator); }

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_decrement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ Nucleus_Interpreter_StringIterator_decrement(context, sourceIterator->iterator); }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol
Nucleus_DataLanguage_SourceIterator_getSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ return Nucleus_Interpreter_StringIterator_get(context, sourceIterator->iterator); }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_SourceIterator_getLexeme
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_Interpreter_Size start,
        Nucleus_Interpreter_Size length
    )
{
    /// @todo This should be subsumed by Nucleus_Interpreter_String_getSubString().
    Nucleus_Interpreter_String *sourceString = Nucleus_DataLanguage_Source_getString(context, sourceIterator->source);
    const char *sourceStringBytes = Nucleus_Interpreter_String_getBytes(context, sourceString);
    return Nucleus_Interpreter_String_create(context, sourceStringBytes + start - 1, length);
}
