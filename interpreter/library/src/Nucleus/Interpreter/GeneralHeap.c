// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/GeneralHeap.h"

#include "Nucleus/Interpreter/GC/Object.h"
#include "Nucleus/Interpreter/Context.h"

Nucleus_Interpreter_NonNull() static void
premark
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    );

Nucleus_Interpreter_NonNull() static void
sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    );

Nucleus_Interpreter_NonNull() static void
uninitialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    );

Nucleus_Interpreter_NonNull() static void
premark
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    Nucleus_Interpreter_GC *gc = &(NUCLEUS_INTERPRETER_CORECONTEXT(context)->gc);
    for (Nucleus_Interpreter_GC_Object *object = generalHeap->objects; NULL != object; object = object->next)
    {
        if (Nucleus_Interpreter_GC_Object_isLocked(object) && Nucleus_Interpreter_GC_Object_isWhite(object))
        {
            object->gray = gc->gray; gc->gray = object;
            Nucleus_Interpreter_GC_Object_setGray(object);
        }
    }
}

Nucleus_Interpreter_NonNull() static void
sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    while (generalHeap->objects)
    {
        Nucleus_Interpreter_GC_Object *object = generalHeap->objects; generalHeap->objects = object->next;
        if (object->finalize)
        {
            object->finalize(context, object); /// @todo Remove this cast.
        }
        Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context), object);
    }
}

Nucleus_Interpreter_NonNull() static void
uninitialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    Nucleus_Interpreter_GC_Heap_sweep(context, NUCLEUS_INTERPRETER_GC_HEAP(generalHeap));
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GeneralHeap_initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    Nucleus_Interpreter_GC_Heap_initialize(context, NUCLEUS_INTERPRETER_GC_HEAP(generalHeap));
    generalHeap->objects = NULL;
    NUCLEUS_INTERPRETER_GC_HEAP(generalHeap)->premark = NUCLEUS_INTERPRETER_GC_HEAP_PREMARK(&premark);
    NUCLEUS_INTERPRETER_GC_HEAP(generalHeap)->sweep = NUCLEUS_INTERPRETER_GC_HEAP_SWEEP(&sweep);
    NUCLEUS_INTERPRETER_GC_HEAP(generalHeap)->uninitialize = NUCLEUS_INTERPRETER_GC_HEAP_UNINITIALIZE(&uninitialize);
}
