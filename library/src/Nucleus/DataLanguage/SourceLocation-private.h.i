// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/SourceLocation.h"
#include "Nucleus/DataLanguage/Context.h"

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceLocation *self,
        Nucleus_DataLanguage_Source *source,
        size_t offset
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceLocation *self
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );
