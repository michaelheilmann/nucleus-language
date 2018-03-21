/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
/// @brief Interned strings.
#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Annotations.h"
#include <stddef.h> /// @todo For size_t. Remove this.

/// @internal
/// @brief Get or create an @a Nucleus_Language_String object for a specified array of Bytes.
/// @param context a pointer to the environment
/// @param stringTable a pointer to the @a Nucleus_Language_StringTable object the @a Nucleus_Language_String object is get from or created in
/// @param bytes a pointer to an array of @a numberOfBytes Bytes
/// @param numberOfBytes the number of Bytes in the array pointed to by @a bytes
/// @return a pointer to @a Nucleus_Language_String object
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_String_create
    (
        Nucleus_Language_Context *context,
        const char *bytes,
        size_t numberOfBytes
    );

Nucleus_Language_NonNull() Nucleus_Language_Boolean
Nucleus_Language_String_equal
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *first,
        Nucleus_Language_String *second
    );

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_String_concatenate
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *first,
        Nucleus_Language_String *second
    );

/// @internal
/// @brief Get the number of Bytes of a @a Nucleus_Language_String object.
/// @param string a pointer to an @a Nucleus_Language_String object
/// @return the number of Bytes of the atom
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
Nucleus_Language_NonNull() size_t
Nucleus_Language_String_getNumberOfBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    );

/// @internal
/// @brief Get the Bytes of a @a Nucleus_Language_String object.
/// @param string a pointer to an @a Nucleus_Language_String object
/// @return a pointer to the Bytes of the @a Nucleus_Language_String object
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() const char *
Nucleus_Language_String_getBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    );
