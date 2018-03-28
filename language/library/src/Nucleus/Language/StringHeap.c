#include "Nucleus/Language/StringHeap.h"

#include "Nucleus/Language/String-internal.h"
#include "Nucleus/Language/FeatureLevelOne_Context.h"
#include "Nucleus/Language/FeatureLevelOne_ErrorHandler.h"

Nucleus_Language_NonNull() static void
sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    );

Nucleus_Language_NonNull() static void
uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    );

Nucleus_Language_NonNull() static void
sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    )
{
    for (size_t i = 0, n = stringHeap->capacity; i < n; ++i)
    {
        Nucleus_Language_String **bucket = &(stringHeap->buckets[i]);
        while (*bucket)
        {
            Nucleus_Language_String *entry = *bucket; *bucket = NUCLEUS_LANGUAGE_STRING(NUCLEUS_LANGUAGE_OBJECT(entry)->next);
            free(entry);
            --stringHeap->size;
        }
    }
}

Nucleus_Language_NonNull() static void
uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    )
{
    Nucleus_Language_FeatureLevelOne_Heap_sweep(context, NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(stringHeap));
    Nucleus_Language_FeatureLevelOne_Context_deallocate(context, stringHeap->buckets);
    stringHeap->buckets = NULL;
    stringHeap->capacity = 0;
}


Nucleus_Language_NonNull() void
Nucleus_Language_StringHeap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    )
{
    Nucleus_Language_FeatureLevelOne_Heap_initialize(context, NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(stringHeap));
    stringHeap->size = 0;
    stringHeap->capacity = 16;
    Nucleus_Language_FeatureLevelOne_ErrorHandler eh;
    Nucleus_Language_FeatureLevelOne_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        stringHeap->buckets = Nucleus_Language_FeatureLevelOne_Context_allocateArray(context, 16, sizeof(Nucleus_Language_String *));
        Nucleus_Language_FeatureLevelOne_Context_popErrorHandler(context);
    }
    else
    {
        Nucleus_Language_FeatureLevelOne_Context_popErrorHandler(context);
        Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Context_getStatus(context));
    }
    for (size_t i = 0, n = 16; i < n; ++i)
    { stringHeap->buckets[i] = NULL; }
    NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(stringHeap)->sweep = NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_SWEEP(&sweep);
    NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(stringHeap)->uninitialize = NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_UNINITIALIZE(&uninitialize);

}
