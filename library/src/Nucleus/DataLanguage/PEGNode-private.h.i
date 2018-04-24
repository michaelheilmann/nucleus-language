// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/PEGNode.h"

#include "Nucleus/DataLanguage/Scanner.h"
#include "Nucleus/DataLanguage/Context.h"

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

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() static Nucleus_Interpreter_Type *
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
            Nucleus_DataLanguage_Symbol symbol;
        } terminal;
        struct
        {
            Nucleus_DataLanguage_Symbol first;
            Nucleus_DataLanguage_Symbol last;
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

Nucleus_DataLanguage_NonNull() static void
initializeTerminal
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Symbol symbol
    );

Nucleus_DataLanguage_NonNull() static void
initializeTerminalRange
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Symbol first,
        Nucleus_DataLanguage_Symbol last
    );

Nucleus_DataLanguage_NonNull() static void
initializeOrderedChoice
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *left,
        DL_PEGNode *right
    );

Nucleus_DataLanguage_NonNull() static void
initializeDifference
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
    );
