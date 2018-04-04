#include "Nucleus/DataLanguage/Import-StringIterator.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_StringIterator *
Nucleus_DataLanguage_StringIterator_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *string
    )
{ return Nucleus_Interpreter_StringIterator_create(context->context, string); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_setInput
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator,
        Nucleus_DataLanguage_String *string
    )
{ Nucleus_Interpreter_StringIterator_setInput(context->context, stringIterator, string); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_StringIterator_getInput
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    )
{ return Nucleus_Interpreter_StringIterator_getInput(context->context, stringIterator); }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_StringIterator_getOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    )
{ return Nucleus_Interpreter_StringIterator_getOffset(context->context, stringIterator); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_StringIterator_get
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    )
{ return Nucleus_Interpreter_StringIterator_get(context->context, stringIterator); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    )
{ Nucleus_Interpreter_StringIterator_increment(context->context, stringIterator); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_StringIterator_decrement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_StringIterator *stringIterator
    )
{ Nucleus_Interpreter_StringIterator_decrement(context->context, stringIterator); }
