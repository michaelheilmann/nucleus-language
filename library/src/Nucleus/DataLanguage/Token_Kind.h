// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

/// @ingroup dl
/// @brief An enumeration of DL token kinds.
typedef enum Nucleus_DataLanguage_Token_Kind Nucleus_DataLanguage_Token_Kind;

enum Nucleus_DataLanguage_Token_Kind
{
    /// @brief Token kind of a name.
    Nucleus_DataLanguage_Token_Kind_Name,

    /// @brief Token kind of a colon.
    Nucleus_DataLanguage_Token_Kind_Colon,

    /// @brief Token kind of a comma.
    Nucleus_DataLanguage_Token_Kind_Comma,

    /// @brief Token kind of a true literal.
    Nucleus_DataLanguage_Token_Kind_TrueLiteral,

    /// @brief Token kind of a false literal.
    Nucleus_DataLanguage_Token_Kind_FalseLiteral,

    /// @brief Token kind of a string literal.
    Nucleus_DataLanguage_Token_Kind_StringLiteral,

    /// @brief Token kind of an integer literal.
    Nucleus_DataLanguage_Token_Kind_IntegerLiteral,

    /// @brief Token kind of a real literal.
    Nucleus_DataLanguage_Token_Kind_RealLiteral,

    /// @brief Token kind of a void literal.
    Nucleus_DataLanguage_Token_Kind_VoidLiteral,

    /// @brief Token kind of a structure opening delimiter.
    Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter,

    /// @brief Token kind of a structure closing delimiter.
    Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter,

    /// @brief Token kind of a list opening delimiter.
    Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter,

    /// @brief Token kind of a list closing delimiter.
    Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter,

    /// @brief Token kind of a comment.
    Nucleus_DataLanguage_Token_Kind_Comment,

    /// @brief Token kind of the beginning of an input.
    Nucleus_DataLanguage_Token_Kind_Begin,

    /// @brief Token kind of the end of an input.
    Nucleus_DataLanguage_Token_Kind_End,

}; // enum Nucleus_DataLanguage_Token_Kind

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Token_Kind_toString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token_Kind kind
    );
