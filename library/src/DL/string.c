/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "DL/string.h"

#include "DL/context.h"
#include "DL/hash-byte-array.h"
#include <memory.h>

DL_NonNull() DL_Status
DL_StringTable_initialize
    (
        DL_StringTable *stringTable
    )
{
    if (!stringTable)
    {
        return DL_Status_InvalidArgument;
    }
    stringTable->size = 0;
    stringTable->capacity = 16;
    stringTable->buckets = malloc(sizeof(DL_String *) * 16);
    if (!stringTable->buckets)
    {
        return DL_Status_AllocationFailed;
    }
    for (size_t i = 0, n = 16; i < n; ++i)
    {
        stringTable->buckets[i] = NULL;
    }
    return DL_Status_Success;
}

DL_NonNull() void
DL_StringTable_uninitialize
    (
        DL_StringTable *stringTable
    )
{
    for (size_t i = 0, n = stringTable->capacity; i < n; ++i)
    {
        DL_String **bucket = &(stringTable->buckets[i]);
        while (*bucket)
        {
            DL_String *entry = *bucket; *bucket = entry->next;
            free(entry);
            --stringTable->size;
        }
    }
    free(stringTable->buckets);
    stringTable->buckets = NULL;
    stringTable->capacity = 0;
}

DL_NonNull() DL_String *
DL_StringTable_getOrCreateString
    (
        DL_Context *context,
        DL_StringTable *stringTable,
        const char *bytes,
        size_t numberOfBytes
    )
{
    if (!stringTable || !bytes)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    unsigned int hashValue;
    Nucleus_Status status = Nucleus_hash_byteArray_to_unsignedInt(bytes, numberOfBytes, &hashValue);
    if (status)
    {
        DL_Context_raiseError(context, status);
    }
    unsigned int hashIndex = hashValue % stringTable->capacity;
    for (DL_String *string = stringTable->buckets[hashIndex]; NULL != string; string = string->next)
    {
        if (hashValue == string->hashValue && numberOfBytes == string->numberOfBytes && !memcmp(bytes, string->bytes, numberOfBytes))
        {
            return string;
        }
    }
    DL_String *string = malloc(sizeof(DL_String) + numberOfBytes);
    if (!string)
    {
        DL_Context_raiseError(context, DL_Status_AllocationFailed);
    }
    string->numberOfBytes = numberOfBytes;
    string->hashValue = hashValue;
    memcpy(string->bytes, bytes, numberOfBytes);
    string->next = stringTable->buckets[hashIndex];
    stringTable->buckets[hashIndex] = string;
    stringTable->size++;
    return string;
}

DL_NonNull() DL_Boolean
DL_String_equal
    (
        DL_Context *context,
        DL_String *first,
        DL_String *second
    )
{
    if (!first || !second)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    return first == second;
}

DL_NonNull() DL_String*
DL_String_concatenate
    (
        DL_Context *context,
        DL_String *first,
        DL_String *second
    )
{
    if (!first || !second)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    size_t numberOfBytes = first->numberOfBytes + second->numberOfBytes;
    char *bytes = DL_Context_acquireScratchSpace(context, numberOfBytes);
    memcpy(bytes + 0, first->bytes, first->numberOfBytes);
    memcpy(bytes + first->numberOfBytes, second->bytes, second->numberOfBytes);
    unsigned int hashValue;
    DL_Status status = Nucleus_hash_byteArray_to_unsignedInt(bytes, numberOfBytes, &hashValue);
    if (status)
    {
        DL_Context_relinquishScratchSpace(context, bytes);
        DL_Context_raiseError(context, status);
    }
    unsigned int hashIndex = hashValue % context->stringTable.capacity;
    for (DL_String *string = context->stringTable.buckets[hashIndex]; NULL != string; string = string->next)
    {
        if (hashValue == string->hashValue && numberOfBytes == string->numberOfBytes && !memcmp(bytes, string->bytes, numberOfBytes))
        {
            DL_Context_relinquishScratchSpace(context, bytes);
            return string;
        }
    }
    DL_String *string = malloc(sizeof(DL_String) + numberOfBytes);
    if (!string)
    {
        DL_Context_relinquishScratchSpace(context, bytes);
        DL_Context_raiseError(context, DL_Status_AllocationFailed);
    }
    string->numberOfBytes = numberOfBytes;
    string->hashValue = hashValue;
    memcpy(string->bytes, bytes, numberOfBytes);
    string->next = context->stringTable.buckets[hashIndex];
    context->stringTable.buckets[hashIndex] = string;
    context->stringTable.size++;
    DL_Context_relinquishScratchSpace(context, bytes);
    return string;
}

DL_NonNull() size_t
DL_String_getNumberOfBytes
    (
        DL_Context *context,
        DL_String *string
    )
{ return string->numberOfBytes; }

DL_NonNull() const char *
DL_String_getBytes
    (
        DL_Context *context,
        DL_String *string
    )
{ return string->bytes; }
