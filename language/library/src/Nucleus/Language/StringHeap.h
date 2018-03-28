#pragma once

#include "Nucleus/Language/FeatureLevelOne_Heap.h"
#include "Nucleus/Language/Annotations.h"
#include <stdlib.h>

// Forward declaration.
typedef struct Nucleus_Language_String Nucleus_Language_String;

/// @ingroup language
/// @internal
/// @brief A string heap.
/// @extends Nucleus_Language_Heap
typedef struct Nucleus_Language_StringHeap Nucleus_Language_StringHeap;

struct Nucleus_Language_StringHeap
{
    Nucleus_Language_FeatureLevelOne_Heap __parent;
    Nucleus_Language_String **buckets;
    size_t size;
    size_t capacity;
}; // struct Nucleus_Language_StringHeap

/// @ingroup language
/// @internal
/// @brief Initialize a @a Nucleus_Language_StringHeap object.
/// @param context a pointer to a @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param stringHeap a pointer to an uninitialized @a (Nucleus_Language_StringHeap) object
/// @post The @a Nucleus_Language_StringHeap object was initialized on success, otherwise not.
Nucleus_Language_NonNull() void
Nucleus_Language_StringHeap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    );

/// @ingroup language
/// @internal
/// @brief Uninitialize a @a Nucleus_Language_StringHeap object.
/// @param context a pointer to a @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param stringHeap a pointer to an initialized @a Nucleus_Language_StringHeap object
/// @post The @a Nucleus_Language_StringHeap object was uninitialized.
Nucleus_Language_NonNull() void
Nucleus_Language_StringHeap_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_StringHeap *stringHeap
    );
