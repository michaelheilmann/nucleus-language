/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/ScannerState.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Source.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_ScannerState *self
    );

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_ScannerState *self
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_ScannerState *self
    );

struct DL_ScannerState
{
    DL_Object _parent;
    DL_Source *source;
    DL_Token_Kind tokenKind;
    int lineNumber;
    DL_StringIterator *iterator;
};

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{}

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_ScannerState *self
    )
{
    DL_Context_assertNotNull(context, self);
    self->tokenKind = DL_Token_Kind_Begin;
    DL_ErrorHandler eh;
    DL_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        self->source = DL_Source_createDefault(context);
        DL_Context_popErrorHandler(context);
    }
    else
    {
        DL_Context_popErrorHandler(context);
        DL_Context_raiseError(context, DL_Context_getStatus(context));
    }
    self->lineNumber = 1;
    self->iterator = DL_StringIterator_create(context, DL_Source_getString(context, self->source));
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_ScannerState *self
    )
{}

DL_NonNull() DL_ScannerState *
DL_ScannerState_create
    (
        DL_Context *context
    )
{
    DL_ScannerState *self = (DL_ScannerState *)DL_Context_allocateObject(context, sizeof(DL_ScannerState));
    initialize(context, self);
    ((DL_Object *)(self))->finalize = (DL_Finalize *)&finalize;
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_Source *
DL_ScannerState_getSource
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{
    DL_Context_assertNotNull(context, scannerState);
    return scannerState->source;
}

DL_NonNull() void
DL_ScannerState_setSource
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, scannerState);
    DL_Context_assertNotNull(context, source);
    DL_StringIterator_setInput(context, scannerState->iterator,
                               DL_Source_getString(context, source));
    scannerState->source = source;
    scannerState->tokenKind = DL_Token_Kind_Begin;
    scannerState->lineNumber = 1;
}

DL_NonNull() DL_SourceLocation *
DL_ScannerState_getSourceLocation
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{ 
    DL_SourceLocation *sourceLocation = DL_SourceLocation_create(context, scannerState->source,
                                                                          scannerState->lineNumber,
                                                                          DL_StringIterator_getOffset(context, scannerState->iterator));
    return sourceLocation;
}

DL_NonNull() void
DL_ScannerState_setSourceLocation
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        DL_SourceLocation *sourceLocation
    )
{
    DL_StringIterator_setInput(context, scannerState->iterator,
                               DL_Source_getString(context, sourceLocation->source));
    for (size_t i = 0, n = sourceLocation->offset; i < n; ++i)
    { DL_StringIterator_increment(context, scannerState->iterator); }
    scannerState->source = sourceLocation->source;
    scannerState->lineNumber = sourceLocation->lineNumber;
}

DL_NonNull() void
DL_ScannerState_increment
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{ DL_StringIterator_increment(context, scannerState->iterator); }

DL_NonNull() void
DL_ScannerState_decrement
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{ DL_StringIterator_decrement(context, scannerState->iterator); }

DL_NonNull() DL_Symbol
DL_ScannerState_getSymbol
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{ return DL_StringIterator_get(context, scannerState->iterator); }

DL_NonNull() void
DL_ScannerState_incrementLineNumber
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{
    DL_Context_assertNotNull(context, scannerState);
    scannerState->lineNumber++;
}

DL_NonNull() DL_String *
DL_ScannerState_getLexeme
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        size_t start,
        size_t length
    )
{ return DL_String_create(context, DL_Source_getBegin(context, scannerState->source) + start - 1, length); }
