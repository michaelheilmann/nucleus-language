/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Annotations.h"
#include <stdlib.h>

/// @ingroup dl
/// @brief A string buffer.
struct Nucleus_Language_StringBuffer
{
    /// @brief A pointer to an array of @a capacity Bytes.
    char *array;
    /// @brief The size, in Bytes, of the array pointed to by @a elements.
    size_t capacity;
    /// @brief The number of Bytes in this string buffer. 
    size_t size;
}; // struct Nucleus_Language_StringBuffer

/// @ingroup dl
/// @brief Initialize a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to a Nucleus_Language_StringBuffer object
/// @success The Nucleus_Language_StringBuffer objec was initialzed with a capacity greater than or equal to @a capacity.
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_initialize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        size_t initialCapacity
    );

/// @ingroup dl
/// @brief Uninitialize a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_uninitialize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Ensure the free capacity of a Nucleus_Language_StringBuffer is greater than or equal a required free capacity.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @param requiredFreeCapacity the required free capacity
/// @post
/// - on success: @a status was not dereferenced. The free capacity of the Nucleus_Language_StringBuffer object pointed to by @a stringBuffer is greater than or equal to @a freeCapacity.
/// - on failure: @a (*status) wsa assigned a non-zero status code.
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_ensureFreeCapacity
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    );

/// @ingroup dl
/// @brief Append Bytes to a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @param bytes a pointer to the array of Bytes to append
/// @param numberOfBytes the number of Bytes to append
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_append
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

/// @ingroup dl
/// @brief Prepend Bytes to a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @param bytes a pointer to the array of Bytes to prepend
/// @param numberOfBytes the number of Bytes to prepend
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_prepend
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

/// @ingroup dl
/// @brief Insert Bytes to a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @param bytes a pointer to the array of Bytes to prepend
/// @param numberOfBytes the number of Bytes to prepend
/// @param index the index at which to insert the Bytes
/// @remark
/// A call
/// @code
/// Nucleus_Language_StringBuffer_insert(environment, status, stringBuffer, bytes, numberOfBytes, 0) 
/// @endcode
/// is equivalent to a call
/// @code
/// Nucleus_Language_StringBuffer_prepend(environment, status, stringBuffer, bytes, numberOfBytes) 
/// @endcode
/// @remark
/// A call
/// @code
/// Nucleus_Language_StringBuffer_insert(environment, status, stringBuffer, bytes, numberOfBytes, Nucleus_Language_StringBuffer_getSize(environment, status, stringBuffer)) 
/// @endcode
/// is equivalent to a call
/// @code
/// Nucleus_Language_StringBuffer_append(environment, status, stringBuffer, bytes, numberOfBytes) 
/// @endcode
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_insert
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes,
        size_t index
    );

/// @ingroup dl
Nucleus_Language_NonNull() const char *
Nucleus_Language_StringBuffer_getBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the size of a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @return the size of the Nucleus_Language_StringBuffer object
Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getSize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the capacity of a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @return the capacity of the Nucleus_Language_StringBuffer object
Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getCapacity
    (
        Nucleus_Language_Context *contet,
        Nucleus_Language_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the free capacity of a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
/// @return the free capacity of the Nucleus_Language_StringBuffer object
Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getFreeCapacity
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Clear a Nucleus_Language_StringBuffer object.
/// @param stringBuffer a pointer to the Nucleus_Language_StringBuffer object
Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_clear
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    );
