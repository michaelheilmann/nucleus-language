#include "Nucleus/DataLanguage/Import-Symbol.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() DL_Symbol DL_Symbol_create_uint8(DL_Context *context, uint8_t value)
{ return Nucleus_Language_Symbol_create_uint8(context->context, value); }

DL_NonNull() DL_Symbol DL_Symbol_create_uint16(DL_Context *context, uint16_t value)
{ return Nucleus_Language_Symbol_create_uint16(context->context, value); }

DL_NonNull() bool DL_Symbol_equal(DL_Context *context, DL_Symbol x, DL_Symbol y)
{ return Nucleus_Language_Symbol_equal(context->context, x, y); }

DL_NonNull() bool DL_Symbol_lowerOrEqual(DL_Context *context, DL_Symbol x, DL_Symbol y)
{ return Nucleus_Language_Symbol_lowerOrEqual(context->context, x, y); }

#define IMPORT(NAME) \
    DL_NonNull() DL_Symbol DL_Symbol_##NAME(DL_Context *context) \
    { return Nucleus_Language_Symbol_##NAME(context->context); }

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
