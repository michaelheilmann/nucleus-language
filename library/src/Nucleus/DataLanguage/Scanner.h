// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

// Forward declarations.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;
typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;
typedef struct Nucleus_DataLanguage_Token Nucleus_DataLanguage_Token;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language scanner.
typedef struct Nucleus_DataLanguage_Scanner Nucleus_DataLanguage_Scanner;

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Scanner *
Nucleus_DataLanguage_Scanner_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Boolean skipComments
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Scanner_scan
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Scanner_getSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_setSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Scanner_getSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_setSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol
Nucleus_DataLanguage_Scanner_getSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );
