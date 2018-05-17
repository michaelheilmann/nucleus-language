#include "Nucleus/DataLanguage/AST/Node-private.c.i"

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_Type *
Nucleus_DataLanguage_AST_Node_getOrCreateType
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

Nucleus_DataLanguage_AST_Node *
allocate
    (
		Nucleus_Interpreter_Context *context
    )
{
    return
        (Nucleus_DataLanguage_AST_Node *)Nucleus_Interpreter_Context_allocateManaged
            (context, sizeof(Nucleus_DataLanguage_AST_Node));
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createUnitNode
    (
		Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeUnitNode(context, self);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListNode
    (
		Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeListNode(context, self);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListElementNode
    (
		Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeListElementNode(context, self);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureNode
    (
		Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStructureNode(context, self);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureElementNode
    (
		Nucleus_Interpreter_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStructureElementNode(context, self);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createBooleanNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Boolean booleanValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeBooleanNode(context, self, booleanValue);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createIntegerNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Integer integerValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeIntegerNode(context, self, integerValue);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createRealNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Real realValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeRealNode(context, self, realValue);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStringNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *stringValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStringNode(context, self, stringValue);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createVoidNode
    (
		Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Void voidValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeVoidNode(context, self, voidValue);
    Nucleus_Interpreter_Type *type = Nucleus_DataLanguage_AST_Node_getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}
