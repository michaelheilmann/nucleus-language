#pragma once

#include "Nucleus/DataLanguage/AST/Node.h"
#include "Nucleus/DataLanguage/Context.h"

struct Nucleus_DataLanguage_AST_Node
{
    Nucleus_DataLanguage_AST_NodeKind kind;
    union
    {
        Nucleus_DataLanguage_Boolean booleanValue;
        Nucleus_DataLanguage_Integer integerValue;
        Nucleus_DataLanguage_Real realValue;
        Nucleus_DataLanguage_String *stringValue;
        Nucleus_DataLanguage_Void voidValue;
    };
}; // struct Nucleus_DataLanguage_AST_Node

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_DataLanguage_NonNull() static void
initializeUnitNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_DataLanguage_NonNull() static void
initializeListNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_DataLanguage_NonNull() static void
initializeListElementNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_DataLanguage_NonNull() static void
initializeStructureNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_DataLanguage_NonNull() static void
initializeStructureElementNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_DataLanguage_NonNull() static void
initializeBooleanNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Boolean booleanValue
    );

Nucleus_DataLanguage_NonNull() static void
initializeIntegerNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Integer integerValue
    );

Nucleus_DataLanguage_NonNull() static void
initializeRealNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Real realValue
    );

Nucleus_DataLanguage_NonNull() static void
initializeStringNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_String *stringValue
    );

Nucleus_DataLanguage_NonNull() static void
initializeVoidNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Void voidValue
    );
