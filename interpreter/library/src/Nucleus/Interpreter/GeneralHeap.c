#include "Nucleus/Interpreter/GeneralHeap.h"

#include "Nucleus/Interpreter/HeapObject.h"
#include "Nucleus/Interpreter/Context.h"

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
sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    while (generalHeap->objects)
    {
        Nucleus_Interpreter_HeapObject *object = generalHeap->objects; generalHeap->objects = object->next;
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
    Nucleus_Interpreter_Heap_sweep(context, NUCLEUS_INTERPRETER_HEAP(generalHeap));
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GeneralHeap_initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GeneralHeap *generalHeap
    )
{
    Nucleus_Interpreter_Heap_initialize(context, NUCLEUS_INTERPRETER_HEAP(generalHeap));
    generalHeap->objects = NULL;
    NUCLEUS_INTERPRETER_HEAP(generalHeap)->sweep = NUCLEUS_INTERPRETER_HEAP_SWEEP(&sweep);
    NUCLEUS_INTERPRETER_HEAP(generalHeap)->uninitialize = NUCLEUS_INTERPRETER_HEAP_UNINITIALIZE(&uninitialize);
}
