#include "Nucleus/DataLanguage/AST/Node-private.c.i"

Nucleus_DataLanguage_AST_Node *
allocate
    (
        Nucleus_DataLanguage_Context *context
    )
{
    return
        (Nucleus_DataLanguage_AST_Node *)Nucleus_DataLanguage_Context_allocateObject
            (context, sizeof(Nucleus_DataLanguage_AST_Node));
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createUnitNode
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeUnitNode(context, self);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListNode
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeListNode(context, self);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createListElementNode
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeListElementNode(context, self);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureNode
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStructureNode(context, self);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStructureElementNode
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStructureElementNode(context, self);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createBooleanNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Boolean booleanValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeBooleanNode(context, self, booleanValue);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createIntegerNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Integer integerValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeIntegerNode(context, self, integerValue);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createRealNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Real realValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeRealNode(context, self, realValue);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createStringNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *stringValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeStringNode(context, self, stringValue);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_AST_Node *
Nucleus_DataLanguage_AST_createVoidNode
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Void voidValue
    )
{
    Nucleus_DataLanguage_AST_Node *self = allocate(context);
    initializeVoidNode(context, self, voidValue);
    ((Nucleus_DataLanguage_HeapObject *)self)->visit = (Nucleus_DataLanguage_HeapObject_Visit *)&visit;
    return self;
}
