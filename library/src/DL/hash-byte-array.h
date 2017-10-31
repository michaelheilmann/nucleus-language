/// @file DL/hash-byte-array.h
/// @author Michael Heilmann
/// @brief Hash functions for arrays of Bytes.

#pragma once

#include "nucleus-annotations.h"
#include "nucleus-status.h"
#include <stdlib.h> // size_t

/// @ingroup Hash
/// @brief Compute the hash value of an array of Bytes values.
/// @param bytes a pointer to an array of @a numberOfBytes Bytes
/// @param numberOfBytes the number of Bytes in the array pointed to by @a bytes
/// @defaultReturn
/// @success @a (*hv) was assigned the hash value
/// @failure @a hv was not dereferenced
Nucleus_NonNull() Nucleus_Status
Nucleus_hash_byteArray_to_unsignedInt
    (
        const unsigned char *bytes,
        size_t numberOfBytes,
        unsigned int *hv
    );

/// @ingroup Hash
/// @brief Compute the hash value of an array of Bytes values.
/// @param bytes a pointer to an array of @a numberOfBytes Bytes
/// @param numberOfBytes the number of Bytes in the array pointed to by @a bytes
/// @param [out] hv a pointer to an @a (signed long long) variable
/// @defaultReturn
/// @success @a (*hv) was assigned the hash value
/// @failure @a hv was not dereferenced
Nucleus_NonNull(1) Nucleus_Status
Nucleus_hash_byteArray_to_signedLongLongInt
    (
        const unsigned char *bytes,
        size_t numberOfBytes,
        signed long long int *hv
    );
