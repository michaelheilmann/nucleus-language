#pragma once

#include "Nucleus/DataLanguage/Parser.h"
#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Scanner.h"

struct DL_Parser
{
    DL_Object __parent;
    DL_Scanner *scanner;
}; // struct DL_Parser

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Parser *self,
        DL_Scanner *scanner
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Parser *self
    );
