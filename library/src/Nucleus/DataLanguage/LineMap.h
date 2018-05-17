// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language line map.
typedef struct Nucleus_DataLanguage_LineMap Nucleus_DataLanguage_LineMap;


struct Nucleus_DataLanguage_LineMap
{
    Nucleus_Interpreter_String *source;
    Nucleus_Interpreter_Size numberOfLines;
    Nucleus_Interpreter_Size *lines; // zero-based line index to offset of start of line
}; // struct Nucleus_DataLanguage_LineMap

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_LineMap *
Nucleus_DataLanguage_LineMap_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *source
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_LineMap_getLineIndex
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_LineMap *lineMap,
        Nucleus_Interpreter_Size offset
    );
