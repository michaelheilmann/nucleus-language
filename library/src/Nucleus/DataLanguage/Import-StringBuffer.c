// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/Import-StringBuffer.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        size_t initialCapacity
    )
{ Nucleus_Interpreter_StringBuffer_initialize(context->context, stringBuffer, initialCapacity); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_uninitialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ Nucleus_Interpreter_StringBuffer_uninitialize(context->context, stringBuffer); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_append
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    )
{ Nucleus_Interpreter_StringBuffer_append(context->context, stringBuffer, bytes, numberOfBytes); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_clear
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ Nucleus_Interpreter_StringBuffer_clear(context->context, stringBuffer); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() const char *
Nucleus_DataLanguage_StringBuffer_getBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ return Nucleus_Interpreter_StringBuffer_getBytes(context->context, stringBuffer); }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getSize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ return Nucleus_Interpreter_StringBuffer_getSize(context->context, stringBuffer); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_ensureFreeCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    )
{ Nucleus_Interpreter_StringBuffer_ensureFreeCapacity(context->context, stringBuffer, requiredFreeCapacity); }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ return Nucleus_Interpreter_StringBuffer_getCapacity(context->context, stringBuffer); }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getFreeCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ return Nucleus_Interpreter_StringBuffer_getFreeCapacity(context->context, stringBuffer); }
