/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/SourceIterator-private.c.i"

DL_NonNull() DL_SourceIterator *
DL_SourceIterator_create
    (
        DL_Context *context
    )
{
    DL_SourceIterator *self = (DL_SourceIterator *)DL_Context_allocateObject(context, sizeof(DL_SourceIterator));
    initialize(context, self);
    ((DL_Object *)(self))->finalize = (DL_Finalize *)&finalize;
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_Source *
DL_SourceIterator_getSource
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{
    DL_Context_assertNotNull(context, sourceIterator);
    return sourceIterator->source;
}

DL_NonNull() void
DL_SourceIterator_setSource
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, sourceIterator);
    DL_Context_assertNotNull(context, source);
    DL_StringIterator_setInput(context, sourceIterator->iterator,
                               DL_Source_getString(context, source));
    sourceIterator->source = source;
}

DL_NonNull() DL_SourceLocation *
DL_SourceIterator_getSourceLocation
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{ 
    DL_SourceLocation *sourceLocation = DL_SourceLocation_create(context, sourceIterator->source,
                                                                          DL_StringIterator_getOffset(context, sourceIterator->iterator));
    return sourceLocation;
}

DL_NonNull() void
DL_SourceIterator_setSourceLocation
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        DL_SourceLocation *sourceLocation
    )
{
    DL_StringIterator_setInput(context, sourceIterator->iterator,
                               DL_Source_getString(context, sourceLocation->source));
    for (size_t i = 0, n = sourceLocation->offset; i < n; ++i)
    { DL_StringIterator_increment(context, sourceIterator->iterator); }
    sourceIterator->source = sourceLocation->source;
}

DL_NonNull() void
DL_SourceIterator_increment
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{ DL_StringIterator_increment(context, sourceIterator->iterator); }

DL_NonNull() void
DL_SourceIterator_decrement
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{ DL_StringIterator_decrement(context, sourceIterator->iterator); }

DL_NonNull() DL_Symbol
DL_SourceIterator_getSymbol
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{ return DL_StringIterator_get(context, sourceIterator->iterator); }

DL_NonNull() DL_String *
DL_SourceIterator_getLexeme
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        size_t start,
        size_t length
    )
{
    /// @todo This should be subsumed by DL_String_getSubString().
    DL_String *sourceString = DL_Source_getString(context, sourceIterator->source);
    const char *sourceStringBytes = DL_String_getBytes(context, sourceString);
    return DL_String_create(context, sourceStringBytes + start - 1, length);
}
