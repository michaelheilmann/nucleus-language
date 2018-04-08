#include "Nucleus/DataLanguage/SourceLocation.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *self,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceLocation *self
    );

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *self,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    )
{
    self->source = source;
    self->offset = offset;
}

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    )
{ /**@todo Add implementation.*/ }


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceLocation_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    )
{
    Nucleus_DataLanguage_SourceLocation *self = (Nucleus_DataLanguage_SourceLocation *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(Nucleus_DataLanguage_SourceLocation));
    initialize(context, self, source, offset);
    Nucleus_DataLanguage_Object_setVisitor(context, NUCLEUS_DATALANGUAGE_OBJECT(self),
                                           NUCLEUS_DATALANGUAGE_OBJECT_VISIT(&visit));
    return self;
}

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceLocation_assign
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *target,
        Nucleus_DataLanguage_SourceLocation *source
    );
