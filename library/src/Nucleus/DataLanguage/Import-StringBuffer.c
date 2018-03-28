#include "Nucleus/DataLanguage/Import-StringBuffer.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() void
DL_StringBuffer_initialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t initialCapacity
    )
{ Nucleus_Language_StringBuffer_initialize(context->context, stringBuffer, initialCapacity); }

DL_NonNull() void
DL_StringBuffer_uninitialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ Nucleus_Language_StringBuffer_uninitialize(context->context, stringBuffer); }

DL_NonNull() void
DL_StringBuffer_append
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{ return Nucleus_Language_StringBuffer_append(context->context, stringBuffer, bytes, numberOfBytes); }

DL_NonNull() void
DL_StringBuffer_clear
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return Nucleus_Language_StringBuffer_clear(context->context, stringBuffer); }

DL_ReturnNonNull() DL_NonNull() const char *
DL_StringBuffer_getBytes
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return Nucleus_Language_StringBuffer_getBytes(context->context, stringBuffer); }

DL_NonNull() size_t
DL_StringBuffer_getSize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return Nucleus_Language_StringBuffer_getSize(context->context, stringBuffer); }

DL_NonNull() void
DL_StringBuffer_ensureFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    )
{ Nucleus_Language_StringBuffer_ensureFreeCapacity(context->context, stringBuffer, requiredFreeCapacity); }

DL_NonNull() size_t
DL_StringBuffer_getCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return Nucleus_Language_StringBuffer_getCapacity(context->context, stringBuffer); }

DL_NonNull() size_t
DL_StringBuffer_getFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    )
{ return Nucleus_Language_StringBuffer_getFreeCapacity(context->context, stringBuffer); }
