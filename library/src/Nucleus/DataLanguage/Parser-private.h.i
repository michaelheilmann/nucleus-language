// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Parser.h"
#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/AST/Node.h"

struct Nucleus_DataLanguage_Parser
{
    Nucleus_DataLanguage_Scanner *scanner;
    Nucleus_DataLanguage_Token *token;
}; // struct Nucleus_DataLanguage_Parser

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *self,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *self
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Token *
getToken
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_DataLanguage_NonNull() static void
increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_DataLanguage_NonNull() static bool
is
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Token_Kind tokenKind
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseExpression
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListElement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListExpression
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureElement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureExpression
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseUnit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );
