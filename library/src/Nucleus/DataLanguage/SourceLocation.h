#pragma once

#include "Nucleus/DataLanguage/Forward.h"

struct DL_SourceLocation
{
    DL_Object __parent;
    DL_Source *source;
    size_t offset;
}; // struct DL_SourceLocation


DL_NonNull() DL_SourceLocation *
DL_SourceLocation_create
    (
        DL_Context *context,
        DL_Source *source,
        size_t offset
    );

DL_NonNull() void
DL_SourceLocation_assign
    (
        DL_Context *context,
        DL_SourceLocation *target,
        DL_SourceLocation *source
    );
