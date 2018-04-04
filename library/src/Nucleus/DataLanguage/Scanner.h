#pragma once

#include "Nucleus/DataLanguage/Forward.h"

typedef struct DL_Scanner DL_Scanner;

DL_NonNull() DL_Scanner *
DL_Scanner_create
    (
        DL_Context *context
    );

DL_NonNull() DL_Token *
DL_Scanner_scan
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() DL_Source *
DL_Scanner_getSource
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() void
DL_Scanner_setSource
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_Source *source
    );

DL_NonNull() DL_SourceLocation *
DL_Scanner_getSourceLocation
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() void
DL_Scanner_setSourceLocation
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_SourceLocation *sourceLocation
    );

DL_NonNull() DL_Symbol
DL_Scanner_getSymbol
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() void
DL_Scanner_increment
    (
        DL_Context *context,
        DL_Scanner *scanner
    );
