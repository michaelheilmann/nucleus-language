#include "Nucleus/Language/StringIterator.h"

#include "Nucleus/Language/Context.h"
#include "Nucleus/Language/String.h"
#include "Nucleus/Language/HeapObject.h"

Nucleus_Language_NonNull() static size_t
beginOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

Nucleus_Language_NonNull() static size_t
endOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

Nucleus_Language_NonNull() static void
updateSymbol
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    );

struct Nucleus_Language_StringIterator
{
    Nucleus_Language_Object __parent;
    Nucleus_Language_String *string;
    Nucleus_Language_Symbol symbol;
    size_t offset;
}; // struct Nucleus_Language_StringIterator

Nucleus_Language_NonNull() static size_t
beginOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{ return 0; }

Nucleus_Language_NonNull() static size_t
endOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{ return Nucleus_Language_String_getNumberOfBytes(context, stringIterator->string) + 1; }

Nucleus_Language_NonNull() static void
updateSymbol
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{
    // 0
    if (stringIterator->offset == beginOffset(context, stringIterator))
    { stringIterator->symbol = Nucleus_Language_Symbol_begin(context); }
    // n + 1
    else if (stringIterator->offset == endOffset(context, stringIterator))
    { stringIterator->symbol = Nucleus_Language_Symbol_end(context); }
    // 1, ..., n
    else
    { stringIterator->symbol = Nucleus_Language_Symbol_create_uint8(context, (uint8_t)*(Nucleus_Language_String_getBytes(context, stringIterator->string) +
                                                                                        stringIterator->offset - 1)); }
}

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_StringIterator *
Nucleus_Language_StringIterator_create
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    )
{
    Nucleus_Language_StringIterator *stringIterator = (Nucleus_Language_StringIterator *)Nucleus_Language_Context_allocateObject(context, sizeof(Nucleus_Language_StringIterator));
    stringIterator->string = string;
    stringIterator->offset = 0;
    stringIterator->symbol = Nucleus_Language_Symbol_begin(context);
    return stringIterator;
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_setInput
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator,
        Nucleus_Language_String *string
    )
{
    stringIterator->string = string;
    stringIterator->offset = 0;
    stringIterator->symbol = Nucleus_Language_Symbol_begin(context);
}

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_StringIterator_getInput
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{ return stringIterator->string; }

Nucleus_Language_NonNull() size_t
Nucleus_Language_StringIterator_getOffset
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{ return stringIterator->offset; }

Nucleus_Language_NonNull() Nucleus_Language_Symbol
Nucleus_Language_StringIterator_get
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{ return stringIterator->symbol; }

Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_increment
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{
    if (stringIterator->offset < endOffset(context, stringIterator))
    { stringIterator->offset++; updateSymbol(context, stringIterator); }
}

Nucleus_Language_NonNull() void
Nucleus_Language_StringIterator_decrement
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringIterator *stringIterator
    )
{
    if (stringIterator->offset > beginOffset(context, stringIterator))
    { stringIterator->offset--; updateSymbol(context, stringIterator); }
}
