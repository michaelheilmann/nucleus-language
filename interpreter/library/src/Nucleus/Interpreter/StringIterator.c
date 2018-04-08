// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/StringIterator.h"

#include "Nucleus/Interpreter/Context.h"
#include "Nucleus/Interpreter/GC/Object.h"
#include "Nucleus/Interpreter/String.h"
#include "Nucleus/Interpreter/Symbol.h"

Nucleus_Interpreter_NonNull() static size_t
beginOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    );

Nucleus_Interpreter_NonNull() static size_t
endOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    );

Nucleus_Interpreter_NonNull() static void
updateSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    );

struct Nucleus_Interpreter_StringIterator
{
    Nucleus_Interpreter_GC_Object __parent;
    Nucleus_Interpreter_String *string;
    Nucleus_Interpreter_Symbol symbol;
    size_t offset;
}; // struct Nucleus_Interpreter_StringIterator

Nucleus_Interpreter_NonNull() static size_t
beginOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{ return 0; }

Nucleus_Interpreter_NonNull() static size_t
endOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{ return Nucleus_Interpreter_String_getNumberOfBytes(context, stringIterator->string) + 1; }

Nucleus_Interpreter_NonNull() static void
updateSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{
    // 0
    if (stringIterator->offset == beginOffset(context, stringIterator))
    { stringIterator->symbol = Nucleus_Interpreter_Symbol_begin(context); }
    // n + 1
    else if (stringIterator->offset == endOffset(context, stringIterator))
    { stringIterator->symbol = Nucleus_Interpreter_Symbol_end(context); }
    // 1, ..., n
    else
    {
        const char *byte = Nucleus_Interpreter_String_getBytes(NUCLEUS_INTERPRETER_CONTEXT(context),
                                                               stringIterator->string)
                         + stringIterator->offset - 1;
        stringIterator->symbol = Nucleus_Interpreter_Symbol_create_uint8(context, (uint8_t)*(byte)); }
}

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_StringIterator *
Nucleus_Interpreter_StringIterator_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *string
    )
{
    Nucleus_Interpreter_StringIterator *stringIterator = (Nucleus_Interpreter_StringIterator *)Nucleus_Interpreter_Context_allocateObject(context, sizeof(Nucleus_Interpreter_StringIterator));
    stringIterator->string = string;
    stringIterator->offset = 0;
    stringIterator->symbol = Nucleus_Interpreter_Symbol_begin(context);
    return stringIterator;
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_StringIterator_setInput
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator,
        Nucleus_Interpreter_String *string
    )
{
    stringIterator->string = string;
    stringIterator->offset = 0;
    stringIterator->symbol = Nucleus_Interpreter_Symbol_begin(context);
}

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_Interpreter_StringIterator_getInput
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{ return stringIterator->string; }

Nucleus_Interpreter_NonNull() size_t
Nucleus_Interpreter_StringIterator_getOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{ return stringIterator->offset; }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol
Nucleus_Interpreter_StringIterator_get
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{ return stringIterator->symbol; }

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_StringIterator_increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{
    if (stringIterator->offset < endOffset(context, stringIterator))
    { stringIterator->offset++; updateSymbol(context, stringIterator); }
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_StringIterator_decrement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringIterator *stringIterator
    )
{
    if (stringIterator->offset > beginOffset(context, stringIterator))
    { stringIterator->offset--; updateSymbol(context, stringIterator); }
}
