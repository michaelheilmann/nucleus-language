#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/HeapObject.h"
#include <stddef.h> /// @todo For size_t. Remove this.

struct Nucleus_Language_String
{
    Nucleus_Language_Object __parent;
    size_t hashValue;
    size_t numberOfBytes;
    char bytes[];
}; // struct Nucleus_Language_String
