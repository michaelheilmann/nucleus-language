#include "Nucleus/Language/FeatureLevelOne_Heap.h"

#include "Nucleus/Language/FeatureLevelOne_Context.h"
#include "Nucleus/Language/FeatureLevelOne_Status.h"
#include <stdlib.h>

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    )
{
    if (!heap) Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_InvalidArgument);
    heap->sweep = NULL;
    heap->uninitialize = NULL;
}

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    )
{
    heap->uninitialize(context, heap);
}

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    )
{
    heap->sweep(context, heap);
}
