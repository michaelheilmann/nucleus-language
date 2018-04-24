// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/Import-Boolean.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/Context.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_String_create
    (
        Nucleus_DataLanguage_Context *context,
        const char *bytes, size_t numberOfBytes
    )
{ return Nucleus_Interpreter_String_create(NUCLEUS_INTERPRETER_CONTEXT(context->context), bytes, numberOfBytes); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() const char *
Nucleus_DataLanguage_String_getBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    )
{ return Nucleus_Interpreter_String_getBytes(NUCLEUS_INTERPRETER_CONTEXT(context->context), string); }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_String_getNumberOfBytes
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    )
{ return Nucleus_Interpreter_String_getNumberOfBytes(NUCLEUS_INTERPRETER_CONTEXT(context->context), string); }

Nucleus_DataLanguage_NonNull() bool
Nucleus_DataLanguage_String_equal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *first,
        Nucleus_DataLanguage_String *second
    )
{ return Nucleus_Interpreter_String_equalTo(NUCLEUS_INTERPRETER_CONTEXT(context->context), first, second); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_String_concatenate
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *first,
        Nucleus_DataLanguage_String *second
    )
{ return Nucleus_Interpreter_String_concatenate(NUCLEUS_INTERPRETER_CONTEXT(context->context), first, second); }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Boolean
Nucleus_DataLanguage_stringToBoolean
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{ return Nucleus_Interpreter_stringToBoolean(context->context, source); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Integer
Nucleus_DataLanguage_stringToInteger
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{ return Nucleus_Interpreter_stringToInteger(context->context, source); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Real
Nucleus_DataLanguage_stringToReal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{ return Nucleus_Interpreter_stringToReal(context->context, source); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_stringToString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{ return Nucleus_Interpreter_stringToString(context->context, source); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Void
Nucleus_DataLanguage_stringToVoid
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    )
{ return Nucleus_Interpreter_stringToVoid(context->context, source); }
