#pragma once

#include "Nucleus/Language/FeatureLevelOne_HeapObject.h"

/// @ingroup language
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Language_Object) or derived pointer to a @a (Nucleus_Language_Object) pointer.
#define NUCLEUS_LANGUAGE_OBJECT(pointer) NUCLEUS_LANGUAGE_FEATURELEVELONE_HEAPOBJECT(pointer)

/// @ingroup language
/// @internal
/// @brief Base type of all managed heap objects.
/// @todo Rename to Nucleus_Language_ManagedHeapObject.
typedef struct Nucleus_Language_FeatureLevelOne_HeapObject Nucleus_Language_Object;

/// @ingroup language
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef Nucleus_Language_FeatureLevelOne_HeapObject_Finalize Nucleus_Language_Finalize;

/// @ingroup language
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef Nucleus_Language_FeatureLevelOne_HeapObject_Visit Nucleus_Language_Visit;
