// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/SourceLocation-private.c.i"

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceLocation_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source,
        Nucleus_Interpreter_Size offset
    )
{
    Nucleus_DataLanguage_SourceLocation *self = (Nucleus_DataLanguage_SourceLocation *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_SourceLocation));
    initialize(context, self, source, offset);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}
