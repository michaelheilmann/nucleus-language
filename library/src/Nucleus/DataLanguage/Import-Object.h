#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/Object.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

#define NUCLEUS_DATALANGUAGE_OBJECT(pointer) ((Nucleus_DataLanguage_Object *)(pointer))
typedef Nucleus_Interpreter_Object Nucleus_DataLanguage_Object;

#define NUCLEUS_DATALANGUAGE_OBJECT_TYPE(pointer) ((Nucleus_DataLanguage_Object_Type *)(pointer))
typedef Nucleus_Interpreter_Object_Type Nucleus_DataLanguage_Object_Type;

#define NUCLEUS_DATALANGUAGE_OBJECT_FINALIZE(pointer) ((Nucleus_DataLanguage_Object_Finalize *)(pointer))
#define Nucleus_DataLanguage_Object_Finalize Nucleus_Interpreter_Object_Finalize

#define NUCLEUS_DATALANGUAGE_OBJECT_VISIT(pointer) ((Nucleus_DataLanguage_Object_Visit *)(pointer))
#define Nucleus_DataLanguage_Object_Visit Nucleus_Interpreter_Object_Visit

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Type *
Nucleus_DataLanguage_getOrCreateForeignType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object_Finalize *finalize,
        Nucleus_DataLanguage_Object_Visit *visit
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Type *
Nucleus_DataLanguage_Object_getType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Type *type
    );
