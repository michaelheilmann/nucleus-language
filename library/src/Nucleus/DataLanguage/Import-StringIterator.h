#pragma once

#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-Boolean.h"
#include "Nucleus/Interpreter/StringIterator.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

// Import.
typedef Nucleus_Interpreter_StringIterator Nucleus_DataLanguage_StringIterator;

// Import.
Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_StringIterator *
Nucleus_DataLanguage_StringIterator_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_setInput
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator,
        Nucleus_DataLanguage_String *string
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_StringIterator_getInput
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringIterator_getOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_StringIterator_get
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_decrement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    );
