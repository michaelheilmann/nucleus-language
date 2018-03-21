#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Annotations.h"
#include <stdint.h>

struct Nucleus_Language_Symbol
{
    uint32_t value;
}; // struct Nucleus_Language_Symbol

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_create_uint8
    (
        Nucleus_Language_Context *context,
        uint8_t value
    );

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_create_uint16
    (
        Nucleus_Language_Context *context,
        uint16_t value
    );

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_equal
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    );

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_notEqual
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    );

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_lower
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    );

Nucleus_Language_NonNull() bool
Nucleus_Language_Symbol_lowerOrEqual
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Symbol x,
        Nucleus_Language_Symbol y
    );

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_begin
    (
        Nucleus_Language_Context *context
    );

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_end
    (
        Nucleus_Language_Context *context
    );

// '['
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_listOpeningDelimiter
    (
        Nucleus_Language_Context *context
    );

// ']'
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_listClosingDelimiter
    (
        Nucleus_Language_Context *context
    );

// '{'
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_structureOpeningDelimiter
    (
        Nucleus_Language_Context *context
    );

// '}'
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_structureClosingDelimiter
    (
        Nucleus_Language_Context *context
    );

// '\n'
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_lineFeed
    (
        Nucleus_Language_Context *context
    );

// '\r'
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_carriageReturn
    (
        Nucleus_Language_Context *context
    );

// '_'/
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_underscore
    (
        Nucleus_Language_Context *context
    );

// ' '/U+0020
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_space
    (
        Nucleus_Language_Context *context
    );

// '\t'/U+0009
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_characterTabulation
    (
        Nucleus_Language_Context *context
    );

// ':'/U+003A
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_colon
    (
        Nucleus_Language_Context *context
    );

// '.'/U+002E
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_fullStop
    (
        Nucleus_Language_Context *context
    );

// ','/U+002C
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_comma
    (
        Nucleus_Language_Context *context
    );

// '"'/U+0022
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_quotationMark
    (
        Nucleus_Language_Context *context
    );

// '/'/U+002F
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_solidus
    (
        Nucleus_Language_Context *context
    );

// '\'/U+005C
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_reverseSolidus
    (
        Nucleus_Language_Context *context
    );

// '+'/U+002B
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_plusSign
    (
        Nucleus_Language_Context *context
    );

// '-'/U+002D
Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_Symbol_hyphenMinus
    (
        Nucleus_Language_Context *context
    );
