// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/SourceIterator-private.h.i"

Nucleus_Interpreter_NonNull() static void
finalize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{}

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    )
{
    Nucleus_Interpreter_Context_assertNotNull(context, self);
    self->source = Nucleus_DataLanguage_Source_createDefault(context);
    self->iterator = Nucleus_Interpreter_StringIterator_create(context, Nucleus_DataLanguage_Source_getString(context, self->source));
}

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    )
{}

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
                        NUCLEUS_INTERPRETER_FINALIZEFOREIGNOBJECT(&finalize),
                        NUCLEUS_INTERPRETER_VISITFOREIGNOBJECT(&visit),
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}
