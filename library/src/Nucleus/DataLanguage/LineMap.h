/// @file Nucleus/DataLanguage/LineMap.h
#pragma once

#include "Nucleus/DataLanguage/Context.h"

struct DL_LineMap
{
    DL_Object __parent;
    DL_String *source;
    size_t numberOfLines;
    size_t *lines; // zero-based line index to offset of start of line
};

DL_NonNull() DL_LineMap *
DL_LineMap_create
    (
        DL_Context *context,
        DL_String *source
    );

DL_NonNull() size_t
DL_LineMap_getLineIndex
    (
        DL_Context *context,
        DL_LineMap *lineMap,
        size_t offset
    );
