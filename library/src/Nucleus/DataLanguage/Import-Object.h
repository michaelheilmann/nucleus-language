#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/Interpreter/Object.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

#define NUCLEUS_DATALANGUAGE_OBJECT(pointer) ((Nucleus_DataLanguage_Object *)(pointer))
typedef Nucleus_Interpreter_Object Nucleus_DataLanguage_Object;

#define NUCLEUS_DATALANGUAGE_OBJECT_FINALIZE(pointer) ((Nucleus_DataLanguage_Object_Finalize *)(pointer))
#define Nucleus_DataLanguage_Object_Finalize Nucleus_Interpreter_Object_Finalize

#define NUCLEUS_DATALANGUAGE_OBJECT_VISIT(pointer) ((Nucleus_DataLanguage_Object_Visit *)(pointer))
#define Nucleus_DataLanguage_Object_Visit Nucleus_Interpreter_Object_Visit

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Finalize *
Nucleus_DataLanguage_Object_getFinalizer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setFinalizer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Finalize *finalize
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Visit *
Nucleus_DataLanguage_Object_getVisitor
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setVisitor
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Visit *visitor
    );
