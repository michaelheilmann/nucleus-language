// Copyright (c) Michael Heilmann 2018
#include "Nucleus/Interpreter/CoreContext.h"

#include <assert.h>
#include "Nucleus/Memory.h"
#include "Nucleus/Interpreter/JumpTarget.h"

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Status
Nucleus_Interpreter_CoreContext_initialize
    (
        Nucleus_Interpreter_CoreContext *context
    )
{
    if (!context) return Nucleus_Interpreter_Status_InvalidArgument;
    context->status = Nucleus_Interpreter_Status_Success;
    context->jumpTargets = NULL;
    return Nucleus_Interpreter_GC_initialize(&context->gc);
}

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_uninitialize
    (
        Nucleus_Interpreter_CoreContext *context
    )
{
    Nucleus_Interpreter_GC_uninitialize(&context->gc);
}

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_pushJumpTarget
    (
        Nucleus_Interpreter_CoreContext *context,
        Nucleus_Interpreter_JumpTarget *jumpTarget
    )
{
    assert(NULL != context && NULL != jumpTarget);
    jumpTarget->previous = context->jumpTargets;
    context->jumpTargets = jumpTarget;
}

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_popJumpTarget
    (
        Nucleus_Interpreter_CoreContext *context
    )
{
    assert(NULL != context && NULL != context->jumpTargets);
    context->jumpTargets = context->jumpTargets->previous;
}

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Status
Nucleus_Interpreter_CoreContext_getStatus
    (
        Nucleus_Interpreter_CoreContext *context
    )
{ return context->status; }

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_setStatus
    (
        Nucleus_Interpreter_CoreContext *context,
        Nucleus_Interpreter_Status status
    )
{ context->status = status; }

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() void *
Nucleus_Interpreter_CoreContext_allocate
    (
        Nucleus_Interpreter_CoreContext *context,
        size_t size
    )
{
    void *memoryBlock;
    Nucleus_Interpreter_Status status = Nucleus_Interpreter_GC_allocate(&context->gc,
                                                                        &memoryBlock,
                                                                        size);
    if (status)
    {
        Nucleus_Interpreter_CoreContext_setStatus(context, status);
        Nucleus_Interpreter_CoreContext_jump(context);
    }
    return memoryBlock;
}

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() void *
Nucleus_Interpreter_CoreContext_allocateArray
    (
        Nucleus_Interpreter_CoreContext *context,
        size_t numberOfElements,
        size_t elementSize
    )
{
    void *memoryBlock;
    Nucleus_Interpreter_Status status = Nucleus_Interpreter_GC_allocateArray(&context->gc,
                                                                             &memoryBlock,
                                                                             numberOfElements,
                                                                             elementSize);
    if (status)
    {
        Nucleus_Interpreter_CoreContext_setStatus(context, status);
        Nucleus_Interpreter_CoreContext_jump(context);
    }
    return memoryBlock;
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_deallocate
    (
        Nucleus_Interpreter_CoreContext *context,
        void *memoryBlock
    )
{ Nucleus_Interpreter_GC_deallocate(&context->gc, memoryBlock); }

Nucleus_Interpreter_NoReturn() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_jump
    (
        Nucleus_Interpreter_CoreContext *context
    )
{
    assert(NULL != context && NULL != context->jumpTargets);
    longjmp(context->jumpTargets->environment, -1);
}
