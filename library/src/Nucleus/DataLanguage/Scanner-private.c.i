#include "Nucleus/DataLanguage/Scanner-private.h.i"

/// @todo Parsing must be performed using Unicode symbols.
/// @todo The string buffer should be created and destroyed once when the scanner is initialized resp. uninitialized.
Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_String *
processStringLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *stringLiteral
    )
{
    Nucleus_DataLanguage_StringBuffer stringBuffer;
    Nucleus_DataLanguage_StringBuffer_initialize(context, &stringBuffer, 512);
    Nucleus_DataLanguage_JumpTarget jt;
    Nucleus_DataLanguage_String *string = NULL;
    Nucleus_DataLanguage_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        const char *start = Nucleus_DataLanguage_String_getBytes(context, stringLiteral);
        const char *end = start + Nucleus_DataLanguage_String_getNumberOfBytes(context, stringLiteral);
        const char *current = start;
        bool lastWasSlash = false;
        if (*current != '"')
        {
            Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_InvalidArgument);
        }
        current++;
        while (current != end)
        {
            if (lastWasSlash)
            {
                if (*current == '\\')
                {
                    static const char SYMBOL = '\\';
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == '0')
                {
                    static const char SYMBOL = '\0';
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == 'n')
                {
                    static const char SYMBOL = '\n';
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == 'r')
                {
                    static const char SYMBOL = '\r';
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else if (*current == '"')
                {
                    static const char SYMBOL = '"';
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, &SYMBOL, sizeof(SYMBOL));
                }
                else
                {
                    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_InvalidArgument);
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
                    Nucleus_DataLanguage_StringBuffer_append(context, &stringBuffer, current, sizeof(*current));
                    current++;
                }
            }
        }
        Nucleus_DataLanguage_Context_popJumpTarget(context);
        string = Nucleus_DataLanguage_String_create(context, Nucleus_DataLanguage_StringBuffer_getBytes(context, &stringBuffer), Nucleus_DataLanguage_StringBuffer_getSize(context, &stringBuffer));
        Nucleus_DataLanguage_StringBuffer_uninitialize(context, &stringBuffer);
    }
    else
    {
        Nucleus_DataLanguage_Context_popJumpTarget(context);
        Nucleus_DataLanguage_StringBuffer_uninitialize(context, &stringBuffer);
        Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Context_getStatus(context));
    }
    return string;
}

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *self,
        bool skipComments
    )
{
    self->skipComments = skipComments;

    self->sourceIterator = Nucleus_DataLanguage_SourceIterator_create(context);
    self->underscore = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_lowLine(context));

    self->lineFeed = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_lineFeed(context));
    self->carriageReturn = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_carriageReturn(context));
    self->newLine = DL_PEGNode_createOrderedChoice(context, self->lineFeed, self->carriageReturn);

    self->space = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_space(context));
    self->characterTabulation = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_characterTabulation(context));
    self->whiteSpace = DL_PEGNode_createOrderedChoice(context, self->space, self->characterTabulation);

    self->begin = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_begin(context));
    self->end = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_end(context));

    self->plusSign = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_plusSign(context));
    self->hyphenMinus = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_hyphenMinus(context));
    self->listOpeningDelimiter = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_leftSquareBracket(context));
    self->listClosingDelimiter = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_rightSquareBracket(context));
    self->structureOpeningDelimiter = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_leftCurlyBracket(context));
    self->structureClosingDelimiter = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_rightCurlyBracket(context));
    self->colon = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_colon(context));
    self->comma = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_comma(context));
    self->solidus = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_solidus(context));
    self->reverseSolidus = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_reverseSolidus(context));
    self->quotationMark = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_quotationMark(context));
    self->fullStop = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_fullStop(context));
    self->digit = DL_PEGNode_createTerminalRange(context, Nucleus_DataLanguage_Symbol_digitZero(context),
                                                          Nucleus_DataLanguage_Symbol_digitNine(context));
    self->nonZeroDigit = DL_PEGNode_createTerminalRange(context, Nucleus_DataLanguage_Symbol_digitOne(context),
                                                                 Nucleus_DataLanguage_Symbol_digitNine(context));
    self->alphabetic = DL_PEGNode_createOrderedChoice
        (
            context,
            DL_PEGNode_createTerminalRange(context, Nucleus_DataLanguage_Symbol_latinSmallLetterA(context),
                                                    Nucleus_DataLanguage_Symbol_latinSmallLetterZ(context)),
            DL_PEGNode_createTerminalRange(context, Nucleus_DataLanguage_Symbol_latinCapitalLetterA(context),
                                                    Nucleus_DataLanguage_Symbol_latinCapitalLetterZ(context))
        );
    self->lowercaseN = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_latinSmallLetterN(context));
    self->zeroDigit = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_digitZero(context));
    self->asterisk = DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_asterisk(context));
    self->exponentIndicator = DL_PEGNode_createOrderedChoice
        (
            context,
            DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_latinSmallLetterE(context)),
            DL_PEGNode_createTerminal(context, Nucleus_DataLanguage_Symbol_latinCapitalLetterE(context))
        );
}

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *self
    )
{}

Nucleus_DataLanguage_NonNull() static void
increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ Nucleus_DataLanguage_Scanner_increment(context, scanner); }

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Symbol
current
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return Nucleus_DataLanguage_Scanner_getSymbol(context, scanner); }

Nucleus_DataLanguage_NonNull() static bool
test
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        DL_PEGNode *pegNode
    )
{ return DL_PEGNode_test(context, pegNode, scanner); }

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_SourceLocation *
getSourceLocation
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return Nucleus_DataLanguage_Scanner_getSourceLocation(context, scanner); }

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_String *
getLexeme
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end
    )
{
    return Nucleus_DataLanguage_SourceIterator_getLexeme(context, scanner->sourceIterator, begin->offset, end->offset - begin->offset);
}

Nucleus_DataLanguage_NonNull() static void
scanExponent
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    increment(context, scanner);

    if (test(context, scanner, scanner->plusSign) ||
        test(context, scanner, scanner->hyphenMinus))
    { increment(context, scanner); }

    if (!test(context, scanner, scanner->digit))
    { Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError); }

    do
    {
        increment(context, scanner);
    } while(test(context, scanner, scanner->digit));
}

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Token *
scan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    //
    if (test(context, scanner, scanner->begin))
    {
        increment(context, scanner);
    }
    //
START:
    if (test(context, scanner, scanner->end))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner),
                          *end = getSourceLocation(context, scanner);
        return Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_End, begin, end,
                               Nucleus_DataLanguage_String_create(context, "<end>", sizeof("<end>") - 1));
    }
    //
    while (test(context, scanner, scanner->newLine) || test(context, scanner, scanner->whiteSpace))
    {
        if (test(context, scanner, scanner->newLine))
        {
            Nucleus_DataLanguage_Symbol old = current(context, scanner);
            increment(context, scanner);
            if (Nucleus_DataLanguage_Symbol_equalTo(context, old, Nucleus_DataLanguage_Symbol_carriageReturn(context)) &&
                Nucleus_DataLanguage_Symbol_equalTo(context, current(context, scanner), Nucleus_DataLanguage_Symbol_lineFeed(context)))
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
        goto START;
    }
    //
    if (test(context, scanner, scanner->listOpeningDelimiter))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->listClosingDelimiter))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->structureOpeningDelimiter))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->structureClosingDelimiter))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->colon))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Colon, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->comma))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Comma, begin, end, lexeme);
        return token;
    }
    // StringLiteral
    if (test(context, scanner, scanner->quotationMark))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_SourceLocation *end = begin;
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
                    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
                }
                else if (test(context, scanner, scanner->end))
                {
                    // unclosed string literal because of end of input
                    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
                }
                else
                {
                    // unexpected symbol
                    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
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
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        lexeme = processStringLiteral(context, lexeme);
        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_StringLiteral, begin, end, lexeme);
        return token;
    }
    //
    if (test(context, scanner, scanner->underscore) || test(context, scanner, scanner->alphabetic))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        do
        {
            increment(context, scanner);
        } while (test(context, scanner, scanner->alphabetic) || test(context, scanner, scanner->digit) || test(context, scanner, scanner->underscore));
        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
        if (Nucleus_DataLanguage_String_equal(context, lexeme, Nucleus_DataLanguage_String_create(context, "true", sizeof("true") - 1)))
        {
            Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
            return Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_TrueLiteral, begin, end, lexeme);
        }
        else if (Nucleus_DataLanguage_String_equal(context, lexeme, Nucleus_DataLanguage_String_create(context, "false", sizeof("false") - 1)))
        {
            Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
            return Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_FalseLiteral, begin, end, lexeme);
        }
        else if (Nucleus_DataLanguage_String_equal(context, lexeme, Nucleus_DataLanguage_String_create(context, "void", sizeof("void") - 1)))
        {
            Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
            return Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_VoidLiteral, begin, end, lexeme);
        }
        else
        {
            Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
            return Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Name, begin, end, lexeme);
        }
    }
    //
    if (test(context, scanner, scanner->plusSign) ||
        test(context, scanner, scanner->hyphenMinus) ||
        test(context, scanner, scanner->fullStop) ||
        test(context, scanner, scanner->digit))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
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
            { Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError); }

            if (test(context, scanner, scanner->fullStop))
            {
                increment(context, scanner);

                do { increment(context, scanner); } while (test(context, scanner, scanner->digit));

                if (test(context, scanner, scanner->exponentIndicator))
                { scanExponent(context, scanner); }
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else if (test(context, scanner, scanner->exponentIndicator))
            {
                scanExponent(context, scanner);
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else
            {
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_IntegerLiteral, begin, end, lexeme);
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
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else if (test(context, scanner, scanner->exponentIndicator))
            {
                scanExponent(context, scanner);
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_RealLiteral, begin, end, lexeme);
                return token;
            }
            else
            {
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_IntegerLiteral, begin, end, lexeme);
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
            { Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError); }
            do { increment(context, scanner); } while (test(context, scanner, scanner->digit));

            // exponent?
            if (test(context, scanner, scanner->exponentIndicator))
            { scanExponent(context, scanner); }

            Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
            Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
            Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_RealLiteral, begin, end, lexeme);
            return token;
        }
    }
    //
    if (test(context, scanner, scanner->solidus))
    {
        Nucleus_DataLanguage_SourceLocation *begin = getSourceLocation(context, scanner);
        increment(context, scanner);
        if (test(context, scanner, scanner->solidus))
        {
            increment(context, scanner);
            while (!test(context, scanner, scanner->end) && !test(context, scanner, scanner->newLine))
            {
                increment(context, scanner);
            }
            if (scanner->skipComments)
            {
                return scan(context, scanner);
            }
            else
            {
                Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Comment, begin, end, lexeme);
                return token;
            }
        }
        else if (test(context, scanner, scanner->asterisk))
        {
            increment(context, scanner);
            while (true)
            {
                if (test(context, scanner, scanner->end))
                {
                    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
                }
                else if (test(context, scanner, scanner->asterisk))
                {
                    increment(context, scanner);
                    if (test(context, scanner, scanner->solidus))
                    {
                        increment(context, scanner);
                        Nucleus_DataLanguage_SourceLocation *end = getSourceLocation(context, scanner);
                        Nucleus_DataLanguage_String *lexeme = getLexeme(context, scanner, begin, end);
                        Nucleus_DataLanguage_Token *token = Nucleus_DataLanguage_Token_create(context, Nucleus_DataLanguage_Token_Kind_Comment, begin, end, lexeme);
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
            Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
        }
    }
    Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_LexicalError);
}
