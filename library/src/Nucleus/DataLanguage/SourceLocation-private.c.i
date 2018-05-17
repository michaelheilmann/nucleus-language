// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/SourceLocation-private.h.i"

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceLocation *self,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    )
{
    self->source = source;
    self->offset = offset;
}

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    )
{ /**@todo Add implementation.*/ }

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    )
{
    if (!g_type)
    {
        g_type = Nucleus_Interpreter_getOrCreateForeignType
                    (
                        context,
                        NULL,
                        NUCLEUS_INTERPRETER_VISITFOREIGNOBJECT(&visit),
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}
