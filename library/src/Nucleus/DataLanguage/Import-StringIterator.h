#pragma once

#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-String.h"
#include "Nucleus/Interpreter/StringIterator.h"

// Forward declaration.
typedef struct DL_Context DL_Context;

// Import.
typedef Nucleus_Interpreter_StringIterator DL_StringIterator;

// Import.
DL_ReturnNonNull() DL_NonNull() DL_StringIterator *
DL_StringIterator_create
    (
        DL_Context *context,
        DL_String *string
    );

DL_NonNull() void
DL_StringIterator_setInput
    (
        DL_Context *context,
        DL_StringIterator *stringIterator,
        DL_String *string
    );

DL_ReturnNonNull() DL_NonNull() DL_String *
DL_StringIterator_getInput
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    );

DL_NonNull() size_t
DL_StringIterator_getOffset
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    );

DL_NonNull() DL_Symbol
DL_StringIterator_get
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    );

DL_NonNull() void
DL_StringIterator_increment
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    );

DL_NonNull() void
DL_StringIterator_decrement
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    );
