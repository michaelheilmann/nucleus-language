#pragma once

#include "Nucleus/Interpreter/String.h"
#include "Nucleus/Interpreter/HeapObject.h"
#include <stddef.h> /// @todo For size_t. Remove this.

struct Nucleus_Interpreter_String
{
    Nucleus_Interpreter_HeapObject __parent;
    size_t hashValue;
    size_t numberOfBytes;
    char bytes[];
}; // struct Nucleus_Interpreter_String
