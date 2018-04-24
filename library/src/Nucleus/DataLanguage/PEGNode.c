// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/PEGNode-private.c.i"

typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol symbol
    )
{
    DL_PEGNode *self = (DL_PEGNode *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeTerminal(context, self, symbol);
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createTerminalRange
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol first,
        Nucleus_DataLanguage_Symbol last
    )
{
    DL_PEGNode *self = (DL_PEGNode *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeTerminalRange(context, self, first, last);
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createOrderedChoice
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *left,
        DL_PEGNode *right
     )
{
    DL_PEGNode *self = (DL_PEGNode *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeOrderedChoice(context, self, left, right);
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createDifference
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
     )
{
    DL_PEGNode *self = (DL_PEGNode *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeDifference(context, self, minuend, subtrahend);
    Nucleus_Interpreter_Type *type = getOrCreateType(context->context);
    Nucleus_Interpreter_Object_setType(context->context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}


Nucleus_DataLanguage_NonNull() bool
DL_PEGNode_test
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    switch (self->kind)
    {
        case DL_PEGNode_Kind_Terminal:
        {
            Nucleus_DataLanguage_SourceLocation *s = Nucleus_DataLanguage_Scanner_getSourceLocation(context, scanner);
            Nucleus_DataLanguage_Symbol symbol = Nucleus_DataLanguage_Scanner_getSymbol(context, scanner);
            bool result = Nucleus_DataLanguage_Symbol_equalTo(context, self->terminal.symbol, symbol);
            if (!result)
            {
                Nucleus_DataLanguage_Scanner_setSourceLocation(context, scanner, s);
            }
            return result;
        }
        case DL_PEGNode_Kind_TerminalRange:
        {
            Nucleus_DataLanguage_SourceLocation *s = Nucleus_DataLanguage_Scanner_getSourceLocation(context, scanner);
            Nucleus_DataLanguage_Symbol symbol = Nucleus_DataLanguage_Scanner_getSymbol(context, scanner);
            bool result = Nucleus_DataLanguage_Symbol_lowerThanOrEqualTo(context, self->terminalRange.first, symbol)
                       && Nucleus_DataLanguage_Symbol_lowerThanOrEqualTo(context, symbol, self->terminalRange.last);
            if (!result)
            {
                Nucleus_DataLanguage_Scanner_setSourceLocation(context, scanner, s);
            }
            return result;
        }
        case DL_PEGNode_Kind_OrderedChoice:
            return DL_PEGNode_test(context, self->orderedChoice.left, scanner)
                || DL_PEGNode_test(context, self->orderedChoice.right, scanner);
        case DL_PEGNode_Kind_Difference:
        {
            Nucleus_DataLanguage_SourceLocation *s = Nucleus_DataLanguage_Scanner_getSourceLocation(context, scanner);

            bool result;
            result = DL_PEGNode_test(context, self->difference.minuend, scanner);
            if (!result)
            {
                // the failing minuend has restored the state already
                return false;
            }
            // backup the state after succeeding minuend
            Nucleus_DataLanguage_SourceLocation *s2 = Nucleus_DataLanguage_Scanner_getSourceLocation(context, scanner);
            
            // restore before state before succeeding minuend
            Nucleus_DataLanguage_Scanner_setSourceLocation(context, scanner, s);
            
            result = DL_PEGNode_test(context, self->difference.subtrahend, scanner);
            if (result)
            {
                // restore state before succeeding minuend
                Nucleus_DataLanguage_Scanner_setSourceLocation(context, scanner, s);
                return false;
            }
            // minuend succeeded, subtrahend failed, restore state after minuend
            Nucleus_DataLanguage_Scanner_setSourceLocation(context, scanner, s2);
            return true;
        }
        default:
            Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_UnreachableCodeReached);
    };
}
