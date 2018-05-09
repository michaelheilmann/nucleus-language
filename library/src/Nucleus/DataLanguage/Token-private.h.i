// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Token.h"

struct Nucleus_DataLanguage_Token
{
    Nucleus_DataLanguage_Token_Kind kind;
    Nucleus_DataLanguage_SourceLocation *begin,
                      *end;
    Nucleus_Interpreter_String *text;
};

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *self
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *self,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_Interpreter_String *text
    );
