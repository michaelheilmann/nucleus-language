// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Source.h"

static Nucleus_Interpreter_Type *g_type = NULL;

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

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );
