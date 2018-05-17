// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/SourceLocation.h"

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source iterator.
typedef struct Nucleus_DataLanguage_SourceIterator Nucleus_DataLanguage_SourceIterator;

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceIterator *
Nucleus_DataLanguage_SourceIterator_create
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_SourceIterator_getSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceIterator_getSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_SourceIterator_decrement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol
Nucleus_DataLanguage_SourceIterator_getSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_SourceIterator_getLexeme
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_Interpreter_Size begin,
        Nucleus_Interpreter_Size length
    );
