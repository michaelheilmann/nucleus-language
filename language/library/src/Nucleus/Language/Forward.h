#pragma once

#include <stdbool.h>

/// @ingroup language
/// @brief A context.
typedef struct Nucleus_Language_Context Nucleus_Language_Context;

/// @ingroup language
/// @brief C representation of the <c>Boolean</c> type.
typedef bool Nucleus_Language_Boolean;

/// @ingroup language
/// @brief C representation of the <c>true</c> value.
#define Nucleus_Language_True (true)

/// @ingroup language
/// @brief C representation of the <c>false</c> value.
#define Nucleus_Language_False (false)

/// @ingroup language
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Language_String) or derived pointer to a @a (Nucleus_Language_String) pointer.
#define NUCLEUS_LANGUAGE_STRING(pointer) ((Nucleus_Language_String *)(pointer))
/// @ingroup language
/// @brief Type of a string.
/// @extends Nucleus_Language_Object
typedef struct Nucleus_Language_String Nucleus_Language_String;

/// @ingroup language
/// @brief A string iterator.
typedef struct Nucleus_Language_StringIterator Nucleus_Language_StringIterator;

/// @ingroup language
/// @brief A string buffer.
typedef struct Nucleus_Language_StringBuffer Nucleus_Language_StringBuffer;

/// @ingroup language
/// @brief A symbol.
typedef struct Nucleus_Language_Symbol Nucleus_Language_Symbol;
