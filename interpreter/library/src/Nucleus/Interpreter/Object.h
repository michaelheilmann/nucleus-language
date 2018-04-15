// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/Interpreter/GC/Object.h"
#include "Nucleus/Interpreter/GC/Type_Finalize.h"

typedef Nucleus_Interpreter_GC_Type Nucleus_Interpreter_Object_Type;
typedef Nucleus_Interpreter_GC_Object Nucleus_Interpreter_Object;

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_lock
    (
        Nucleus_Interpreter_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_unlock
    (
        Nucleus_Interpreter_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_Object_isLocked
    (
        Nucleus_Interpreter_Object *object
    );

typedef struct Nucleus_Interpreter_GC_Type Nucleus_Interpreter_Object_Type;

#define Nucleus_Interpreter_Object_Finalize Nucleus_Interpreter_GC_Finalize

#define Nucleus_Interpreter_Object_Visit Nucleus_Interpreter_GC_Visit

#define Nucleus_Interpreter_Object_Type_Finalize Nucleus_Interpreter_GC_Type_Finalize

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Type *
Nucleus_Interpreter_Object_getOrCreateForeignType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object_Finalize *finalize,
        Nucleus_Interpreter_Object_Visit *visit,
        Nucleus_Interpreter_Object_Type_Finalize *finalizeType
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Type *
Nucleus_Interpreter_Object_getType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_setType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object,
        Nucleus_Interpreter_Object_Type *type
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Visit *
Nucleus_Interpreter_Object_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object,
        Nucleus_Interpreter_Object_Visit *visitor
    );
