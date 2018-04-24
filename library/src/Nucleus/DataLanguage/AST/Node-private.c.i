#include "Nucleus/DataLanguage/AST/Node-private.h.i"

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{}

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    )
{
    if (!g_type)
    {
        g_type = Nucleus_Interpreter_getOrCreateForeignType
            (
                context,
                NULL,
                NUCLEUS_INTERPRETER_VISITFOREIGNOBJECT(&visit),
                NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
            );
    }
    return g_type;
}

Nucleus_DataLanguage_NonNull() static void
initializeUnitNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Unit; }

Nucleus_DataLanguage_NonNull() static void
initializeListNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_List; }

Nucleus_DataLanguage_NonNull() static void
initializeListElementNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_ListElement; }

Nucleus_DataLanguage_NonNull() static void
initializeStructureNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Structure; }

Nucleus_DataLanguage_NonNull() static void
initializeStructureElementNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_StructureElement; }

Nucleus_DataLanguage_NonNull() static void
initializeBooleanNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Boolean booleanValue
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Boolean;
  node->booleanValue = booleanValue; }

Nucleus_DataLanguage_NonNull() static void
initializeIntegerNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Integer integerValue
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Integer;
  node->integerValue = integerValue; }

Nucleus_DataLanguage_NonNull() static void
initializeRealNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Real realValue
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Real;
  node->realValue = realValue; }

Nucleus_DataLanguage_NonNull() static void
initializeStringNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_String *stringValue
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  Nucleus_DataLanguage_Context_assertNotNull(context, stringValue);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_String;
  node->stringValue = stringValue; }

Nucleus_DataLanguage_NonNull() static void
initializeVoidNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_DataLanguage_Void voidValue
    )
{ Nucleus_DataLanguage_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Void;
  node->voidValue = voidValue; }
