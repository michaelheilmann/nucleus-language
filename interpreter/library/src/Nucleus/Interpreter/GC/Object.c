// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/GC/Object.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_lock
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ object->lockCount++; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_unlock
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ object->lockCount--; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isLocked
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ return 0 != object->lockCount; }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_GC_Object_Finalize *
Nucleus_Interpreter_GC_Object_getFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object
    )
{ return object->finalize; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object,
        Nucleus_Interpreter_GC_Object_Finalize *finalize
    )
{ object->finalize = finalize; }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_GC_Object_Visit *
Nucleus_Interpreter_GC_Object_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object
    )
{ return object->visit; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object,
        Nucleus_Interpreter_GC_Object_Visit *visit
    )
{ object->visit = visit; }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isGray
    (
        const Nucleus_Interpreter_GC_Object *object
    )
{ return Nucleus_Interpreter_GC_Color_Gray == (object->flags & Nucleus_Interpreter_GC_Color_Gray); }

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setGray
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ object->flags = Nucleus_Interpreter_GC_Color_Gray; }

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isBlack
    (
        const Nucleus_Interpreter_GC_Object *object
    )
{ return Nucleus_Interpreter_GC_Color_Black == (object->flags & Nucleus_Interpreter_GC_Color_Black); }

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setBlack
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ object->flags = Nucleus_Interpreter_GC_Color_Black; }

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isWhite
    (
        const Nucleus_Interpreter_GC_Object *object
    )
{ return Nucleus_Interpreter_GC_Color_White == (object->flags & Nucleus_Interpreter_GC_Color_White); }

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setWhite
    (
        Nucleus_Interpreter_GC_Object *object
    )
{ object->flags = Nucleus_Interpreter_GC_Color_White; }
