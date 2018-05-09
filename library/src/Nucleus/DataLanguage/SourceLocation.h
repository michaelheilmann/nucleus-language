// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source location.
typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;

struct Nucleus_DataLanguage_SourceLocation
{
    Nucleus_DataLanguage_Source *source;
    Nucleus_Interpreter_Size offset;
}; // struct Nucleus_DataLanguage_SourceLocation


Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceLocation_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source,
        Nucleus_Interpreter_Size offset
    );
