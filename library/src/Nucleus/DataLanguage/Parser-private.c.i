#include "Nucleus/DataLanguage/Parser-private.h.i"

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *self,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    self->scanner = scanner;
    Nucleus_DataLanguage_SourceLocation *begin = Nucleus_DataLanguage_Scanner_getSourceLocation(context, self->scanner),
                                          *end = Nucleus_DataLanguage_Scanner_getSourceLocation(context, self->scanner);
    self->token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Begin, begin, end,
                                                    Nucleus_DataLanguage_String_create(context, "<begin>",
                                                                                       sizeof("<begin>") - 1));
}

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *self
    )
{}

Nucleus_DataLanguage_NoReturn() Nucleus_DataLanguage_NonNull() static void
syntacticalError
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_SyntacticalError); }

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Token *
getToken
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ return parser->token; }

Nucleus_DataLanguage_NonNull() static void
increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{ parser->token = Nucleus_DataLanguage_Scanner_scan(context, parser->scanner); }

Nucleus_DataLanguage_NonNull() static bool
is
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser,
        Nucleus_DataLanguage_Token_Kind tokenKind
    )
{ return Nucleus_DataLanguage_Token_getKind(context, getToken(context, parser)) == tokenKind; }

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseExpression
    (
        Nucleus_DataLanguage_Context *context,
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
                Nucleus_DataLanguage_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_DataLanguage_Boolean value =
                    Nucleus_DataLanguage_stringToBoolean(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createBooleanNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_IntegerLiteral:
            {
                Nucleus_DataLanguage_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_DataLanguage_Integer value =
                    Nucleus_DataLanguage_stringToInteger(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createIntegerNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_RealLiteral:
            {
                Nucleus_DataLanguage_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_DataLanguage_Real value =
                    Nucleus_DataLanguage_stringToReal(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createRealNode(context, value);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_StringLiteral:
            {
                Nucleus_DataLanguage_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_DataLanguage_String *value =
                    Nucleus_DataLanguage_stringToString(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createStringNode(context, lexeme);
                increment(context, parser);
                return node;
            }
        case Nucleus_DataLanguage_Token_Kind_VoidLiteral:
            {
                Nucleus_DataLanguage_String *lexeme =
                    Nucleus_DataLanguage_Token_getText(context, getToken(context, parser));
                Nucleus_DataLanguage_Void value =
                    Nucleus_DataLanguage_stringToVoid(context, lexeme);
                Nucleus_DataLanguage_AST_Node *node =
                    Nucleus_DataLanguage_AST_createVoidNode(context, value);
                increment(context, parser);
                return node;
            }
        default:
            syntacticalError(context, parser);
    };
}

/*--------------------------------------------------------------------------------------------------------------------*/

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListElement
    (
        Nucleus_DataLanguage_Context *context,
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

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseListExpression
    (
        Nucleus_DataLanguage_Context *context,
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
            if (is(context, parser, Nucleus_DataLanguage_Token_Kind_End))
            { syntacticalError(context, parser); } /* unclosed list expression (end of input) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter))
            { syntacticalError(context, parser); } /* unclosed list expression (wrong closing delimiter) */
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

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureElement
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    Nucleus_DataLanguage_AST_Node *structureElementNode =
        Nucleus_DataLanguage_AST_createStructureElementNode(context);

    // Name
    Nucleus_DataLanguage_AST_Node *nameNode;
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Name))
    { syntacticalError(context, parser); }
    increment(context, parser);

    // Colon
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Colon))
    { syntacticalError(context, parser); }
    increment(context, parser);

    // Expression
    Nucleus_DataLanguage_AST_Node *expressionNode =
        parseExpression(context, parser);

    return structureElementNode;
}

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseStructureExpression
    (
        Nucleus_DataLanguage_Context *context,
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
            if (is(context, parser, Nucleus_DataLanguage_Token_Kind_End))
            { syntacticalError(context, parser); } /* unclosed structure expression (end of input) */
            else if (is(context, parser, Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter))
            { syntacticalError(context, parser); } /* unclosed list expression (wrong closing delimiter) */
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

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_AST_Node *
parseUnit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Parser *parser
    )
{
    if (!is(context, parser, Nucleus_DataLanguage_Token_Kind_Begin))
    { syntacticalError(context, parser); }
    increment(context, parser);
    Nucleus_DataLanguage_AST_Node *unitNode = Nucleus_DataLanguage_AST_createUnitNode(context);
    switch (Nucleus_DataLanguage_Token_getKind(context, getToken(context, parser)))
    {
        case Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter:
            return parseListExpression(context, parser);
        case Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter:
            return parseStructureExpression(context, parser);
        default:
            syntacticalError(context, parser);
    };
    return unitNode;
}
