#include "Nucleus/DataLanguage/Import-Symbol.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_create_uint8
    (
        Nucleus_DataLanguage_Context *context,
        uint8_t value
    )
{ return Nucleus_Interpreter_Symbol_create_uint8(context->context, value); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_create_uint16
    (
        Nucleus_DataLanguage_Context *context,
        uint16_t value
    )
{ return Nucleus_Interpreter_Symbol_create_uint16(context->context, value); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_equalTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    )
{ return Nucleus_Interpreter_Symbol_equalTo(context->context, x, y); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_notEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    )
{ return Nucleus_Interpreter_Symbol_notEqualTo(context->context, x, y); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_lowerThanOrEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    )
{ return Nucleus_Interpreter_Symbol_lowerThanOrEqualTo(context->context, x, y); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_greaterThan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    )
{ return Nucleus_Interpreter_Symbol_greaterThan(context->context, x, y); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_greaterThanOrEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    )
{ return Nucleus_Interpreter_Symbol_greaterThanOrEqualTo(context->context, x, y); }


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_begin
    (
        Nucleus_DataLanguage_Context *context
    )
{ return Nucleus_Interpreter_Symbol_begin(context->context); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_end
    (
        Nucleus_DataLanguage_Context *context
    )
{ return Nucleus_Interpreter_Symbol_end(context->context); }

#define DEFINE(CNAME, UNAME, VALUE) \
    Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol Nucleus_DataLanguage_Symbol_##CNAME(Nucleus_DataLanguage_Context *context) \
    { return Nucleus_Interpreter_Symbol_##CNAME(context->context); }

#include "Nucleus/Interpreter/UnicodeCodePoints.i"

#undef DEFINE
