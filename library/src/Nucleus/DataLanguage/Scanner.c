#include "Nucleus/DataLanguage/Scanner.h"

#include "Nucleus/DataLanguage/Scanner-private.c.in"

DL_NonNull() DL_Scanner *
DL_Scanner_create
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    )
{
    DL_Scanner *self = (DL_Scanner *)DL_Context_allocateObject(context, sizeof(DL_Scanner));
    initialize(context, self, scannerState);
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_Token *
DL_Scanner_scan
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return scan(context, scanner); }

DL_NonNull() DL_Source *
DL_Scanner_getSource
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_ScannerState_getSource(context, scanner->scannerState); }

DL_NonNull() void
DL_Scanner_setSource
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_Source *source
    )
{ DL_ScannerState_setSource(context, scanner->scannerState, source); }

DL_NonNull() DL_Symbol
DL_Scanner_getSymbol
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_ScannerState_getSymbol(context, scanner->scannerState); }

DL_NonNull() void
DL_Scanner_incrementLineNumber
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ DL_ScannerState_incrementLineNumber(context, scanner->scannerState); }

DL_NonNull() void
DL_Scanner_increment
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ DL_ScannerState_increment(context, scanner->scannerState); }
