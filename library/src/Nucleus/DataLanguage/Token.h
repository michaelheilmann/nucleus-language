// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Token_Kind.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Data Language token.
typedef struct Nucleus_DataLanguage_Token Nucleus_DataLanguage_Token;

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Token_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_Interpreter_String *text
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getBegin
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getEnd
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token_Kind
Nucleus_DataLanguage_Token_getKind
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Token_getText
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    );
