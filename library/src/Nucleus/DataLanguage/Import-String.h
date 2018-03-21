#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"

// Forward declration.
typedef struct DL_Context DL_Context;

// Import.
typedef Nucleus_Language_String DL_String;

// Import.
DL_ReturnNonNull() DL_NonNull() DL_String *
DL_String_create(DL_Context *context, const char *bytes, size_t numberOfBytes);

// Import.
DL_ReturnNonNull() DL_NonNull() const char *
DL_String_getBytes(DL_Context *context, DL_String *string);

// Import.
DL_NonNull() size_t
DL_String_getNumberOfBytes(DL_Context *context, DL_String *string);

// Import.
DL_NonNull() bool
DL_String_equal(DL_Context *context, DL_String *first, DL_String *second);

// Import.
DL_ReturnNonNull() DL_NonNull() DL_String *
DL_String_concatenate(DL_Context *context, DL_String *first, DL_String *second);
