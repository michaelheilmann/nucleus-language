#pragma once

#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/PEGNode.h"
#include "Nucleus/DataLanguage/Context.h"

struct DL_Scanner
{
    DL_Object _parent;
    DL_SourceIterator *sourceIterator;
    DL_PEGNode *underscore;
    
    DL_PEGNode *lineFeed;
    DL_PEGNode *carriageReturn;
    DL_PEGNode *newLine; /* NewLine : LineFeed / CarriageReturn */

    DL_PEGNode *space;
    DL_PEGNode *characterTabulation;
    DL_PEGNode *whiteSpace; /* WhiteSpace : Space / characterTabulation */

    DL_PEGNode *end;
    DL_PEGNode *plusSign;
    DL_PEGNode *hyphenMinus;
    DL_PEGNode *listOpeningDelimiter;
    DL_PEGNode *listClosingDelimiter;
    DL_PEGNode *structureOpeningDelimiter;
    DL_PEGNode *structureClosingDelimiter;
    DL_PEGNode *colon;
    DL_PEGNode *comma;
    DL_PEGNode *solidus;
    DL_PEGNode *reverseSolidus;
    DL_PEGNode *quotationMark;
    DL_PEGNode *fullStop;
    DL_PEGNode *digit;
    DL_PEGNode *nonZeroDigit;
    DL_PEGNode *alphabetic;
    DL_PEGNode *lowercaseN;
    DL_PEGNode *zeroDigit;
    DL_PEGNode *asterisk;
    DL_PEGNode *exponentIndicator;
};

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Scanner *self
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Scanner *self
    );

DL_ReturnNonNull() DL_NonNull() static DL_String *
processStringLiteral
    (
        DL_Context *context,
        DL_String *stringLiteral
    );

DL_NonNull() static void
increment
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() static DL_Symbol
current
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() static bool
test
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_PEGNode *pegNode
    );

DL_NonNull() static DL_String *
getLexeme
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_SourceLocation *begin,
        DL_SourceLocation *end
    );

DL_NonNull() static void
scanExponent
    (
        DL_Context *context,
        DL_Scanner *scanner
    );

DL_NonNull() static DL_Token *
scan
    (
        DL_Context *context,
        DL_Scanner *scanner
    );