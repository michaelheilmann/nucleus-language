/// @file DL/hash-byte-array.c
/// @author Michael Heilmann
/// @brief Hash functions for arrays of Bytes.

#include "DL/hash-byte-array.h"
#include <limits.h>

Nucleus_NonNull() Nucleus_Status
Nucleus_hash_byteArray_to_unsignedInt
    (
        const unsigned char *bytes,
        size_t numberOfBytes,
        unsigned int *hv
    )
{
    if (!bytes || !hv) return Nucleus_Status_InvalidArgument;
    unsigned int hashValue = (unsigned int)numberOfBytes;
    for (size_t i = 0, n = numberOfBytes; i < n; ++i)
    {
        hashValue ^= bytes[i]; // well-defined (neither undefined nor implementation defined)
    }
    *hv = hashValue;
    return Nucleus_Status_Success;
}

Nucleus_NonNull() Nucleus_Status
Nucleus_hash_byteArray_to_signedLongLong
    (
        const unsigned char *bytes,
        size_t numberOfBytes,
        signed long long int *hv
    )
{
    if (!bytes || !hv) return Nucleus_Status_InvalidArgument;
    unsigned long long hashValue = (unsigned long long)numberOfBytes;
    for (size_t i = 0, n = numberOfBytes; i < n; ++i)
    {
        hashValue ^= bytes[i]; // well-defined (neither undefined nor implementation defined)
    }
    *hv = (signed long long)(hashValue % LLONG_MAX);
    return Nucleus_Status_Success;
}
