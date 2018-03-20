/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "DL/stringbuffer.h"

#include "DL/context.h"
#include "nucleus-memory.h"
#include <malloc.h>

DL_NonNull() void
DL_StringBuffer_initialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t initialCapacity
    )
{
    if (!stringBuffer)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    stringBuffer->array = malloc(sizeof(char) * (initialCapacity  > 0 ? initialCapacity : 1));
    if (!stringBuffer->array)
    {
        DL_Context_raiseError(context, DL_Status_AllocationFailed);
    }
    stringBuffer->size = 0;
    stringBuffer->capacity = initialCapacity;
}

DL_NonNull() void
DL_StringBuffer_uninitialize
    (
        DL_StringBuffer *stringBuffer
    )
{
    free(stringBuffer->array);
    stringBuffer->array = NULL;
}

DL_NonNull() void
DL_StringBuffer_ensureFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    )
{
    if (!stringBuffer)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    size_t availableFreeCapacity = stringBuffer->capacity - stringBuffer->size;
    if (availableFreeCapacity < requiredFreeCapacity)
    {
        size_t additionalCapacity = requiredFreeCapacity - availableFreeCapacity;
        size_t oldCapacity = stringBuffer->capacity;
        size_t newCapacity = oldCapacity + additionalCapacity;
        char *newArray = realloc(stringBuffer->array, sizeof(char) * newCapacity);
        if (!newArray)
        {
            DL_Context_raiseError(context, DL_Status_AllocationFailed);
        }
        stringBuffer->array = newArray;
        stringBuffer->capacity = newCapacity;
    }
}

DL_NonNull() void
DL_StringBuffer_append
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{
    if (!stringBuffer)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    DL_StringBuffer_insert(context, stringBuffer, bytes, numberOfBytes, stringBuffer->size);
}

DL_NonNull() void
DL_StringBuffer_prepend
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{
    if (!stringBuffer)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    DL_StringBuffer_insert(context, stringBuffer, bytes, numberOfBytes, 0);
}

DL_NonNull() void
DL_StringBuffer_insert
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes,
        size_t index
    )
{
    if (!stringBuffer || !bytes || index > stringBuffer->size)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    if (numberOfBytes == 0)
    {
        return;
    }
    DL_StringBuffer_ensureFreeCapacity(context, stringBuffer, numberOfBytes);
    Nucleus_copyMemory(stringBuffer->array + index, stringBuffer->array + index + numberOfBytes, numberOfBytes);
    Nucleus_copyMemory(stringBuffer->array + index, bytes, numberOfBytes);
    stringBuffer->size += numberOfBytes;
}

DL_NonNull() const char *
DL_StringBuffer_getBytes
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return stringBuffer->array; }

DL_NonNull() size_t
DL_StringBuffer_getSize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return stringBuffer->size; }

DL_NonNull() size_t
DL_StringBuffer_getCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return stringBuffer->capacity; }

DL_NonNull() size_t
DL_StringBuffer_getFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return stringBuffer->capacity - stringBuffer->size; }
