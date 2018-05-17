// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/Parser-private.h.i"

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *self,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    self->scanner = scanner;
    Nucleus_DataLanguage_SourceLocation *begin = Nucleus_DataLanguage_Scanner_getSourceLocation(context, self->scanner),
                                          *end = Nucleus_DataLanguage_Scanner_getSourceLocation(context, self->scanner);
    self->token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Begin, begin, end,
                                                    Nucleus_Interpreter_String_create(context, "<begin>",
                                                                                      sizeof("<begin>") - 1));
}

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *self
    )
{}

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    )
{
    if (!g_type)
    {
        g_type = Nucleus_Interpreter_getOrCreateForeignType
                    (
                        context,
                        NULL,
                        NUCLEUS_INTERPRETER_VISITFOREIGNOBJECT(&visit),
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_Interpreter_NoReturn() Nucleus_Interpreter_NonNull() static void
raiseSyntacticalError
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
	Nucleus_Interpreter_ProcessContext_setStatus(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context),
	                                             Nucleus_DataLanguage_Status_SyntacticalError);
	Nucleus_Interpreter_ProcessContext_jump(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
}

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_Token *
getToken
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ return parser->token; }

Nucleus_Interpreter_NonNull() static void
increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ parser->token = Nucleus_DataLanguage_Scanner_scan(context, parser->scanner); }

Nucleus_Interpreter_NonNull() static bool
is
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Token_Kind tokenKind
    )
{ return Nucleus_DataLanguage_Token_getKind(context, getToken(context, parser)) == tokenKind; }

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    switch (Nucleus_DataLanguage_Token_getKind(context, getToken(context, parser)))
    {
        case Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter:
            return parseListExpression(context, parser);
        case Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter:
            return parseStructureExpression(context, parser);
        case Nucleus_DataLanguage_Token_Kind_TrueLiteral:
        case Nucleus_DataLanguage_Token_Kind_FalseLiteral:
            {
                Nucleus_Interpreter_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_Interpreter_Boolean value =
                    Nucleus_Interpreter_stringToBoolean(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createBooleanNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_IntegerLiteral:
            {
                Nucleus_Interpreter_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_Interpreter_Integer value =
                    Nucleus_Interpreter_stringToInteger(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createIntegerNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_RealLiteral:
            {
                Nucleus_Interpreter_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_Interpreter_Real value =
                    Nucleus_Interpreter_stringToReal(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createRealNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_StringLiteral:
            {
                Nucleus_Interpreter_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_Interpreter_String *value =
                    Nucleus_Interpreter_stringToString(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createStringNode(context, lexeme);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_VoidLiteral:
            {
                Nucleus_Interpreter_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_Interpreter_Void value =
                    Nucleus_Interpreter_stringToVoid(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createVoidNode(context, value);
                increment(context, parser);
                return node;
            }
        default:
            raiseSyntacticalError(context, parser);
    };
}

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListElement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    Nucleus_DataLanguage_AST_Node *listElementNode =
                Nucleus_DataLanguage_AST_createListElementNode(context);

    // Expression
    Nucleus_DataLanguage_AST_Node *expressionNode =
        parseExpression(context, parser);

    return listElementNode;
}

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ 
    Nucleus_DataLanguage_AST_Node *listNode =
                Nucleus_DataLanguage_AST_createListNode(context);
    increment(context, parser);
    do
    {
        if (is(context, parser, Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter))
        { increment(context, parser); break; }
        else
        {
            Nucleus_DataLanguage_AST_Node *listElementNode =
                parseListElement(context, parser);
			//Nucleus_DataLanguage_AST_Node_append(context, listNode, listElementNode);
            if (is(context, parser, Nucleus_DataLanguage_Token_Kind_End))
            { raiseSyntacticalError(context, parser); } /* unclosed list expression (end of input) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter))
            { raiseSyntacticalError(context, parser); } /* unclosed list expression (wrong closing delimiter) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_Comma))
            {
                increment(context, parser);
                continue;
            }
        }
    } while (true);
    return listNode;
}

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureElement
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    Nucleus_DataLanguage_AST_Node *structureElementNode =
        Nucleus_DataLanguage_AST_createStructureElementNode(context);

    // Name
    Nucleus_DataLanguage_AST_Node *nameNode;
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Name))
    { raiseSyntacticalError(context, parser); }
    increment(context, parser);
	//Nucleus_DataLanguage_AST_Node_append(structureElementNode, nameNode);
	
    // Colon
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Colon))
    { raiseSyntacticalError(context, parser); }
    increment(context, parser);

    // Expression
    Nucleus_DataLanguage_AST_Node *expressionNode =
        parseExpression(context, parser);
	//Nucleus_DataLanguage_AST_Node_append(structureElementNode, expressionNode);

    return structureElementNode;
}

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureExpression
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    Nucleus_DataLanguage_AST_Node *structureNode =
                Nucleus_DataLanguage_AST_createStructureNode(context);
    increment(context, parser);
    do
    {
        if (is(context, parser, Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter))
        { increment(context, parser); break; }
        else
        {
            Nucleus_DataLanguage_AST_Node *structureElementNode =
                parseStructureElement(context, parser);
			//Nucleus_DataLanguage_AST_Node_append(context, structureNode, structureElementNode);
            if (is(context, parser, Nucleus_DataLanguage_Token_Kind_End))
            { raiseSyntacticalError(context, parser); } /* unclosed structure expression (end of input) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter))
            { raiseSyntacticalError(context, parser); } /* unclosed list expression (wrong closing delimiter) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_Comma))
            {
                increment(context, parser);
                continue;
            }
        }
    } while (true);
    return structureNode;
}

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_AST_Node *
parseUnit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Begin))
    { raiseSyntacticalError(context, parser); }
    increment(context, parser);
    Nucleus_DataLanguage_AST_Node *unitNode = Nucleus_DataLanguage_AST_createUnitNode(context);
    switch (Nucleus_DataLanguage_Token_getKind(context, getToken(context, parser)))
    {
        case Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter:
            return parseListExpression(context, parser);
        case Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter:
            return parseStructureExpression(context, parser);
        default:
            raiseSyntacticalError(context, parser);
    };
    return unitNode;
}
