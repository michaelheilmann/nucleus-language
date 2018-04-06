#pragma once

#include "Nucleus/DataLanguage/Forward.h"

typedef struct Nucleus_DataLanguage_AST_Node Nucleus_DataLanguage_AST_Node;

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_Parser *
Nucleus_DataLanguage_Parser_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Parser_getSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Parser_setSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Source *source
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_Parser_run
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );
