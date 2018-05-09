// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Token.h"
#include "Nucleus/DataLanguage/SourceIterator.h"
#include "Nucleus/DataLanguage/PEGNode.h"

struct Nucleus_DataLanguage_Scanner
{
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

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *self,
        bool skipComments
    );

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *self
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

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_String *
processStringLiteral
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *stringLiteral
    );

Nucleus_Interpreter_NonNull() static void
increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Symbol
current
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() static bool
test
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        DL_PEGNode *pegNode
    );

Nucleus_Interpreter_NoReturn() Nucleus_Interpreter_NonNull() static void
raiseLexicalError
	(
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
	);

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_SourceLocation *
getSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_String *
getLexeme
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end
    );

Nucleus_Interpreter_NonNull() static void
scanExponent
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );

Nucleus_Interpreter_NonNull() static Nucleus_DataLanguage_Token *
scan
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    );
