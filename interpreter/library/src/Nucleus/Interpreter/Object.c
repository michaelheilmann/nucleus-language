// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/Object.h"

#include "Nucleus/Interpreter/GC/Type.h"
#include "Nucleus/Interpreter/CoreContext.h"
#include "Nucleus/Interpreter/Context.h"

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_lock
    (
        Nucleus_Interpreter_Object *object
    )
{ Nucleus_Interpreter_GC_Tag_lock(address2Tag(object)); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_unlock
    (
        Nucleus_Interpreter_Object *object
    )
{ Nucleus_Interpreter_GC_Tag_unlock(address2Tag(object)); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_Object_isLocked
    (
        Nucleus_Interpreter_Object *object
    )
{ return Nucleus_Interpreter_GC_Tag_isLocked(address2Tag(object)); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Type *
Nucleus_Interpreter_Object_getOrCreateForeignType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object_Finalize *finalize,
        Nucleus_Interpreter_Object_Visit *visit,
        Nucleus_Interpreter_Object_Type_Finalize *finalizeType
    )
{
    Nucleus_Interpreter_Status status;
    Nucleus_Interpreter_GC_Type *type;
    status = Nucleus_Interpreter_GC_getOrCreateForeignType(&NUCLEUS_INTERPRETER_CORECONTEXT(context)->gc,
                                                           &type, finalize, visit, finalizeType);
    if (status)
    {
        Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context), status);
        Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(context));
    }
    return type;
}

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Object_Type *
Nucleus_Interpreter_Object_getType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object
    )
{ return Nucleus_Interpreter_GC_Tag_getType(context, address2Tag(object)); }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Object_setType
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Object *object,
        Nucleus_Interpreter_Object_Type *type
    )
{ Nucleus_Interpreter_GC_Tag_setType(context, address2Tag(object), type); }
