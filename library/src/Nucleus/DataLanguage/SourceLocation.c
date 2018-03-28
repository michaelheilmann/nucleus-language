#include "Nucleus/DataLanguage/SourceLocation.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceLocation *self,
        DL_Source *source,
        int lineNumber,
        size_t offset
    );

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_SourceLocation *self
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_SourceLocation *self
    );

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceLocation *self,
        DL_Source *source,
        int lineNumber,
        size_t offset
    )
{
    self->source = source;
    self->lineNumber = lineNumber;
    self->offset = offset;
}

DL_NonNull() DL_SourceLocation *
DL_SourceLocation_create
    (
        DL_Context *context,
        DL_Source *source,
        int lineNumber,
        size_t offset
    )
{
    DL_SourceLocation *self = (DL_SourceLocation *)DL_Context_allocateObject(context, sizeof(DL_SourceLocation));
    initialize(context, self, source, lineNumber, offset);
    return self;
}

DL_NonNull() void
DL_SourceLocation_assign
    (
        DL_Context *context,
        DL_SourceLocation *target,
        DL_SourceLocation *source
    );
