// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/SourceLocation-private.c.i"

#include "Nucleus/DataLanguage/Context.h"

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
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceLocation_assign
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *target,
        Nucleus_DataLanguage_SourceLocation *source
    );
