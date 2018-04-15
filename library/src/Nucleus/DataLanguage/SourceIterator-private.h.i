#pragma once

#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Source.h"

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

Nucleus_DataLanguage_NonNull() static void
finalize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

struct Nucleus_DataLanguage_SourceIterator
{
    Nucleus_DataLanguage_Source *source;
    Nucleus_DataLanguage_StringIterator *iterator;
};
