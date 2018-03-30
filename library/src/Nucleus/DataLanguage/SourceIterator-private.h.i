#pragma once

#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Source.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceIterator *self
    );

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_SourceIterator *self
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_SourceIterator *self
    );

struct DL_SourceIterator
{
    DL_Object _parent;
    DL_Source *source;
    DL_StringIterator *iterator;
};