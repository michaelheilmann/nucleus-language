/// @file Nucleus/Interpreter/getFileContents.h
/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Interpreter/Annotations.h"

// Forward declarations.
typedef struct Nucleus_Interpreter_Context Nucleus_Interpreter_Context;
typedef struct Nucleus_Interpreter_String Nucleus_Interpreter_String;
typedef struct Nucleus_Interpreter_StringBuffer Nucleus_Interpreter_StringBuffer;

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Context_getFileContentsStringBuffer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *pathname,
        Nucleus_Interpreter_StringBuffer *stringBuffer
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_Interpreter_Context_getFileContentsString
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *pathname
    );
