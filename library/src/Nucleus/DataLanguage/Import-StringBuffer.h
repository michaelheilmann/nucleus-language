// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/StringBuffer.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

// Import.
typedef Nucleus_Interpreter_StringBuffer Nucleus_DataLanguage_StringBuffer;

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        size_t initialCapacity
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_uninitialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_append
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        const char *bytes,
        size_t numberOfBytes
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_clear
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() const char *
Nucleus_DataLanguage_StringBuffer_getBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getSize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringBuffer_ensureFreeCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer,
        size_t requiredFreeCapacity
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringBuffer_getFreeCapacity
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    );
