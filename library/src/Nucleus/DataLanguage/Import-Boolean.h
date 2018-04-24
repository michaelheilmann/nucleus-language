// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/Boolean.h"
#include "Nucleus/Interpreter/Integer.h"
#include "Nucleus/Interpreter/Real.h"
#include "Nucleus/Interpreter/String.h"
#include "Nucleus/Interpreter/Conversions.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef Nucleus_Interpreter_Boolean Nucleus_DataLanguage_Boolean;

typedef Nucleus_Interpreter_Integer Nucleus_DataLanguage_Integer;

typedef Nucleus_Interpreter_Real Nucleus_DataLanguage_Real;

typedef Nucleus_Interpreter_String Nucleus_DataLanguage_String;

typedef Nucleus_Interpreter_Void Nucleus_DataLanguage_Void;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Import.
Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_String_create
    (
        Nucleus_DataLanguage_Context *context,
        const char *bytes,
        size_t numberOfBytes
    );

// Import.
Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() const char *
Nucleus_DataLanguage_String_getBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    );

// Import.
Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_String_getNumberOfBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    );

// Import.
Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_String_equal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *first,
        Nucleus_DataLanguage_String *second
    );

// Import.
Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_String_concatenate
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *first,
        Nucleus_DataLanguage_String *second
    );

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define Nucleus_DataLanguage_Integer_GreatestConstant() Nucleus_Interpreter_Integer_GreatestConstant()

#define Nucleus_DataLanguage_Integer_LeastConstant() Nucleus_Interpreter_Integer_LeastConstant()

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define Nucleus_DataLanguage_Boolean_TrueConstant() Nucleus_Interpreter_Boolean_TrueConstant()

#define Nucleus_DataLanguage_Boolean_FalseConstant() Nucleus_Interpreter_Boolean_FalseConstant()

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Boolean
Nucleus_DataLanguage_stringToBoolean
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Integer
Nucleus_DataLanguage_stringToInteger
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Real
Nucleus_DataLanguage_stringToReal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_stringToString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Void
Nucleus_DataLanguage_stringToVoid
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define Nucleus_DataLanguage_Void_VoidConstant() Nucleus_Interpreter_Void_VoidConstant()
