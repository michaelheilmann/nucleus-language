// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Context.h"

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language line map.
typedef struct Nucleus_DataLanguage_LineMap Nucleus_DataLanguage_LineMap;


struct Nucleus_DataLanguage_LineMap
{
    Nucleus_DataLanguage_String *source;
    size_t numberOfLines;
    size_t *lines; // zero-based line index to offset of start of line
}; // struct Nucleus_DataLanguage_LineMap

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_LineMap *
Nucleus_DataLanguage_LineMap_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_LineMap_getLineIndex
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_LineMap *lineMap,
        size_t offset
    );
