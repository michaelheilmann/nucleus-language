/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"

struct DL_Parser
{
    int dummy;
};

DL_NonNull() void
DL_Parser_initialize
    (
        DL_Context *context,
        DL_Parser *parser,
        DL_Scanner *scanner
    );

DL_NonNull() void
DL_Parser_uninitialize
    (
        DL_Parser *parser
    );
