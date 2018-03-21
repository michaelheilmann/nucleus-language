/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"
#include "Nucleus/DataLanguage/Token_Kind.h"
#include "Nucleus/DataLanguage/SourceLocation.h"

DL_NonNull() DL_ScannerState *
DL_ScannerState_create
    (
        DL_Context *context
    );

DL_NonNull() DL_Source *
DL_ScannerState_getSource
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() void
DL_ScannerState_setSource
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        DL_Source *source
    );

DL_NonNull() DL_SourceLocation *
DL_ScannerState_getSourceLocation
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() void
DL_ScannerState_setSourceLocation
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        DL_SourceLocation *sourceLocation
    );

DL_NonNull() void
DL_ScannerState_increment
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() void
DL_ScannerState_decrement
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() DL_Symbol
DL_ScannerState_getSymbol
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() void
DL_ScannerState_incrementLineNumber
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );

DL_NonNull() DL_String *
DL_ScannerState_getLexeme
    (
        DL_Context *context,
        DL_ScannerState *scannerState,
        size_t begin,
        size_t length
    );
