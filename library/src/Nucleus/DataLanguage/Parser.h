// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

// Forward declarations.
typedef struct Nucleus_DataLanguage_AST_Node Nucleus_DataLanguage_AST_Node;
typedef struct Nucleus_DataLanguage_Scanner Nucleus_DataLanguage_Scanner;
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language parser.
typedef struct Nucleus_DataLanguage_Parser Nucleus_DataLanguage_Parser;

Nucleus_Interpreter_ReturnNonNull() Nucleus_DataLanguage_Parser *
Nucleus_DataLanguage_Parser_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Parser_getSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Parser_setSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_Parser_run
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );
