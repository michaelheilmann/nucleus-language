// Copyright (c) 2018 Michael Heilmann
// https://github.com/nucleus-interpreter/blob/master/documentation/Nucleus_Interpreter_TypeSystem.md
#pragma once

#include "Nucleus/DataLanguage/Import-Interpreter.h"

typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

typedef enum Nucleus_DataLanguage_AST_NodeKind
{
    Nucleus_DataLanguage_AST_NodeKind_Unit,
    Nucleus_DataLanguage_AST_NodeKind_List,
    Nucleus_DataLanguage_AST_NodeKind_ListElement,
    Nucleus_DataLanguage_AST_NodeKind_Structure,
    Nucleus_DataLanguage_AST_NodeKind_StructureElement,
    Nucleus_DataLanguage_AST_NodeKind_Boolean,
    Nucleus_DataLanguage_AST_NodeKind_Integer,
    Nucleus_DataLanguage_AST_NodeKind_Real,
    Nucleus_DataLanguage_AST_NodeKind_String,
    Nucleus_DataLanguage_AST_NodeKind_Void,
} Nucleus_DataLanguage_AST_NodeKind;

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_Type *
Nucleus_DataLanguage_AST_Node_getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

typedef struct Nucleus_DataLanguage_AST_Node Nucleus_DataLanguage_AST_Node;

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createUnitNode
    (
		Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListNode
    (
		Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListElementNode
    (
		Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureNode
    (
		Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureElementNode
    (
		Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createBooleanNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Boolean booleanValue
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createIntegerNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Integer integerValue
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createRealNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Real realValue
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStringNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *stringValue
    );

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createVoidNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Void voidValue
    );
