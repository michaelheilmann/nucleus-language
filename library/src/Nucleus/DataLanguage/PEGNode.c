#include "Nucleus/DataLanguage/PEGNode.h"

#include "Nucleus/DataLanguage/Scanner.h"
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
    Nucleus_DataLanguage_HeapObject _parent;
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

Nucleus_DataLanguage_NonNull() DL_PEGNode *
DL_PEGNode_createTerminal
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Symbol symbol
    )
{
    DL_PEGNode *self = (DL_PEGNode *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(DL_PEGNode));
    initializeTerminal(context, self, symbol);
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

            Nucleus_DataLanguage_Symbol symbol = Nucleus_DataLanguage_Scanner_getSymbol(context, scanner);
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
