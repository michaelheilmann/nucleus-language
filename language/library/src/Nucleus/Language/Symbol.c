#include "Nucleus/Language/Symbol.h"

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_create_uint8
    (
        Nucleus_Language_Context *context,
        uint8_t value
    )
{
    Nucleus_Language_Symbol symbol = { .value = value };
    return symbol;
}

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_create_uint16
    (
        Nucleus_Language_Context *context,
        uint16_t value
    )
{
    Nucleus_Language_Symbol symbol = { .value = value };
    return symbol;
}

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_equal
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    )
{ return x.value == y.value; }

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_notEqual
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    )
{ return x.value != y.value; }

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_lower
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    )
{ return x.value < y.value; }

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_lowerOrEqual
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    )
{ return x.value <= y.value; }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_begin
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint16(context, 255+1); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_end
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint16(context, 255+2); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_listOpeningDelimiter
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'['); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_listClosingDelimiter
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)']'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_structureOpeningDelimiter
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'{'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_structureClosingDelimiter
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'}'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_lineFeed
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'\n'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_carriageReturn
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'\r'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_underscore
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'_'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_space
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)' '); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_characterTabulation
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'\t'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_colon
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)':'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_fullStop
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'.'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_comma
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)','); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_quotationMark
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'"'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_solidus
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'/'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_reverseSolidus
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'\\'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_plusSign
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'+'); }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_hyphenMinus
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_Symbol_create_uint8(context, (uint8_t)'-'); }

#if 0
Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_isAlphabetic
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x
    )
{
    return (Nucleus_Language_Symbol_lowerOrEqual(context, Nucleus_Language_Symbol_make(context, 'a'), x) && Nucleus_Language_Symbol_lowerOrEqual(context, x, Nucleus_Language_Symbol_make(context, 'z')))
        || (Nucleus_Language_Symbol_lowerOrEqual(context, Nucleus_Language_Symbol_make(context, 'A'), x) && Nucleus_Language_Symbol_lowerOrEqual(context, x, Nucleus_Language_Symbol_make(context, 'Z')));
}

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_isNumeric
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x
    )
{
    return (Nucleus_Language_Symbol_lowerOrEqual(context, Nucleus_Language_Symbol_make(context, '0'), x) && Nucleus_Language_Symbol_lowerOrEqual(context, x, Nucleus_Language_Symbol_make(context, '9')));
}

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_isUnderscore
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x
    )
{
    return Nucleus_Language_Symbol_equal(context, x, Nucleus_Language_Symbol_make(context, '_'));
}
#endif