#include "Nucleus/DataLanguage/Import-StringIterator.h"

#include "Nucleus/DataLanguage/Context.h"

DL_ReturnNonNull() DL_NonNull() DL_StringIterator *
DL_StringIterator_create
    (
        DL_Context *context,
        DL_String *string
    )
{ return Nucleus_Language_StringIterator_create(context->context, string); }

DL_NonNull() void
DL_StringIterator_setInput
    (
        DL_Context *context,
        DL_StringIterator *stringIterator,
        DL_String *string
    )
{ Nucleus_Language_StringIterator_setInput(context->context, stringIterator, string); }

DL_ReturnNonNull() DL_NonNull() DL_String *
DL_StringIterator_getInput
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    )
{ return Nucleus_Language_StringIterator_getInput(context->context, stringIterator); }

DL_NonNull() size_t
DL_StringIterator_getOffset
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    )
{ return Nucleus_Language_StringIterator_getOffset(context->context, stringIterator); }

DL_NonNull() DL_Symbol
DL_StringIterator_get
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    )
{ return Nucleus_Language_StringIterator_get(context->context, stringIterator); }

DL_NonNull() void
DL_StringIterator_increment
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    )
{ Nucleus_Language_StringIterator_increment(context->context, stringIterator); }

DL_NonNull() void
DL_StringIterator_decrement
    (
        DL_Context *context,
        DL_StringIterator *stringIterator
    )
{ Nucleus_Language_StringIterator_decrement(context->context, stringIterator); }
