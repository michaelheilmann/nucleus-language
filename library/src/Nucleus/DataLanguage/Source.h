// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

// Forward declarations.
typedef struct Nucleus_DataLanguage_LineMap Nucleus_DataLanguage_LineMap;
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

struct Nucleus_DataLanguage_Source
{
    Nucleus_DataLanguage_LineMap *lineMap; ///< @brief The line map.
    Nucleus_Interpreter_String *name; ///< @brief The source name.
    Nucleus_Interpreter_String *string; ///< @brief The source string.
}; // struct Nucleus_DataLanguage_Source

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *name,
        Nucleus_Interpreter_String *string
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Source_getName
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Source_getString
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_Source_getBeginOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_Source_getEndOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    );


Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_createDefault
    (
        Nucleus_Interpreter_Context *context
    );
