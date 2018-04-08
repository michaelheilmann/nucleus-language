// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/Object.h"

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_lock
    (
        Nucleus_Interpreter_Object *object
    )
{ Nucleus_Interpreter_GC_Object_lock(object); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_unlock
    (
        Nucleus_Interpreter_Object *object
    )
{ Nucleus_Interpreter_GC_Object_unlock(object); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_Object_isLocked
    (
        Nucleus_Interpreter_Object *object
    )
{ return Nucleus_Interpreter_GC_Object_isLocked(object); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Finalize *
Nucleus_Interpreter_Object_getFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object
    )
{ return Nucleus_Interpreter_GC_Object_getFinalizer(context, object); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_setFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object,
        Nucleus_Interpreter_Object_Finalize *finalize
    )
{ Nucleus_Interpreter_GC_Object_setFinalizer(context, object, finalize); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Visit *
Nucleus_Interpreter_Object_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object
    )
{ return Nucleus_Interpreter_GC_Object_getVisitor(context, object); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object,
        Nucleus_Interpreter_Object_Visit *visitor
    )
{ return Nucleus_Interpreter_GC_Object_setVisitor(context, object, visitor); }
