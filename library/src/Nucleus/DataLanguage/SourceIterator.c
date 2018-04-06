/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/SourceIterator-private.c.i"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceIterator *
Nucleus_DataLanguage_SourceIterator_create
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_SourceIterator *self = (Nucleus_DataLanguage_SourceIterator *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(Nucleus_DataLanguage_SourceIterator));
    initialize(context, self);
    ((Nucleus_DataLanguage_HeapObject *)(self))->finalize = (Nucleus_DataLanguage_HeapObject_Finalize *)&finalize;
    ((Nucleus_DataLanguage_HeapObject *)(self))->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_SourceIterator_getSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{
    Nucleus_DataLanguage_Context_assertNotNull(context, sourceIterator);
    return sourceIterator->source;
}

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_DataLanguage_Context_assertNotNull(context, sourceIterator);
    Nucleus_DataLanguage_Context_assertNotNull(context, source);
    Nucleus_DataLanguage_StringIterator_setInput(context, sourceIterator->iterator,
                               Nucleus_DataLanguage_Source_getString(context, source));
    sourceIterator->source = source;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceIterator_getSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ 
    Nucleus_DataLanguage_SourceLocation *sourceLocation = Nucleus_DataLanguage_SourceLocation_create(context, sourceIterator->source,
                                                                          Nucleus_DataLanguage_StringIterator_getOffset(context, sourceIterator->iterator));
    return sourceLocation;
}

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    )
{
    Nucleus_DataLanguage_StringIterator_setInput(context, sourceIterator->iterator,
                               Nucleus_DataLanguage_Source_getString(context, sourceLocation->source));
    for (size_t i = 0, n = sourceLocation->offset; i < n; ++i)
    { Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator->iterator); }
    sourceIterator->source = sourceLocation->source;
}

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ Nucleus_DataLanguage_StringIterator_increment(context, sourceIterator->iterator); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_decrement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ Nucleus_DataLanguage_StringIterator_decrement(context, sourceIterator->iterator); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_SourceIterator_getSymbol
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{ return Nucleus_DataLanguage_StringIterator_get(context, sourceIterator->iterator); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_SourceIterator_getLexeme
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        size_t start,
        size_t length
    )
{
    /// @todo This should be subsumed by Nucleus_DataLanguage_String_getSubString().
    Nucleus_DataLanguage_String *sourceString = Nucleus_DataLanguage_Source_getString(context, sourceIterator->source);
    const char *sourceStringBytes = Nucleus_DataLanguage_String_getBytes(context, sourceString);
    return Nucleus_DataLanguage_String_create(context, sourceStringBytes + start - 1, length);
}
