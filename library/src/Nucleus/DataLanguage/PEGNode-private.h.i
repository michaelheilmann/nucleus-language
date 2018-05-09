// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/PEGNode.h"

#include "Nucleus/DataLanguage/Scanner.h"

static Nucleus_Interpreter_Type *g_type = NULL;

typedef enum DL_PEGNode_Kind DL_PEGNode_Kind;

enum DL_PEGNode_Kind
{
    /// @brief A terminal node.
    DL_PEGNode_Kind_Terminal,
    /// @brief A terminal range node.
    DL_PEGNode_Kind_TerminalRange,
    /// @brief An ordered choice node.
    DL_PEGNode_Kind_OrderedChoice,
    /// @brief A difference node.
    DL_PEGNode_Kind_Difference,
}; // enum DL_PEGNode_Kind

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

struct DL_PEGNode
{
    DL_PEGNode_Kind kind;
    union
    {
        struct
        {
            Nucleus_Interpreter_Symbol symbol;
        } terminal;
        struct
        {
            Nucleus_Interpreter_Symbol first;
            Nucleus_Interpreter_Symbol last;
        } terminalRange;
        struct
        {
            DL_PEGNode *left;
            DL_PEGNode *right;
        } orderedChoice;
        struct
        {
            DL_PEGNode *minuend;
            DL_PEGNode *subtrahend;
        } difference;
    };
};

Nucleus_Interpreter_NonNull() static void
initializeTerminal
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        Nucleus_Interpreter_Symbol symbol
    );

Nucleus_Interpreter_NonNull() static void
initializeTerminalRange
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        Nucleus_Interpreter_Symbol first,
        Nucleus_Interpreter_Symbol last
    );

Nucleus_Interpreter_NonNull() static void
initializeOrderedChoice
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *left,
        DL_PEGNode *right
    );

Nucleus_Interpreter_NonNull() static void
initializeDifference
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
    );
