#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Symbol.h"
#include <stddef.h> /// @todo For size_t. Remove this.

/// @ingroup language
/// @brief Create a @a (Nucleus_Language_StringIterator) object with the specifid input.
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param string a pointer to a @a (Nucleus_Language_String) input object
/// @return a pointer to a @a (Nucleus_Language_StringIterator) object
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_StringIterator *
Nucleus_Language_StringIterator_create
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    );

/// @ingroup language
/// @brief Set the input of a @a (Nucleus_Lanuguage_StringIterator) object
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param stringIterator a pointer to the @a (Nucleus_Lanuguage_StringIterator) object
/// @param string a pointer to the @a (Nucleus_Language_String) input object
Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_setInput
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator,
        Nucleus_Language_String *string
    );

/// @ingroup language
/// @brief Get the input of a @a (Nucleus_Lanuguage_StringIterator) object
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param stringIterator a pointer to the @a (Nucleus_Lanuguage_StringIterator) object
/// @return a pointer to the @a (Nucleus_Language_String) input object
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_StringIterator_getInput
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

/// @ingroup language
/// @brief Get the offset of a @a (Nucleus_Lanuguage_StringIterator) object
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param stringIterator a pointer to the @a (Nucleus_Lanuguage_StringIterator) object
/// @return the offset
Nucleus_Language_NonNull() size_t
Nucleus_Language_StringIterator_getOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

/// @ingroup language
/// @brief Get the symbol of a string iterator.
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param stringIterator a pointer to the @a (Nucleus_Language_StringIterator) object
/// @return a (Nucleus_Language_Symbol) value
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_StringIterator_get
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

/// @ingroup language
/// @brief Increment a string iterator.
/// @param context a pointer to a @a (Nucleus_Language_Context) object
/// @param stringIterator a pointer to the @a (Nucleus_Language_StringIterator) object
Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_increment
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

/// @ingroup language
/// @brief Decrement a string iterator.
/// @param context a pointer to a @a (Nucleus_Language_Context)
/// @param stringIterator a pointer to the @a (Nucleus_Language_StringIterator)
Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_decrement
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );
