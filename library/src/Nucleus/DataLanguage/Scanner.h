#pragma once

#include "Nucleus/DataLanguage/Forward.h"

typedef struct Nucleus_DataLanguage_Scanner Nucleus_DataLanguage_Scanner;

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Scanner *
Nucleus_DataLanguage_Scanner_create
    (
        Nucleus_DataLanguage_Context *context,
        bool skipComments
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Scanner_scan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Scanner_getSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Scanner_setSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Scanner_getSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Scanner_setSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Scanner_getSymbol
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Scanner_increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );
