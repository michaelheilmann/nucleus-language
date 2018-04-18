// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/GeneralHeap.h"

#include "Nucleus/Interpreter/GC/Object.h"
#include "Nucleus/Interpreter/GC/Type.h"
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
    for (Nucleus_Interpreter_GC_Tag *tag = generalHeap->objects; NULL != tag; tag = tag->next)
    {
        if (Nucleus_Interpreter_GC_Tag_isLocked(tag) && Nucleus_Interpreter_GC_Tag_isWhite(tag))
        {
            tag->gray = gc->gray; gc->gray = tag;
            Nucleus_Interpreter_GC_Tag_setGray(tag);
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
        Nucleus_Interpreter_GC_Tag *tag = generalHeap->objects; generalHeap->objects = tag->next;
        Nucleus_Interpreter_GC_Type *type = Nucleus_Interpreter_GC_Tag_getType(context, tag);
        if (type)
        {
            if (Nucleus_Interpreter_GC_Type_isForeign(type))
            {
                if (type->foreignType.finalize)
                {
                    type->foreignType.finalize(context, tag2Address(tag));
                }
                Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context), tag);
            }
            else if (Nucleus_Interpreter_GC_Type_isArray(type))
            {
                Nucleus_Interpreter_GC_ArrayTag *arrayTag = tag2ArrayTag(tag);
                Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context), arrayTag);
            }
        }
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
