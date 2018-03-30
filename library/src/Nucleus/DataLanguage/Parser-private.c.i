#include "Nucleus/DataLanguage/Parser-private.h.i"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Parser *self,
        DL_Scanner *scanner
    )
{
    self->scanner = scanner;
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Parser *self
    )
{}
