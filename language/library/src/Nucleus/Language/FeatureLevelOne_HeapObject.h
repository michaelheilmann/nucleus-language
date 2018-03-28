#pragma once

// Forward declaration.
typedef struct Nucleus_Language_FeatureLevelOne_Context Nucleus_Language_FeatureLevelOne_Context;

/// @ingroup language
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Language_FeatureLevelOne_HeapObject) or derived pointer to a @a (Nucleus_Language_FeatureLevelOne_HeapObject) pointer.
#define NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAPOBJECT(pointer) ((Nucleus_Language_FeatureLevelOne_HeapObject *)(pointer))

/// @ingroup language
/// @internal
/// @brief Base type of all heap objects.
typedef struct Nucleus_Language_FeatureLevelOne_HeapObject Nucleus_Language_FeatureLevelOne_HeapObject;

/// @ingroup language
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef void Nucleus_Language_FeatureLevelOne_HeapObject_Finalize(Nucleus_Language_FeatureLevelOne_Context *context, Nucleus_Language_FeatureLevelOne_HeapObject *heapObject);

/// @ingroup language
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef void Nucleus_Language_FeatureLevelOne_HeapObject_Visit(Nucleus_Language_FeatureLevelOne_Context *context, Nucleus_Language_FeatureLevelOne_HeapObject *heapObject);

struct Nucleus_Language_FeatureLevelOne_HeapObject
{
    Nucleus_Language_FeatureLevelOne_HeapObject *next;
    Nucleus_Language_FeatureLevelOne_HeapObject_Finalize *finalize;
    Nucleus_Language_FeatureLevelOne_HeapObject_Visit *visit;
}; // struct Nucleus_Language_FeatureLevelOne_HeapObject
