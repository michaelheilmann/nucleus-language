#pragma once

#include "Nucleus/DataLanguage/Forward.h"

typedef struct DL_PEGNode DL_PEGNode;

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol symbol
    );

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createTerminalRange
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol first,
        Nucleus_DataLanguage_Symbol last
    );

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createOrderedChoice
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *left,
        DL_PEGNode *right
     );

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createDifference
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
     );

Nucleus_DataLanguage_NonNull() bool
DL_PEGNode_test
    (
        Nucleus_DataLanguage_Context *context,
        DL_PEGNode *self,
        Nucleus_DataLanguage_Scanner *scanner
    );
