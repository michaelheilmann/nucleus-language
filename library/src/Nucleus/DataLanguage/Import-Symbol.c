#include "Nucleus/DataLanguage/Import-Symbol.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() DL_Symbol DL_Symbol_create_uint8(DL_Context *context, uint8_t value)
{ return Nucleus_Interpreter_Symbol_create_uint8(context->context, value); }

DL_NonNull() DL_Symbol DL_Symbol_create_uint16(DL_Context *context, uint16_t value)
{ return Nucleus_Interpreter_Symbol_create_uint16(context->context, value); }

DL_NonNull() bool DL_Symbol_equal(DL_Context *context, DL_Symbol x, DL_Symbol y)
{ return Nucleus_Interpreter_Symbol_equalTo(context->context, x, y); }

DL_NonNull() bool DL_Symbol_notEqual(DL_Context *context, DL_Symbol x, DL_Symbol y)
{ return Nucleus_Interpreter_Symbol_notEqualTo(context->context, x, y); }

DL_NonNull() bool DL_Symbol_lowerOrEqual(DL_Context *context, DL_Symbol x, DL_Symbol y)
{ return Nucleus_Interpreter_Symbol_lowerThanOrEqualTo(context->context, x, y); }

DL_NonNull() DL_Symbol DL_Symbol_begin(DL_Context *context)
{ return Nucleus_Interpreter_Symbol_begin(context->context); }

DL_NonNull() DL_Symbol DL_Symbol_end(DL_Context *context)
{ return Nucleus_Interpreter_Symbol_end(context->context); }

#define DEFINE(CNAME, UNAME, VALUE) \
    DL_NonNull() DL_Symbol DL_Symbol_##CNAME(DL_Context *context) \
    { return Nucleus_Interpreter_Symbol_##CNAME(context->context); }

#include "Nucleus/Language/UnicodeCodePoints.i"

#undef DEFINE
