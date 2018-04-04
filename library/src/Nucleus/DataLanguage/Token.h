/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"
#include "Nucleus/DataLanguage/Token_Kind.h"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Token_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_DataLanguage_String *text
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getBegin
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getEnd
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Token_Kind
Nucleus_DataLanguage_Token_getKind
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Token_getText
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    );
