/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"
#include "Nucleus/DataLanguage/Token_Kind.h"

DL_NonNull() DL_Token *
DL_Token_create
    (
        DL_Context *context,
        DL_Token_Kind kind,
        DL_SourceLocation *begin,
        DL_SourceLocation *end,
        DL_String *text
    );

DL_NonNull() DL_SourceLocation *
DL_Token_getBegin
    (
        DL_Context *context,
        DL_Token *token
    );

DL_NonNull() DL_SourceLocation *
DL_Token_getEnd
    (
        DL_Context *context,
        DL_Token *token
    );

DL_NonNull() DL_Token_Kind
DL_Token_getKind
    (
        DL_Context *context,
        DL_Token *token
    );

DL_NonNull() DL_String *
DL_Token_getText
    (
        DL_Context *context,
        DL_Token *token
    );
