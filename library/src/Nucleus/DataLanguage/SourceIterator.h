/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"
#include "Nucleus/DataLanguage/SourceLocation.h"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceIterator *
Nucleus_DataLanguage_SourceIterator_create
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_SourceIterator_getSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_SourceIterator_getSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_setSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_SourceIterator_decrement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Symbol
Nucleus_DataLanguage_SourceIterator_getSymbol
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_SourceIterator_getLexeme
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_SourceIterator *sourceIterator,
        size_t begin,
        size_t length
    );
