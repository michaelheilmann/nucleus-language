#pragma once

#include "Nucleus/Interpreter/HeapObject.h"

typedef Nucleus_Interpreter_HeapObject Nucleus_DataLanguage_HeapObject;

#define Nucleus_DataLanguage_HeapObject_Finalize Nucleus_Interpreter_HeapObject_Finalize

#define Nucleus_DataLanguage_HeapObject_Visit Nucleus_Interpreter_HeapObject_Visit
