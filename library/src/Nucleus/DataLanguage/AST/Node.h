// Copyright (c) Michael Heilmann 2018
// https://github.com/nucleus-interpreter/blob/master/documentation/Nucleus_Interpreter_TypeSystem.md
#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-Boolean.h"

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

typedef struct Nucleus_DataLanguage_AST_Node Nucleus_DataLanguage_AST_Node;

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createUnitNode
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListNode
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListElementNode
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureNode
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureElementNode
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createBooleanNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Boolean booleanValue
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createIntegerNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Integer integerValue
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createRealNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Real realValue
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStringNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *stringValue
    );

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createVoidNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Void voidValue
    );
