// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/PEGNode-private.h.i"

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

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
                        NULL,
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}

Nucleus_Interpreter_NonNull() static void
initializeTerminal
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        Nucleus_Interpreter_Symbol symbol
    )
{
    self->kind = DL_PEGNode_Kind_Terminal;
    self->terminal.symbol = symbol;
}

Nucleus_Interpreter_NonNull() static void
initializeTerminalRange
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        Nucleus_Interpreter_Symbol first,
        Nucleus_Interpreter_Symbol last
    )
{
    self->kind = DL_PEGNode_Kind_TerminalRange;
    self->terminalRange.first = first;
    self->terminalRange.last = last;
}

Nucleus_Interpreter_NonNull() static void
initializeOrderedChoice
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *left,
        DL_PEGNode *right
    )
{
    self->kind = DL_PEGNode_Kind_OrderedChoice;
    self->orderedChoice.left = left;
    self->orderedChoice.right = right;
}

Nucleus_Interpreter_NonNull() static void
initializeDifference
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
    )
{
    self->kind = DL_PEGNode_Kind_Difference;
    self->difference.minuend = minuend;
    self->difference.subtrahend = subtrahend;
}