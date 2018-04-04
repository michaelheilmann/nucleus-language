#include "Nucleus/Interpreter/StringHeap.h"

#include "Nucleus/Interpreter/String-internal.h"
#include "Nucleus/Interpreter/Context.h"
#include "Nucleus/Interpreter/JumpTarget.h"

Nucleus_Interpreter_NonNull() static void
sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringHeap *stringHeap
    );

Nucleus_Interpreter_NonNull() static void
uninitialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringHeap *stringHeap
    );

Nucleus_Interpreter_NonNull() static void
sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringHeap *stringHeap
    )
{
    for (size_t i = 0, n = stringHeap->capacity; i < n; ++i)
    {
        Nucleus_Interpreter_String **bucket = &(stringHeap->buckets[i]);
        while (*bucket)
        {
            Nucleus_Interpreter_String *entry = *bucket; *bucket = NUCLEUS_INTERPRETER_STRING(NUCLEUS_INTERPRETER_HEAPOBJECT(entry)->next);
            Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context), entry);
            --stringHeap->size;
        }
    }
}

Nucleus_Interpreter_NonNull() static void
uninitialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringHeap *stringHeap
    )
{
    Nucleus_Interpreter_Heap_sweep(context, NUCLEUS_INTERPRETER_HEAP(stringHeap));
    Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context), stringHeap->buckets);
    stringHeap->buckets = NULL;
    stringHeap->capacity = 0;
}


Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_StringHeap_initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_StringHeap *stringHeap
    )
{
    Nucleus_Interpreter_Heap_initialize(context, NUCLEUS_INTERPRETER_HEAP(stringHeap));
    stringHeap->size = 0;
    stringHeap->capacity = 16;
    Nucleus_Interpreter_JumpTarget jt;
    Nucleus_Interpreter_CoreContext_pushJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context), &jt);
    if (!setjmp(jt.environment))
    {
        stringHeap->buckets = Nucleus_Interpreter_CoreContext_allocateArray(NUCLEUS_INTERPRETER_CORECONTEXT(context),
                                                                            16, sizeof(Nucleus_Interpreter_String *));
        Nucleus_Interpreter_CoreContext_popJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context));
    }
    else
    {
        Nucleus_Interpreter_CoreContext_popJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context));
        Nucleus_Interpreter_Context_raiseError(context, Nucleus_Interpreter_CoreContext_getStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context)));
    }
    for (size_t i = 0, n = 16; i < n; ++i)
    { stringHeap->buckets[i] = NULL; }
    NUCLEUS_INTERPRETER_HEAP(stringHeap)->sweep = NUCLEUS_INTERPRETER_HEAP_SWEEP(&sweep);
    NUCLEUS_INTERPRETER_HEAP(stringHeap)->uninitialize = NUCLEUS_INTERPRETER_HEAP_UNINITIALIZE(&uninitialize);
}
