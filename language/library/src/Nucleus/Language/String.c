/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
/// @brief Interned strings.
#include "Nucleus/Language/String.h"

#include "Nucleus/Language/Context-internal.h"
#include "Nucleus/Language/String-internal.h"
#include "Nucleus/Memory.h"

Nucleus_Language_NonNull() static unsigned int
Nucleus_Language_hashMemory
    (
        Nucleus_Language_Context *context,
        const void *p,
        size_t n
    );

Nucleus_Language_NonNull() static unsigned int
Nucleus_Language_hashMemory
    (
        Nucleus_Language_Context *context,
        const void *p,
        size_t n
    )
{
    unsigned int hv;
    Nucleus_hashMemory(p, n, &hv);
    return hv;
}

typedef struct LookupResult
{
    Nucleus_Language_String *string;
    size_t hashValue;
    size_t hashIndex;
} LookupResult;

Nucleus_Language_NonNull() static LookupResult
lookup
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_StringHeap *stringHeap,
        const char *bytes,
        size_t numberOfBytes
    )
{
    unsigned int hashValue = Nucleus_Language_hashMemory(context, bytes, numberOfBytes);
    unsigned int hashIndex = hashValue % stringHeap->capacity;
    for (Nucleus_Language_String *string = NUCLEUS_LANGUAGE_STRING(stringHeap->buckets[hashIndex]); NULL != string; string = NUCLEUS_LANGUAGE_STRING(NUCLEUS_LANGUAGE_OBJECT(string)->next))
    {
        if (hashValue == string->hashValue && numberOfBytes == string->numberOfBytes)
        {
            bool result = false;
            Nucleus_compareMemory(bytes, string->bytes, numberOfBytes, &result);
            if (result)
            {
                return (LookupResult) { .string = string, .hashValue = hashValue, .hashIndex = hashIndex };
            }
        }
    }
    return (LookupResult) { .string = NULL, .hashValue = hashValue, .hashIndex = hashIndex };
}

Nucleus_Language_NonNull() static void
create
    (
        Nucleus_Language_Context *context,
        const char *bytes,
        size_t numberOfBytes,
        LookupResult *lookupResult
    );

Nucleus_Language_NonNull() static void
create
    (
        Nucleus_Language_Context *context,
        const char *bytes,
        size_t numberOfBytes,
        LookupResult *lookupResult
    )
{
    Nucleus_Language_String *string = Nucleus_Language_Context_allocate(context, sizeof(Nucleus_Language_String) + numberOfBytes);
    string->numberOfBytes = numberOfBytes;
    string->hashValue = lookupResult->hashValue;
    Nucleus_copyMemory(string->bytes, bytes, numberOfBytes);
    NUCLEUS_LANGUAGE_OBJECT(string)->next = NUCLEUS_LANGUAGE_OBJECT(context->stringHeap.buckets[lookupResult->hashIndex]);
    context->stringHeap.buckets[lookupResult->hashIndex] = string;
    context->stringHeap.size++;
    lookupResult->string = string;
}

Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_String_create
    (
        Nucleus_Language_Context *context,
        const char *bytes,
        size_t numberOfBytes
    )
{
    Nucleus_Language_Context_assertNotNull(context, bytes);
    LookupResult lookupResult = lookup(context, &context->stringHeap, bytes, numberOfBytes);
    if (lookupResult.string) return lookupResult.string;
    create(context, bytes, numberOfBytes, &lookupResult);
    return lookupResult.string;
}

Nucleus_Language_NonNull() Nucleus_Language_Boolean
Nucleus_Language_String_equal
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *first,
        Nucleus_Language_String *second
    )
{
    Nucleus_Language_Context_assertNotNull(context, first);
    Nucleus_Language_Context_assertNotNull(context, second);
    return first == second;
}

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_String_concatenate
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *first,
        Nucleus_Language_String *second
    )
{
    Nucleus_Language_Context_assertNotNull(context, first);
    Nucleus_Language_Context_assertNotNull(context, second);
    size_t numberOfBytes = first->numberOfBytes + second->numberOfBytes;
    char *bytes = Nucleus_Language_Context_acquireScratchSpace(context, numberOfBytes);
    Nucleus_copyMemory(bytes + 0, first->bytes, first->numberOfBytes);
    Nucleus_copyMemory(bytes + first->numberOfBytes, second->bytes, second->numberOfBytes);
    LookupResult lookupResult = lookup(context, &context->stringHeap, bytes, numberOfBytes);
    if (lookupResult.string) return lookupResult.string;
    Nucleus_Language_ErrorHandler eh;
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        create(context, bytes, numberOfBytes, &lookupResult);
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_Context_relinquishScratchSpace(context, bytes);
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Context_getStatus(context));
    }
    Nucleus_Language_Context_relinquishScratchSpace(context, bytes);
    return lookupResult.string;
}

Nucleus_Language_NonNull() size_t
Nucleus_Language_String_getNumberOfBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    )
{ return string->numberOfBytes; }

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() const char *
Nucleus_Language_String_getBytes
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *string
    )
{ return string->bytes; }
