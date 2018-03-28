#pragma once

#include "Nucleus/Language/Context.h"
#include "Nucleus/Language/String-internal.h"

#include "Nucleus/Language/FeatureLevelOne_Context.h"
#include "Nucleus/Language/GeneralHeap.h"
#include "Nucleus/Language/StringHeap.h"

/// @ingroup language
/// @internal
/// @brief A scratch space.
typedef struct Nucleus_Language_ScratchSpace Nucleus_Language_ScratchSpace;


struct Nucleus_Language_Context
{
    Nucleus_Language_FeatureLevelOne_Context __parent;
    /// @brief A null pointer or a pointer to the first element of the singly-linked list of @a (Nucleus_Language_ScratchSpace) objects.
    Nucleus_Language_ScratchSpace *scratchSpaces;
    /// @brief The string heap.
    Nucleus_Language_StringHeap stringHeap;
    /// @brief The general heap.
    Nucleus_Language_GeneralHeap generalHeap;
}; // struct Nucleus_Language_Context
