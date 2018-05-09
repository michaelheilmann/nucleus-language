#pragma once

#include "Nucleus/DataLanguage/AST/Node.h"

struct Nucleus_DataLanguage_AST_Node
{
    Nucleus_DataLanguage_AST_NodeKind kind;
    union
    {
        Nucleus_Interpreter_Boolean booleanValue;
        Nucleus_Interpreter_Integer integerValue;
        Nucleus_Interpreter_Real realValue;
        Nucleus_Interpreter_String *stringValue;
        Nucleus_Interpreter_Void voidValue;
    };
	Nucleus_DataLanguage_AST_Node **children;
}; // struct Nucleus_DataLanguage_AST_Node

static Nucleus_Interpreter_Type *g_arrayType = NULL;

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_NonNull() static void
initializeUnitNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NonNull() static void
initializeListNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NonNull() static void
initializeListElementNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NonNull() static void
initializeStructureNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NonNull() static void
initializeStructureElementNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    );

Nucleus_Interpreter_NonNull() static void
initializeBooleanNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Boolean booleanValue
    );

Nucleus_Interpreter_NonNull() static void
initializeIntegerNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Integer integerValue
    );

Nucleus_Interpreter_NonNull() static void
initializeRealNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Real realValue
    );

Nucleus_Interpreter_NonNull() static void
initializeStringNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_String *stringValue
    );

Nucleus_Interpreter_NonNull() static void
initializeVoidNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Void voidValue
    );
