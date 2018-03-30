/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"
#include "Nucleus/DataLanguage/SourceLocation.h"

DL_NonNull() DL_SourceIterator *
DL_SourceIterator_create
    (
        DL_Context *context
    );

DL_NonNull() DL_Source *
DL_SourceIterator_getSource
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    );

DL_NonNull() void
DL_SourceIterator_setSource
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        DL_Source *source
    );

DL_NonNull() DL_SourceLocation *
DL_SourceIterator_getSourceLocation
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    );

DL_NonNull() void
DL_SourceIterator_setSourceLocation
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        DL_SourceLocation *sourceLocation
    );

DL_NonNull() void
DL_SourceIterator_increment
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    );

DL_NonNull() void
DL_SourceIterator_decrement
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    );

DL_NonNull() DL_Symbol
DL_SourceIterator_getSymbol
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator
    );

DL_NonNull() DL_String *
DL_SourceIterator_getLexeme
    (
        DL_Context *context,
        DL_SourceIterator *sourceIterator,
        size_t begin,
        size_t length
    );
