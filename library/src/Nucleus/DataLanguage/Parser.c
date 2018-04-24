// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/Parser-private.c.i"

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_Parser *
Nucleus_DataLanguage_Parser_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Parser *self = (Nucleus_DataLanguage_Parser *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(Nucleus_DataLanguage_Parser));
    initialize(context, self, scanner);
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Parser_getSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ return Nucleus_DataLanguage_Scanner_getSource(context, parser->scanner); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Parser_setSource
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Source *source
    )
{ Nucleus_DataLanguage_Scanner_setSource(context, parser->scanner, source); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_Parser_run
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ return parseUnit(context, parser); }
