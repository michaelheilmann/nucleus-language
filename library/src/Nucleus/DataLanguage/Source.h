/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

struct Nucleus_DataLanguage_Source
{
    DL_LineMap *lineMap; ///< @brief The line map.
    Nucleus_DataLanguage_String *name; ///< @brief The source name.
    Nucleus_DataLanguage_String *string; ///< @brief The source string.
};

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
