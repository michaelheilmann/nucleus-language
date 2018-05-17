// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/Source.h"

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

Nucleus_Interpreter_NonNull() static void
finalize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *self
    );

struct Nucleus_DataLanguage_SourceIterator
{
    Nucleus_DataLanguage_Source *source;
    Nucleus_Interpreter_StringIterator *iterator;
};

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );
