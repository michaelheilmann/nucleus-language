#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/Symbol.h"
#include "Nucleus/Language/PredefinedSymbols.h"

// Forward declaration.
typedef struct DL_Context DL_Context;

// Import.
typedef Nucleus_Interpreter_Symbol DL_Symbol;

// Import.
DL_NonNull() DL_Symbol DL_Symbol_create_uint8(DL_Context *context, uint8_t value);

// Import.
DL_NonNull() DL_Symbol DL_Symbol_create_uint16(DL_Context *context, uint16_t value);

// Import.
DL_NonNull() bool DL_Symbol_equal(DL_Context *context, DL_Symbol x, DL_Symbol y);

// Import.
DL_NonNull() bool DL_Symbol_notEqual(DL_Context *context, DL_Symbol x, DL_Symbol y);

// Import.
DL_NonNull() bool DL_Symbol_lowerOrEqual(DL_Context *context, DL_Symbol x, DL_Symbol y);


DL_NonNull() DL_Symbol DL_Symbol_begin(DL_Context *context);
DL_NonNull() DL_Symbol DL_Symbol_end(DL_Context *context);

#define DEFINE(CNAME, UNAME, VALUE) \
    DL_NonNull() DL_Symbol DL_Symbol_##CNAME(DL_Context *context);

#include "Nucleus/Language/UnicodeCodePoints.i"

#undef DEFINE
