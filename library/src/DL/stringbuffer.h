/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"
#include <stdlib.h>

/// @ingroup dl
/// @brief A string buffer.
struct DL_StringBuffer
{
    /// @brief A pointer to an array of @a capacity Bytes.
    char *array;
    /// @brief The size, in Bytes, of the array pointed to by @a elements.
    size_t capacity;
    /// @brief The number of Bytes in this string buffer. 
    size_t size;
}; // struct DL_StringBuffer

/// @ingroup dl
/// @brief Initialize a DL_StringBuffer object.
/// @param stringBuffer a pointer to a DL_StringBuffer object
/// @success The DL_StringBuffer objec was initialzed with a capacity greater than or equal to @a capacity.
DL_NonNull() void
DL_StringBuffer_initialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t initialCapacity
    );

/// @ingroup dl
/// @brief Uninitialize a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
DL_NonNull() void
DL_StringBuffer_uninitialize
    (
        DL_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Ensure the free capacity of a DL_StringBuffer is greater than or equal a required free capacity.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @param requiredFreeCapacity the required free capacity
/// @post
/// - on success: @a status was not dereferenced. The free capacity of the DL_StringBuffer object pointed to by @a stringBuffer is greater than or equal to @a freeCapacity.
/// - on failure: @a (*status) wsa assigned a non-zero status code.
DL_NonNull() void
DL_StringBuffer_ensureFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    );

/// @ingroup dl
/// @brief Append Bytes to a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @param bytes a pointer to the array of Bytes to append
/// @param numberOfBytes the number of Bytes to append
DL_NonNull() void
DL_StringBuffer_append
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

/// @ingroup dl
/// @brief Prepend Bytes to a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @param bytes a pointer to the array of Bytes to prepend
/// @param numberOfBytes the number of Bytes to prepend
DL_NonNull() void
DL_StringBuffer_prepend
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

/// @ingroup dl
/// @brief Insert Bytes to a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @param bytes a pointer to the array of Bytes to prepend
/// @param numberOfBytes the number of Bytes to prepend
/// @param index the index at which to insert the Bytes
/// @remark
/// A call
/// @code
/// DL_StringBuffer_insert(environment, status, stringBuffer, bytes, numberOfBytes, 0) 
/// @endcode
/// is equivalent to a call
/// @code
/// DL_StringBuffer_prepend(environment, status, stringBuffer, bytes, numberOfBytes) 
/// @endcode
/// @remark
/// A call
/// @code
/// DL_StringBuffer_insert(environment, status, stringBuffer, bytes, numberOfBytes, DL_StringBuffer_getSize(environment, status, stringBuffer)) 
/// @endcode
/// is equivalent to a call
/// @code
/// DL_StringBuffer_append(environment, status, stringBuffer, bytes, numberOfBytes) 
/// @endcode
DL_NonNull() void
DL_StringBuffer_insert
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes,
        size_t index
    );

/// @ingroup dl
DL_NonNull() const char *
DL_StringBuffer_getBytes
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the size of a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @return the size of the DL_StringBuffer object
DL_NonNull() size_t
DL_StringBuffer_getSize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the capacity of a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @return the capacity of the DL_StringBuffer object
DL_NonNull() size_t
DL_StringBuffer_getCapacity
    (
        DL_Context *contet,
        DL_StringBuffer *stringBuffer
    );

/// @ingroup dl
/// @brief Get the free capacity of a DL_StringBuffer object.
/// @param stringBuffer a pointer to the DL_StringBuffer object
/// @return the free capacity of the DL_StringBuffer object
DL_NonNull() size_t
DL_StringBuffer_getFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );
