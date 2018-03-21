/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/ParserState.h"

//#include "Nucleus/Language.h"
#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_ParserState *self,
        DL_ScannerState *scannerState
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_ParserState *self
    );

struct DL_ParserState
{
    int dummy;
};

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_ParserState *self,
        DL_ScannerState *scannerState
    )
{
    if (!self || !scannerState)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_ParserState *self
    )
{}

DL_NonNull() DL_ParserState *
DL_ParserState_create
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{
    DL_ParserState *self = (DL_ParserState *)DL_Context_allocateObject(context, sizeof(DL_ParserState));
    initialize(context, self, scannerState);
    ((DL_Object *)self)->visit = (DL_Visit *)&visit;
    return self;
}
