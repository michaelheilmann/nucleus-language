#pragma once

#include "Nucleus/DataLanguage/Forward.h"

typedef struct DL_PEGNode DL_PEGNode;

DL_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        DL_Context *context,
        DL_Symbol symbol
    );

DL_NonNull() DL_PEGNode *
DL_PEGNode_createTerminalRange
    (
        DL_Context *context,
        DL_Symbol first,
        DL_Symbol last
    );

DL_NonNull() DL_PEGNode *
DL_PEGNode_createOrderedChoice
    (
        DL_Context *context,
        DL_PEGNode *left,
        DL_PEGNode *right
     );

DL_NonNull() DL_PEGNode *
DL_PEGNode_createDifference
    (
        DL_Context *context,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
     );

DL_NonNull() bool
DL_PEGNode_test
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_ScannerState *scannerState
    );
