// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/Symbol.h"
#include "Nucleus/Interpreter/PredefinedSymbols.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

// Import.
typedef Nucleus_Interpreter_Symbol Nucleus_DataLanguage_Symbol;

// Import.
Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_create_uint8
    (
        Nucleus_DataLanguage_Context *context,
        uint8_t value
    );

// Import.
Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_create_uint16
    (
        Nucleus_DataLanguage_Context *context,
        uint16_t value
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_equalTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_notEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_lowerThan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_lowerThanOrEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_greaterThan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_Symbol_greaterThanOrEqualTo
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol x,
        Nucleus_DataLanguage_Symbol y
    );


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_begin
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_Symbol_end
    (
        Nucleus_DataLanguage_Context *context
    );

#define DEFINE(CNAME, UNAME, VALUE) \
    Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol Nucleus_DataLanguage_Symbol_##CNAME(Nucleus_DataLanguage_Context *context);

#include "Nucleus/Interpreter/UnicodeCodePoints.i"

#undef DEFINE
