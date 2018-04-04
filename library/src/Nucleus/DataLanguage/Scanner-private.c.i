#include "Nucleus/DataLanguage/Scanner-private.h.i"

/// @todo Parsing must be performed using Unicode symbols.
/// @todo The string buffer should be created and destroyed once when the scanner is initialized resp. uninitialized.
DL_ReturnNonNull() DL_NonNull() static DL_String *
processStringLiteral
    (
        DL_Context *context,
        DL_String *stringLiteral
    )
{
    DL_StringBuffer stringBuffer;
    DL_StringBuffer_initialize(context, &stringBuffer, 512);
    DL_JumpTarget jt;
    DL_String *string = NULL;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        const char *start = DL_String_getBytes(context, stringLiteral);
        const char *end = start + DL_String_getNumberOfBytes(context, stringLiteral);
        const char *current = start;
        bool lastWasSlash = false;
        if (*current != '"')
        {
            DL_Context_raiseError(context, DL_Status_InvalidArgument);
        }
        current++;
        while (current != end)
        {
            if (lastWasSlash)
            {
                if (*current == '\\')
                {
                    static const char SYMBOL = '\\';
                    DL_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == '0')
                {
                    static const char SYMBOL = '\0';
                    DL_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == 'n')
                {
                    static const char SYMBOL = '\n';
                    DL_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == 'r')
                {
                    static const char SYMBOL = '\r';
                    DL_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == '"')
                {
                    static const char SYMBOL = '"';
                    DL_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else
                {
                    DL_Context_raiseError(context, DL_Status_InvalidArgument);
                }
                current++;
                lastWasSlash = false;
            }
            else
            {
                if (*current == '\\')
                {
                    current++;
                    lastWasSlash = true;
                }
                else if (*current == '"')
                {
                    break;
                }
                else
                {
                    DL_StringBuffer_append(context, &stringBuffer, current, sizeof(*current));
                    current++;
                }
            }
        }
        DL_Context_popJumpTarget(context);
        string = DL_String_create(context, DL_StringBuffer_getBytes(context, &stringBuffer), DL_StringBuffer_getSize(context, &stringBuffer));
        DL_StringBuffer_uninitialize(context, &stringBuffer);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringBuffer_uninitialize(context, &stringBuffer);
        DL_Context_raiseError(context, DL_Context_getStatus(context));
    }
    return string;
}

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Scanner *self
    )
{
    self->sourceIterator = DL_SourceIterator_create(context);
    self->underscore = DL_PEGNode_createTerminal(context, DL_Symbol_lowLine(context));

    self->lineFeed = DL_PEGNode_createTerminal(context, DL_Symbol_lineFeed(context));
    self->carriageReturn = DL_PEGNode_createTerminal(context, DL_Symbol_carriageReturn(context));
    self->newLine = DL_PEGNode_createOrderedChoice(context, self->lineFeed, self->carriageReturn);

    self->space = DL_PEGNode_createTerminal(context, DL_Symbol_space(context));
    self->characterTabulation = DL_PEGNode_createTerminal(context, DL_Symbol_characterTabulation(context));
    self->whiteSpace = DL_PEGNode_createOrderedChoice(context, self->space, self->characterTabulation);

    self->end = DL_PEGNode_createTerminal(context, DL_Symbol_end(context));
    self->plusSign = DL_PEGNode_createTerminal(context, DL_Symbol_plusSign(context));
    self->hyphenMinus = DL_PEGNode_createTerminal(context, DL_Symbol_hyphenMinus(context));
    self->listOpeningDelimiter = DL_PEGNode_createTerminal(context, DL_Symbol_leftSquareBracket(context));
    self->listClosingDelimiter = DL_PEGNode_createTerminal(context, DL_Symbol_rightSquareBracket(context));
    self->structureOpeningDelimiter = DL_PEGNode_createTerminal(context, DL_Symbol_leftCurlyBracket(context));
    self->structureClosingDelimiter = DL_PEGNode_createTerminal(context, DL_Symbol_rightCurlyBracket(context));
    self->colon = DL_PEGNode_createTerminal(context, DL_Symbol_colon(context));
    self->comma = DL_PEGNode_createTerminal(context, DL_Symbol_comma(context));
    self->solidus = DL_PEGNode_createTerminal(context, DL_Symbol_solidus(context));
    self->reverseSolidus = DL_PEGNode_createTerminal(context, DL_Symbol_reverseSolidus(context));
    self->quotationMark = DL_PEGNode_createTerminal(context, DL_Symbol_quotationMark(context));
    self->fullStop = DL_PEGNode_createTerminal(context, DL_Symbol_fullStop(context));
    self->digit = DL_PEGNode_createTerminalRange(context, DL_Symbol_create_uint8(context, (uint8_t)'0'),
                                                          DL_Symbol_create_uint8(context, (uint8_t)'9'));
    self->nonZeroDigit = DL_PEGNode_createTerminalRange(context, DL_Symbol_create_uint8(context, (uint8_t)'1'),
                                                                 DL_Symbol_create_uint8(context, (uint8_t)'9'));
    self->alphabetic = DL_PEGNode_createOrderedChoice
        (
            context,
            DL_PEGNode_createTerminalRange(context, DL_Symbol_create_uint8(context, (uint8_t)'a'),
                                                    DL_Symbol_create_uint8(context, (uint8_t)'z')),
            DL_PEGNode_createTerminalRange(context, DL_Symbol_create_uint8(context, (uint8_t)'A'),
                                                    DL_Symbol_create_uint8(context, (uint8_t)'Z'))
        );
    self->lowercaseN = DL_PEGNode_createTerminal(context, DL_Symbol_create_uint8(context, (uint8_t)'n'));
    self->zeroDigit = DL_PEGNode_createTerminal(context, DL_Symbol_create_uint8(context, (uint8_t)'0'));
    self->asterisk = DL_PEGNode_createTerminal(context, DL_Symbol_create_uint8(context, (uint8_t)'*'));
    self->exponentIndicator = DL_PEGNode_createOrderedChoice
        (
            context,
            DL_PEGNode_createTerminal(context, DL_Symbol_create_uint8(context, (uint8_t)'e')),
            DL_PEGNode_createTerminal(context, DL_Symbol_create_uint8(context, (uint8_t)'E'))
        );
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Scanner *self
    )
{}

DL_NonNull() static void
increment
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ DL_Scanner_increment(context, scanner); }

DL_NonNull() static DL_Symbol
current
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_Scanner_getSymbol(context, scanner); }

DL_NonNull() static bool
test
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_PEGNode *pegNode
    )
{ return DL_PEGNode_test(context, pegNode, scanner); }

DL_NonNull() static DL_SourceLocation *
getSourceLocation
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_Scanner_getSourceLocation(context, scanner); }

DL_NonNull() static DL_String *
getLexeme
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_SourceLocation *begin,
        DL_SourceLocation *end
    )
{
    return DL_SourceIterator_getLexeme(context, scanner->sourceIterator, begin->offset, end->offset - begin->offset);
}

DL_NonNull() static void
scanExponent
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    increment(context, scanner);

    if (test(context, scanner, scanner->plusSign) ||
        test(context, scanner, scanner->hyphenMinus))
    { increment(context, scanner); }

    if (!test(context, scanner, scanner->digit))
    { DL_Context_raiseError(context, DL_Status_LexicalError); }

    do
    {
        increment(context, scanner);
    } while(test(context, scanner, scanner->digit));
}

DL_NonNull() static DL_Token *
scan
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    //
    if (test(context, scanner, scanner->end))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner),
                          *end = getSourceLocation(context, scanner);
        return DL_Token_create(context, DL_Token_Kind_End, begin, end,
                               DL_String_create(context, "<end>", sizeof("<end>") - 1));
    }
    //
    while (test(context, scanner, scanner->newLine) || test(context, scanner, scanner->whiteSpace))
    {
        if (test(context, scanner, scanner->newLine))
        {
            DL_Symbol old = current(context, scanner);
            increment(context, scanner);
            if (DL_Symbol_equal(context, old, DL_Symbol_carriageReturn(context)) &&
                DL_Symbol_equal(context, current(context, scanner), DL_Symbol_lineFeed(context)))
            {
                increment(context, scanner);
            }
        }
        else if (test(context, scanner, scanner->whiteSpace))
        {
            do
            {
                increment(context, scanner);
            } while (test(context, scanner, scanner->whiteSpace));
        }
    }
    //
    if (test(context, scanner, scanner->listOpeningDelimiter))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_ListOpeningDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->listClosingDelimiter))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_ListClosingDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->structureOpeningDelimiter))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_StructureOpeningDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->structureClosingDelimiter))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_StructureClosingDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->colon))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_Colon, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->comma))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_Comma, begin, end, lexeme);
        return token;
    }
    // StringLiteral
    if (test(context, scanner, scanner->quotationMark))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        DL_SourceLocation *end = begin;
        increment(context, scanner);
        bool lastWasSlash = false;
        while (true)
        {
            if (lastWasSlash)
            {
                if (test(context, scanner, scanner->reverseSolidus))
                {
                    increment(context, scanner);
                    lastWasSlash = false;
                    continue;
                }
                else if (test(context, scanner, scanner->lowercaseN))
                {
                    increment(context, scanner);
                    lastWasSlash = false;
                    continue;
                }
                else if (test(context, scanner, scanner->quotationMark))
                {
                    increment(context, scanner);
                    lastWasSlash = false;
                    continue;
                }
                else if (test(context, scanner, scanner->newLine))
                {
                    // unclosed string literal because of newline
                    DL_Context_raiseError(context, DL_Status_LexicalError);
                }
                else if (test(context, scanner, scanner->end))
                {
                    // unclosed string literal because of end of input
                    DL_Context_raiseError(context, DL_Status_LexicalError);
                }
                else
                {
                    // unexpected symbol
                    DL_Context_raiseError(context, DL_Status_LexicalError);
                }
            }
            else
            {
                if (test(context, scanner, scanner->reverseSolidus))
                {
                    increment(context, scanner);
                    lastWasSlash = true;
                    continue;
                }
                if (test(context, scanner, scanner->quotationMark))
                {
                    increment(context, scanner);
                    end = getSourceLocation(context, scanner);
                    break;
                }
                increment(context, scanner);
            }
        } // while
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        lexeme = processStringLiteral(context, lexeme);
        DL_Token *token = DL_Token_create(context, DL_Token_Kind_StringLiteral, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->underscore) || test(context, scanner, scanner->alphabetic))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        do
        {
            increment(context, scanner);
        } while (test(context, scanner, scanner->alphabetic) || test(context, scanner, scanner->digit) || test(context, scanner, scanner->underscore));
        DL_SourceLocation *end = getSourceLocation(context, scanner);
        DL_String *lexeme = getLexeme(context, scanner, begin, end);
        if (DL_String_equal(context, lexeme, DL_String_create(context, "true", sizeof("true") - 1)))
        {
            DL_SourceLocation *end = getSourceLocation(context, scanner);
            return DL_Token_create(context, DL_Token_Kind_TrueLiteral, begin, end, lexeme);
        }
        else if (DL_String_equal(context, lexeme, DL_String_create(context, "false", sizeof("false") - 1)))
        {
            DL_SourceLocation *end = getSourceLocation(context, scanner);
            return DL_Token_create(context, DL_Token_Kind_FalseLiteral, begin, end, lexeme);
        }
        else if (DL_String_equal(context, lexeme, DL_String_create(context, "null", sizeof("null") - 1)))
        {
            DL_SourceLocation *end = getSourceLocation(context, scanner);
            return DL_Token_create(context, DL_Token_Kind_NullLiteral, begin, end, lexeme);
        }
        else { DL_Context_raiseError(context, DL_Status_LexicalError); }
    }
    //
    if (test(context, scanner, scanner->plusSign) ||
        test(context, scanner, scanner->hyphenMinus) ||
        test(context, scanner, scanner->fullStop) ||
        test(context, scanner, scanner->digit))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        // sign?
        if (test(context, scanner, scanner->plusSign) ||
            test(context, scanner, scanner->hyphenMinus))
        { increment(context, scanner); }

        // integer := '0'
        // real := '0' '.' fractional-part? exponent?
        // real := '0' exponent
        if (test(context, scanner, scanner->zeroDigit))
        {
            increment(context, scanner);
            if (test(context, scanner, scanner->digit))
            { DL_Context_raiseError(context, DL_Status_LexicalError); }

            if (test(context, scanner, scanner->fullStop))
            {
                increment(context, scanner);

                do { increment(context, scanner); } while (test(context, scanner, scanner->digit));

                if (test(context, scanner, scanner->exponentIndicator))
                { scanExponent(context, scanner); }
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else if (test(context, scanner, scanner->exponentIndicator))
            {
                scanExponent(context, scanner);
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else
            {
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_IntegerLiteral, begin, end, lexeme);
                return token;
            }
        }
        // integer := non-zero-digit digit*
        // real := non-zero-digit digit* '.' fractional-part? exponent?
        // real := non-zero-digit digit* exponent
        else if (test(context, scanner, scanner->nonZeroDigit))
        {
            do { increment(context, scanner); } while (test(context, scanner, scanner->digit));
            if (test(context, scanner, scanner->fullStop))
            {
                increment(context, scanner);

                do
                {
                    increment(context, scanner);
                } while (test(context, scanner, scanner->digit));

                if (test(context, scanner, scanner->exponentIndicator))
                { scanExponent(context, scanner); }
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else if (test(context, scanner, scanner->exponentIndicator))
            {
                scanExponent(context, scanner);
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else
            {
                DL_SourceLocation *end = getSourceLocation(context, scanner);
                DL_String *lexeme = getLexeme(context, scanner, begin, end);
                DL_Token *token = DL_Token_create(context, DL_Token_Kind_IntegerLiteral, begin, end, lexeme);
                return token;
            }
        }
        // real := '.' fractional-part exponent?
        else if (test(context, scanner, scanner->fullStop))
        {
            // '.'
            increment(context, scanner);

            // fractional-part
            if (!test(context, scanner, scanner->digit))
            { DL_Context_raiseError(context, DL_Status_LexicalError); }
            do { increment(context, scanner); } while (test(context, scanner, scanner->digit));

            // exponent?
            if (test(context, scanner, scanner->exponentIndicator))
            { scanExponent(context, scanner); }

            DL_SourceLocation *end = getSourceLocation(context, scanner);
            DL_String *lexeme = getLexeme(context, scanner, begin, end);
            DL_Token *token = DL_Token_create(context, DL_Token_Kind_RealLiteral, begin, end, lexeme);
            return token;
        }
    }
    //
    if (test(context, scanner, scanner->solidus))
    {
        DL_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        if (test(context, scanner, scanner->solidus))
        {
            increment(context, scanner);
            while (!test(context, scanner, scanner->end) && !test(context, scanner, scanner->whiteSpace))
            {
                increment(context, scanner);
            }
            DL_SourceLocation *end = getSourceLocation(context, scanner);
            DL_String *lexeme = getLexeme(context, scanner, begin, end);
            DL_Token *token = DL_Token_create(context, DL_Token_Kind_Comment, begin, end, lexeme);
            return token;
        }
        else if (test(context, scanner, scanner->asterisk))
        {
            increment(context, scanner);
            while (true)
            {
                if (test(context, scanner, scanner->end))
                {
                    DL_Context_raiseError(context, DL_Status_LexicalError);
                }
                else if (test(context, scanner, scanner->asterisk))
                {
                    increment(context, scanner);
                    if (test(context, scanner, scanner->solidus))
                    {
                        increment(context, scanner);
                        DL_SourceLocation *end = getSourceLocation(context, scanner);
                        DL_String *lexeme = getLexeme(context, scanner, begin, end);
                        DL_Token *token = DL_Token_create(context, DL_Token_Kind_Comment, begin, end, lexeme);
                        return token;
                    }
                    else
                    {
                        increment(context, scanner);
                    }
                }
                else
                {
                    increment(context, scanner);
                }
            }
        }
        else
        {
            DL_Context_raiseError(context, DL_Status_LexicalError);
        }
    }
    DL_Context_raiseError(context, DL_Status_LexicalError);
}