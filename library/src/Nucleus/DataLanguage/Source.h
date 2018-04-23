// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

// Forward declarations.
typedef struct Nucleus_DataLanguage_LineMap Nucleus_DataLanguage_LineMap;
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

struct Nucleus_DataLanguage_Source
{
    Nucleus_DataLanguage_LineMap *lineMap; ///< @brief The line map.
    Nucleus_DataLanguage_String *name; ///< @brief The source name.
    Nucleus_DataLanguage_String *string; ///< @brief The source string.
}; // struct Nucleus_DataLanguage_Source

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *name,
        Nucleus_DataLanguage_String *string
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Source_getName
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Source_getString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_Source_getBeginOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_Source_getEndOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    );


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_createDefault
    (
        Nucleus_DataLanguage_Context *context
    );
