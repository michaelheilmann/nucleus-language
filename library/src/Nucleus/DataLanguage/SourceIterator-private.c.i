#include "Nucleus/DataLanguage/SourceIterator-private.h.i"

Nucleus_DataLanguage_NonNull() static void
finalize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    )
{}

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    )
{
    Nucleus_DataLanguage_Context_assertNotNull(context, self);
    self->source = Nucleus_DataLanguage_Source_createDefault(context);
    self->iterator = Nucleus_DataLanguage_StringIterator_create(context, Nucleus_DataLanguage_Source_getString(context, self->source));
}

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    )
{}
