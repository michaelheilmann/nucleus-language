// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Parser.h"
#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/AST/Node.h"

struct Nucleus_DataLanguage_Parser
{
    Nucleus_DataLanguage_Scanner *scanner;
    Nucleus_DataLanguage_Token *token;
}; // struct Nucleus_DataLanguage_Parser

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *self,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *self
    );

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_NoReturn() Nucleus_Interpreter_NonNull() static void
raiseSyntacticalError
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );
	
Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_Token *
getToken
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_Interpreter_NonNull() static void
increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_Interpreter_NonNull() static bool
is
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Token_Kind tokenKind
    );

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListElement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureElement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseUnit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    );
