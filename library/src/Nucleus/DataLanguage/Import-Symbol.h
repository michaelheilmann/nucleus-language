#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"

// Forward declaration.
typedef struct DL_Context DL_Context;

// Import.
typedef struct Nucleus_Language_Symbol DL_Symbol;

// Import.
DL_NonNull() DL_Symbol DL_Symbol_create_uint8(DL_Context *context, uint8_t value);

// Import.
DL_NonNull() DL_Symbol DL_Symbol_create_uint16(DL_Context *context, uint16_t value);

// Import.
DL_NonNull() bool DL_Symbol_equal(DL_Context *context, DL_Symbol x, DL_Symbol y);

// Import.
DL_NonNull() bool DL_Symbol_lowerOrEqual(DL_Context *context, DL_Symbol x, DL_Symbol y);

#define IMPORT(NAME) \
    DL_NonNull() DL_Symbol DL_Symbol_##NAME(DL_Context *context);

IMPORT(begin)
IMPORT(end)
IMPORT(listOpeningDelimiter)
IMPORT(listClosingDelimiter)
IMPORT(structureOpeningDelimiter)
IMPORT(structureClosingDelimiter)
IMPORT(lineFeed)
IMPORT(carriageReturn)
IMPORT(underscore)
IMPORT(space)
IMPORT(characterTabulation)
IMPORT(colon)
IMPORT(fullStop)
IMPORT(comma)
IMPORT(quotationMark)
IMPORT(solidus)
IMPORT(reverseSolidus)
IMPORT(plusSign)
IMPORT(hyphenMinus)

#undef IMPORT
