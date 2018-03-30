#pragma once

#include "Nucleus/DataLanguage/Forward.h"

DL_ReturnNonNull() DL_Parser *
DL_Parser_create
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() DL_Source *
DL_Parser_getSource
    (
        DL_Context *context,
        DL_Parser *parser
    );

DL_NonNull() void
DL_Parser_setSource
    (
        DL_Context *context,
        DL_Parser *parser,
        DL_Source *source
    );
