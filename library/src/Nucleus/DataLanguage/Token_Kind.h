#pragma once

#include "Nucleus/DataLanguage/Forward.h"

/// @ingroup dl
/// @brief An enumeration of DL token kinds.
typedef enum DL_Token_Kind DL_Token_Kind;

enum DL_Token_Kind
{

    /// @brief Token kind of a colon.
    DL_Token_Kind_Colon,

    /// @brief Token kind of a comma.
    DL_Token_Kind_Comma,

    /// @brief Token kind of a true literal.
    DL_Token_Kind_TrueLiteral,

    /// @brief Token kind of a false literal.
    DL_Token_Kind_FalseLiteral,

    /// @brief Token kind of a null literal.
    DL_Token_Kind_NullLiteral,

    /// @brief Token kind of a string literal.
    DL_Token_Kind_StringLiteral,

    /// @brief Token kind of an integer literal.
    DL_Token_Kind_IntegerLiteral,

    /// @brief Token kind of a real literal.
    DL_Token_Kind_RealLiteral,

    /// @brief Token kind of a structure opening delimiter.
    DL_Token_Kind_StructureOpeningDelimiter,

    /// @brief Token kind of a structure closing delimiter.
    DL_Token_Kind_StructureClosingDelimiter,

    /// @brief Token kind of a list opening delimiter.
    DL_Token_Kind_ListOpeningDelimiter,

    /// @brief Token kind of a list closing delimiter.
    DL_Token_Kind_ListClosingDelimiter,

    /// @brief Token kind of a comment.
    DL_Token_Kind_Comment,

    /// @brief Token kind of the beginning of an input.
    DL_Token_Kind_Begin,

    /// @brief Token kind of the end of an input.
    DL_Token_Kind_End,

}; // enum DL_Token_Kind

DL_NonNull() DL_String *
DL_Token_Kind_toString
    (
        DL_Context *context,
        DL_Token_Kind kind
    );
