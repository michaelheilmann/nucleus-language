#pragma once

#include "Nucleus/Language/FeatureLevelOne_Annotations.h"

// Forward declaration.
typedef struct Nucleus_Language_FeatureLevelOne_Context Nucleus_Language_FeatureLevelOne_Context;

#define NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP(pointer) ((Nucleus_Language_FeatureLevelOne_Heap *)(pointer))
typedef struct Nucleus_Language_FeatureLevelOne_Heap Nucleus_Language_FeatureLevelOne_Heap;

#define NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_SWEEP(pointer) ((Nucleus_Language_FeatureLevelOne_Heap_Sweep *)(pointer))
typedef void (Nucleus_Language_FeatureLevelOne_Heap_Sweep)(Nucleus_Language_FeatureLevelOne_Context *, Nucleus_Language_FeatureLevelOne_Heap *);

#define NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAP_UNINITIALIZE(pointer) ((Nucleus_Language_FeatureLevelOne_Heap_Uninitialize *)(pointer))
typedef void (Nucleus_Language_FeatureLevelOne_Heap_Uninitialize)(Nucleus_Language_FeatureLevelOne_Context *, Nucleus_Language_FeatureLevelOne_Heap *);


struct Nucleus_Language_FeatureLevelOne_Heap
{
    Nucleus_Language_FeatureLevelOne_Heap_Sweep *sweep;
    Nucleus_Language_FeatureLevelOne_Heap_Uninitialize *uninitialize;
};

/// @ingroup language
/// @internal
/// @brief Initialize a @a (Nucleus_Language_FeatureLevelOne_Heap) object.
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    );

/// @ingroup language
/// @internal
/// @brief Uninitialize a @a (Nucleus_Language_FeatureLevelOne_Heap) object.
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    );

/// @ingroup language
/// @internal
/// @brief Sweep a @a (Nucleus_Language_FeatureLevelOne_Heap) object i.e. finalize and deallocate dead objects on the heap.
/// @param context a pointer to a @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param heap a pointer to the initialized @a (Nucleus_Language_FeatureLevelOne_Heap) object
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Heap_sweep
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Heap *heap
    );
