/// @file Nucleus/DataLanguage/LineMap.h
#pragma once

#include "Nucleus/DataLanguage/Context.h"

struct DL_LineMap
{
    Nucleus_DataLanguage_Object __parent;
    Nucleus_DataLanguage_String *source;
    size_t numberOfLines;
    size_t *lines; // zero-based line index to offset of start of line
};

Nucleus_DataLanguage_NonNull() DL_LineMap *
DL_LineMap_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *source
    );

Nucleus_DataLanguage_NonNull() size_t
DL_LineMap_getLineIndex
    (
        Nucleus_DataLanguage_Context *context,
        DL_LineMap *lineMap,
        size_t offset
    );
