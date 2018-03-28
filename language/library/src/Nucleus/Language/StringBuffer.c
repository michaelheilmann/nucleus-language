/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/Language/StringBuffer.h"

#include "Nucleus/Language/Context.h"
#include "Nucleus/Memory.h"

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_initialize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        size_t initialCapacity
    )
{
    Nucleus_Language_Context_assertNotNull(context, stringBuffer);
    stringBuffer->array = Nucleus_Language_Context_allocateArray(context, initialCapacity, sizeof(char));
    stringBuffer->size = 0;
    stringBuffer->capacity = initialCapacity;
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_uninitialize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{
    free(stringBuffer->array);
    stringBuffer->array = NULL;
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_ensureFreeCapacity
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    )
{
    Nucleus_Language_Context_assertNotNull(context, stringBuffer);
    size_t availableFreeCapacity = stringBuffer->capacity - stringBuffer->size;
    if (availableFreeCapacity < requiredFreeCapacity)
    {
        size_t additionalCapacity = requiredFreeCapacity - availableFreeCapacity;
        size_t oldCapacity = stringBuffer->capacity;
        size_t newCapacity = oldCapacity + additionalCapacity;
        char *oldArray = stringBuffer->array;
        char *newArray = Nucleus_Language_Context_allocateArray(context, newCapacity, sizeof(char));
        Nucleus_copyArrayMemory(newArray, oldArray, oldCapacity, sizeof(char));
        stringBuffer->array = newArray;
        Nucleus_Language_Context_deallocate(context, oldArray);
        stringBuffer->capacity = newCapacity;
    }
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_append
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{
    Nucleus_Language_Context_assertNotNull(context, stringBuffer);
    Nucleus_Language_StringBuffer_insert(context, stringBuffer, bytes, numberOfBytes, stringBuffer->size);
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_prepend
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{
    Nucleus_Language_Context_assertNotNull(context, stringBuffer);
    Nucleus_Language_StringBuffer_insert(context, stringBuffer, bytes, numberOfBytes, 0);
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_insert
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes,
        size_t index
    )
{
    Nucleus_Language_Context_assertNotNull(context, stringBuffer);
    Nucleus_Language_Context_assertNotNull(context, bytes);
    if (index > stringBuffer->size)
    {
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Status_InvalidArgument);
    }
    if (numberOfBytes == 0)
    {
        return;
    }
    Nucleus_Language_StringBuffer_ensureFreeCapacity(context, stringBuffer, numberOfBytes);
    Nucleus_copyMemory(stringBuffer->array + index, stringBuffer->array + index + numberOfBytes, numberOfBytes);
    Nucleus_copyMemory(stringBuffer->array + index, bytes, numberOfBytes);
    stringBuffer->size += numberOfBytes;
}

Nucleus_Language_NonNull() const char *
Nucleus_Language_StringBuffer_getBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{ return stringBuffer->array; }

Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getSize
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{ return stringBuffer->size; }

Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getCapacity
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{ return stringBuffer->capacity; }

Nucleus_Language_NonNull() size_t
Nucleus_Language_StringBuffer_getFreeCapacity
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{ return stringBuffer->capacity - stringBuffer->size; }

Nucleus_Language_NonNull() void
Nucleus_Language_StringBuffer_clear
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{ stringBuffer->size = 0; }
