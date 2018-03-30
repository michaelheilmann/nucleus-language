#pragma once

#include "Nucleus/Interpreter/HeapObject.h"

typedef Nucleus_Interpreter_HeapObject DL_Object;

#define DL_Finalize Nucleus_Interpreter_HeapObject_Finalize

#define DL_Visit Nucleus_Interpreter_HeapObject_Visit
