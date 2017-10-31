/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"

struct DL_Source
{
    DL_Object __parent;
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
