// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/Context.h"

struct Nucleus_DataLanguage_Token
{
    Nucleus_DataLanguage_Token_Kind kind;
    Nucleus_DataLanguage_SourceLocation *begin,
                      *end;
    Nucleus_DataLanguage_String *text;
};

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_DataLanguage_String *text
    );
