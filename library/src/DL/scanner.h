/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"
#include "DL/stringbuffer.h"
#include "DL/token_kind.h"

struct DL_Scanner
{
    DL_StringTable *stringTable;
    DL_StringBuffer stringBuffer;
    DL_Source *source;
    DL_Token_Kind tokenKind;
};

DL_NonNull() void
DL_Scanner_initialize
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_StringTable *stringTable
    );

DL_NonNull() void
DL_Scanner_uninitialize
    (
        DL_Scanner *scanner
    );

DL_NonNull() void
DL_Scanner_setInput
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_Source *input
    );

DL_NonNull() DL_Source *
DL_Scanner_getSource
    (
        DL_Context *context,
        DL_Scanner *scanner
    );
