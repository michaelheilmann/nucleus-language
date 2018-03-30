/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

struct DL_Source
{
    DL_Object __parent;
    DL_LineMap *lineMap; ///< @brief The line map.
    DL_String *name; ///< @brief The source name.
    DL_String *string; ///< @brief The source string.
};

DL_NonNull() DL_Source *
DL_Source_create
    (
        DL_Context *context,
        DL_String *name,
        DL_String *string
    );

DL_NonNull() DL_String *
DL_Source_getName
    (
        DL_Context *context,
        DL_Source *source
    );

DL_NonNull() DL_String *
DL_Source_getString
    (
        DL_Context *context,
        DL_Source *source
    );

DL_NonNull() size_t
DL_Source_getBeginOffset
    (
        DL_Context *context,
        DL_Source *source
    );

DL_NonNull() size_t
DL_Source_getEndOffset
    (
        DL_Context *context,
        DL_Source *source
    );


DL_NonNull() DL_Source *
DL_Source_createDefault
    (
        DL_Context *context
    );
