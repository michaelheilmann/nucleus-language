// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source location.
typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;

struct Nucleus_DataLanguage_SourceLocation
{
    Nucleus_DataLanguage_Source *source;
    size_t offset;
}; // struct Nucleus_DataLanguage_SourceLocation


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceLocation_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceLocation_assign
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *target,
        Nucleus_DataLanguage_SourceLocation *source
    );
