#include "Nucleus/DataLanguage/SourceIterator-private.h.i"

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    )
{}

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceIterator *self
    )
{
    DL_Context_assertNotNull(context, self);
    self->source = DL_Source_createDefault(context);
    self->iterator = DL_StringIterator_create(context, DL_Source_getString(context, self->source));
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_SourceIterator *self
    )
{}