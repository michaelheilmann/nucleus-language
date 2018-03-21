#pragma once

#include "Nucleus/Language/FeatureLevelOne_Heap.h"
#include "Nucleus/Language/HeapObject.h"
#include "Nucleus/Language/Annotations.h"

/// @ingroup language
/// @internal
/// @brief A general heap.
/// @extends Nucleus_Language_Heap
typedef struct Nucleus_Language_GeneralHeap Nucleus_Language_GeneralHeap;

struct Nucleus_Language_GeneralHeap
{
    Nucleus_Language_FeatureLevelOne_Heap __parent;
    /// @brief A null pointer or a pointer to the first element of the singly-linked list of @a Nucleus_Language_Object) objects.
    Nucleus_Language_Object *objects;
}; // struct Nucleus_Language_GeneralHeap

/// @ingroup language
/// @internal
/// @brief Initialize a @a (Nucleus_Language_GeneralHeap) object.
/// @param context a pointer to a @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param generalHeap a pointer to an uninitialized @a (Nucleus_Language_GeneralHeap) object
/// @post The @a (Nucleus_Language_GeneralHeap) object was initialized on success, otherwise not.
Nucleus_Language_NonNull() void
Nucleus_Language_GeneralHeap_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    );

/// @ingroup language
/// @internal
/// @brief Uninitialize a @a (Nucleus_Language_GeneralHeap) object.
/// @param context a pointer to a @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param generalHeap a pointer to an initialized @a (Nucleus_Language_GeneralHeap) object
/// @post The @a (Nucleus_Language_GeneralHeap) object was uninitialized.
Nucleus_Language_NonNull() void
Nucleus_Language_GeneralHeap_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_GeneralHeap *generalHeap
    );
