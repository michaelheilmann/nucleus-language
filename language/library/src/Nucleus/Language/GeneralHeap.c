#include "Nucleus/Language/GeneralHeap.h"

#include "Nucleus/Language/HeapObject.h"
#include "Nucleus/Language/FeatureLevelOne_Context.h"
#include <stddef.h> /// @todo For size_t. Remove this.

Nucleus_Language_NonNull() static void
sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    );

Nucleus_Language_NonNull() static void
uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    );

Nucleus_Language_NonNull() static void
sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    )
{
    while (generalHeap->objects)
    {
        Nucleus_Language_Object *object = generalHeap->objects; generalHeap->objects = object->next;
        if (object->finalize)
        {
            object->finalize(context, object);
        }
        Nucleus_Language_FeatureLevelOne_Context_deallocate(context, object);
    }
}

Nucleus_Language_NonNull() static void
uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    )
{
    Nucleus_Language_FeatureLevelOne_Heap_sweep(context, NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(generalHeap));
}

Nucleus_Language_NonNull() void
Nucleus_Language_GeneralHeap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    )
{
    Nucleus_Language_FeatureLevelOne_Heap_initialize(context, NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(generalHeap));
    generalHeap->objects = NULL;
    NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(generalHeap)->sweep = NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_SWEEP(&sweep);
    NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(generalHeap)->uninitialize = NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_UNINITIALIZE(&uninitialize);
}
