#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/StringBuffer.h"

// Forward declaration.
typedef struct DL_Context DL_Context;

// Import.
typedef Nucleus_Interpreter_StringBuffer DL_StringBuffer;

DL_NonNull() void
DL_StringBuffer_initialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t initialCapacity
    );

DL_NonNull() void
DL_StringBuffer_uninitialize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

DL_NonNull() void
DL_StringBuffer_append
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

DL_NonNull() void
DL_StringBuffer_clear
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

DL_ReturnNonNull() DL_NonNull() const char *
DL_StringBuffer_getBytes
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

DL_NonNull() size_t
DL_StringBuffer_getSize
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

DL_NonNull() void
DL_StringBuffer_ensureFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    );

DL_NonNull() size_t
DL_StringBuffer_getCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );

DL_NonNull() size_t
DL_StringBuffer_getFreeCapacity
    (
        DL_Context *context,
        DL_StringBuffer *stringBuffer
    );
