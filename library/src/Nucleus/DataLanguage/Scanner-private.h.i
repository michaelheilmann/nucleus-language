#pragma once

#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/PEGNode.h"
#include "Nucleus/DataLanguage/Context.h"

struct Nucleus_DataLanguage_Scanner
{
    Nucleus_DataLanguage_Object _parent;
    Nucleus_DataLanguage_SourceIterator *sourceIterator;

    bool skipComments;

    DL_PEGNode *underscore;
    
    DL_PEGNode *lineFeed;
    DL_PEGNode *carriageReturn;
    DL_PEGNode *newLine; /* NewLine : LineFeed / CarriageReturn */

    DL_PEGNode *space;
    DL_PEGNode *characterTabulation;
    DL_PEGNode *whiteSpace; /* WhiteSpace : Space / characterTabulation */

    DL_PEGNode *begin;
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

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *self,
        bool skipComments
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *self
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_String *
processStringLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *stringLiteral
    );

Nucleus_DataLanguage_NonNull() static void
increment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Symbol
current
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() static bool
test
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        DL_PEGNode *pegNode
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_String *
getLexeme
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end
    );

Nucleus_DataLanguage_NonNull() static void
scanExponent
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Token *
scan
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );
