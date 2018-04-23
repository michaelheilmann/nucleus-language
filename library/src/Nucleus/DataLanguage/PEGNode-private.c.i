// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/PEGNode-private.h.i"

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
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
                        NULL,
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}

Nucleus_DataLanguage_NonNull() static void
initializeTerminal
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Symbol symbol
    )
{
    self->kind = DL_PEGNode_Kind_Terminal;
    self->terminal.symbol = symbol;
}

Nucleus_DataLanguage_NonNull() static void
initializeTerminalRange
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Symbol first,
        Nucleus_DataLanguage_Symbol last
    )
{
    self->kind = DL_PEGNode_Kind_TerminalRange;
    self->terminalRange.first = first;
    self->terminalRange.last = last;
}

Nucleus_DataLanguage_NonNull() static void
initializeOrderedChoice
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *left,
        DL_PEGNode *right
    )
{
    self->kind = DL_PEGNode_Kind_OrderedChoice;
    self->orderedChoice.left = left;
    self->orderedChoice.right = right;
}

Nucleus_DataLanguage_NonNull() static void
initializeDifference
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
    )
{
    self->kind = DL_PEGNode_Kind_Difference;
    self->difference.minuend = minuend;
    self->difference.subtrahend = subtrahend;
}