/// @file DL/string.h
/// @author Michael Heilmann
/// @brief Strings
/// @details A string of length @a an is an array of @a n Bytes that is interned.

#pragma once

#include "DL/forward.h"
#include <stdlib.h>
#include <setjmp.h>

struct DL_String
{
    DL_String *next;
    size_t hashValue;
    size_t numberOfBytes;
    char bytes[];
}; // struct DL_String

struct DL_StringTable
{
    DL_String **buckets;
    size_t size;
    size_t capacity;
}; // struct DL_StringTable

/// @internal
/// @brief Initialize a @a DL_StringTable object.
/// @param stringTable a pointer to an uninitialized @a DL_StringTable object
/// @return #DL_Status_Success on success, a non-zero status code on failure
/// @post The @a DL_StringTable object was initialized on success, otherwise not.
DL_NonNull() DL_Status
DL_StringTable_initialize
    (
        DL_StringTable *stringTable
    );

/// @internal
/// @brief Uninitialize a @a DL_StringTable object.
/// @param stringTable a pointer to an initialized @a DL_StringTable object
/// @post The @a DL_StringTable object was uninitialized.
DL_NonNull() void
DL_StringTable_uninitialize
    (
        DL_StringTable *stringTable
    );

/// @internal
/// @brief Get or create an @a DL_String object for a specified array of Bytes.
/// @param context a pointer to the environment
/// @param stringTable a pointer to the @a DL_StringTable object the @a DL_String object is get from or created in
/// @param bytes a pointer to an array of @a numberOfBytes Bytes
/// @param numberOfBytes the number of Bytes in the array pointed to by @a bytes
/// @return a pointer to @a DL_String object
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
DL_NonNull() DL_String *
DL_StringTable_getOrCreateString
    (
        DL_Context *context,
        DL_StringTable *stringTable,
        const char *bytes,
        size_t numberOfBytes
    );

DL_NonNull() DL_Boolean
DL_String_equal
    (
        DL_Context *context,
        DL_String *first,
        DL_String *second
    );

DL_NonNull() DL_String *
DL_String_concatenate
    (
        DL_Context *context,
        DL_String *first,
        DL_String *second
    );

/// @internal
/// @brief Get the number of Bytes of a @a DL_String object.
/// @param string a pointer to an @a DL_String object
/// @return the number of Bytes of the atom
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
DL_NonNull() size_t
DL_String_getNumberOfBytes
    (
        DL_Context *context,
        DL_String *string
    );

/// @internal
/// @brief Get the Bytes of a @a DL_String object.
/// @param string a pointer to an @a DL_String object
/// @return a pointer to the Bytes of the @a DL_String object
/// @failure @a *status is assigned a status code denoting the reason for the failure, then @a longjmp(*environment, -1) is invoked
DL_NonNull() const char *
DL_String_getBytes
    (
        DL_Context *context,
        DL_String *string
    );
