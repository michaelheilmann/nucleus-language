#pragma once

/// @ingroup language
/// @brief Status codes of this library.
typedef enum Nucleus_Language_Status Nucleus_Language_Status;

enum Nucleus_Language_Status
{
    /// @brief Status code indicating success.
    /// @invariant This is the only status code with the value @a 0.
    Nucleus_Language_Status_Success = 0,

    /// @brief Status code indicating an invalid argument was passed.
    Nucleus_Language_Status_InvalidArgument,

    /// @brief Status code indicating an allocation failed.
    Nucleus_Language_Status_AllocationFailed,

    /// @brief Status code indicating unreachable code was reached.
    Nucleus_Language_Status_UnreachableCodeReached,

    /// @brief Status code indicating an overflow.
    Nucleus_Language_Status_Overflow,

    /// @brief Status code indicating a lexical error.
    Nucleus_Language_Status_LexicalError,

    /// @brief Status code indicating a syntactical error.
    Nucleus_Language_Status_SyntacticalError,

    /// @brief Status code indicating a semantical error.
    Nucleus_Language_Status_SemanticalError,

    /// @brief Status code indicating an internal error.
    Nucleus_Language_Status_InternalError,

}; // enum Nucleus_Language_Status
