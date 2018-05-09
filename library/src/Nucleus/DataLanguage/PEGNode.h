// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Scanner Nucleus_DataLanguage_Scanner;

typedef struct DL_PEGNode DL_PEGNode;

Nucleus_Interpreter_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Symbol symbol
    );

Nucleus_Interpreter_NonNull() DL_PEGNode *
DL_PEGNode_createTerminalRange
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Symbol first,
        Nucleus_Interpreter_Symbol last
    );

Nucleus_Interpreter_NonNull() DL_PEGNode *
DL_PEGNode_createOrderedChoice
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *left,
        DL_PEGNode *right
     );

Nucleus_Interpreter_NonNull() DL_PEGNode *
DL_PEGNode_createDifference
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
     );

Nucleus_Interpreter_NonNull() bool
DL_PEGNode_test
    (
        Nucleus_Interpreter_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Scanner *scanner
    );
