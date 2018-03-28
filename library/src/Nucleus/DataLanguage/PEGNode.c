#include "Nucleus/DataLanguage/PEGNode.h"

#include "Nucleus/Language.h"
#include "Nucleus/DataLanguage/ScannerState.h"
#include "Nucleus/DataLanguage/Context.h"


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

struct DL_PEGNode
{
    DL_Object _parent;
    DL_PEGNode_Kind kind;
    union
    {
        struct
        {
            DL_Symbol symbol;
        } terminal;
        struct
        {
            DL_Symbol first;
            DL_Symbol last;
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

DL_NonNull() static void
initializeTerminal
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_Symbol symbol
    )
{
    self->kind = DL_PEGNode_Kind_Terminal;
    self->terminal.symbol = symbol;
}

DL_NonNull() static void
initializeTerminalRange
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_Symbol first,
        DL_Symbol last
    )
{
    self->kind = DL_PEGNode_Kind_TerminalRange;
    self->terminalRange.first = first;
    self->terminalRange.last = last;
}

DL_NonNull() static void
initializeOrderedChoice
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *left,
        DL_PEGNode *right
    )
{
    self->kind = DL_PEGNode_Kind_OrderedChoice;
    self->orderedChoice.left = left;
    self->orderedChoice.right = right;
}

DL_NonNull() static void
initializeDifference
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
    )
{
    self->kind = DL_PEGNode_Kind_Difference;
    self->difference.minuend = minuend;
    self->difference.subtrahend = subtrahend;
}

DL_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        DL_Context *context,
        DL_Symbol symbol
    )
{
    DL_PEGNode *self = (DL_PEGNode *)DL_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeTerminal(context, self, symbol);
    return self;
}

DL_NonNull() DL_PEGNode *
DL_PEGNode_createTerminalRange
    (
        DL_Context *context,
        DL_Symbol first,
        DL_Symbol last
    )
{
    DL_PEGNode *self = (DL_PEGNode *)DL_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeTerminalRange(context, self, first, last);
    return self;
}

DL_NonNull() DL_PEGNode *
DL_PEGNode_createOrderedChoice
    (
        DL_Context *context,
        DL_PEGNode *left,
        DL_PEGNode *right
     )
{
    DL_PEGNode *self = (DL_PEGNode *)DL_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeOrderedChoice(context, self, left, right);
    return self;
}

DL_NonNull() DL_PEGNode *
DL_PEGNode_createDifference
    (
        DL_Context *context,
        DL_PEGNode *minuend,
        DL_PEGNode *subtrahend
     )
{
    DL_PEGNode *self = (DL_PEGNode *)DL_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeDifference(context, self, minuend, subtrahend);
    return self;
}


DL_NonNull() bool
DL_PEGNode_test
    (
        DL_Context *context,
        DL_PEGNode *self,
        DL_ScannerState *scannerState
    )
{
    switch (self->kind)
    {
        case DL_PEGNode_Kind_Terminal:
        {
            DL_SourceLocation *s = DL_ScannerState_getSourceLocation(context, scannerState);
            DL_Symbol symbol = DL_ScannerState_getSymbol(context, scannerState);
            bool result = DL_Symbol_equal(context, self->terminal.symbol, symbol);
            if (!result)
            {
                DL_ScannerState_setSourceLocation(context, scannerState, s);
            }
            return result;
        }
        case DL_PEGNode_Kind_TerminalRange:
        {
            DL_SourceLocation *s = DL_ScannerState_getSourceLocation(context, scannerState);
            DL_Symbol symbol = DL_ScannerState_getSymbol(context, scannerState);
            bool result = DL_Symbol_lowerOrEqual(context, self->terminalRange.first, symbol)
                       && DL_Symbol_lowerOrEqual(context, symbol, self->terminalRange.last);
            if (!result)
            {
                DL_ScannerState_setSourceLocation(context, scannerState, s);
            }
            return result;
        }
        case DL_PEGNode_Kind_OrderedChoice:
            return DL_PEGNode_test(context, self->orderedChoice.left, scannerState)
                || DL_PEGNode_test(context, self->orderedChoice.right, scannerState);
        case DL_PEGNode_Kind_Difference:
        {
            DL_SourceLocation *s = DL_ScannerState_getSourceLocation(context, scannerState);

            DL_Symbol symbol = DL_ScannerState_getSymbol(context, scannerState);
            bool result;
            result = DL_PEGNode_test(context, self->difference.minuend, scannerState);
            if (!result)
            {
                // the failing minuend has restored the state already
                return false;
            }
            // backup the state after succeeding minuend
            DL_SourceLocation *s2 = DL_ScannerState_getSourceLocation(context, scannerState);
            
            // restore before state before succeeding minuend
            DL_ScannerState_setSourceLocation(context, scannerState, s);
            
            result = DL_PEGNode_test(context, self->difference.subtrahend, scannerState);
            if (result)
            {
                // restore state before succeeding minuend
                DL_ScannerState_setSourceLocation(context, scannerState, s);
                return false;
            }
            // minuend succeeded, subtrahend failed, restore state after minuend
            DL_ScannerState_setSourceLocation(context, scannerState, s2);
            return true;
        }
        default:
            DL_Context_raiseError(context, DL_Status_UnreachableCodeReached);
    };
}
