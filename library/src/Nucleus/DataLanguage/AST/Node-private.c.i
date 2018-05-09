#include "Nucleus/DataLanguage/AST/Node-private.h.i"

Nucleus_Interpreter_NoError() static void
finalizeArrayType
	(
	)
{ g_arrayType = NULL; }

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_Type *
getOrCreateArrayType
	(
        Nucleus_Interpreter_Context *context
	)
{
    if (!g_arrayType)
    {
        g_arrayType = Nucleus_Interpreter_getOrCreateArrayType
            (
                context,
                Nucleus_DataLanguage_AST_Node_getOrCreateType(context),
                NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeArrayType)
            );
    }
    return g_type;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{}

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_Interpreter_NonNull() static void
initializeUnitNode
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Unit; }

Nucleus_Interpreter_NonNull() static void
initializeListNode
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_List; }

Nucleus_Interpreter_NonNull() static void
initializeListElementNode
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_ListElement; }

Nucleus_Interpreter_NonNull() static void
initializeStructureNode
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Structure; }

Nucleus_Interpreter_NonNull() static void
initializeStructureElementNode
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_StructureElement; }

Nucleus_Interpreter_NonNull() static void
initializeBooleanNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Boolean booleanValue
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Boolean;
  node->booleanValue = booleanValue; }

Nucleus_Interpreter_NonNull() static void
initializeIntegerNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Integer integerValue
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Integer;
  node->integerValue = integerValue; }

Nucleus_Interpreter_NonNull() static void
initializeRealNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Real realValue
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Real;
  node->realValue = realValue; }

Nucleus_Interpreter_NonNull() static void
initializeStringNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_String *stringValue
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_String;
  node->stringValue = stringValue; }

Nucleus_Interpreter_NonNull() static void
initializeVoidNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_AST_Node *node,
        Nucleus_Interpreter_Void voidValue
    )
{ Nucleus_Interpreter_Context_assertNotNull(context, node);
  node->kind = Nucleus_DataLanguage_AST_NodeKind_Void;
  node->voidValue = voidValue; }
