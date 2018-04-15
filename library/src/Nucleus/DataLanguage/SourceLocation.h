#pragma once

#include "Nucleus/DataLanguage/Forward.h"

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
