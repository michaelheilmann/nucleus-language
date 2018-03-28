/// @file Nucleus/Language/FeatureLevelOne_Context.c
/// @brief Definitions of a @a (Nucleus_Language_FeatureLevelOne_Context) object.
/// @author Michael Heilmann
#include "Nucleus/Language/FeatureLevelOne_Context.h"

#include <assert.h>
#include "Nucleus/Memory.h"
#include "Nucleus/Language/FeatureLevelOne_ErrorHandler.h"

Nucleus_Language_FeatureLevelOne_NonNull() Nucleus_Language_FeatureLevelOne_Status
Nucleus_Language_FeatureLevelOne_Context_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    )
{
    if (!context) return Nucleus_Language_FeatureLevelOne_Status_InvalidArgument;
    context->status = Nucleus_Language_FeatureLevelOne_Status_Success;
    context->errorHandlers = NULL;
    return Nucleus_Language_FeatureLevelOne_Status_Success;
}

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    )
{}

Nucleus_Language_FeatureLevelOne_NoError() void
Nucleus_Language_FeatureLevelOne_Context_pushErrorHandler
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_ErrorHandler *errorHandler
    )
{
    assert(NULL != context && NULL != errorHandler);
    errorHandler->previous = context->errorHandlers;
    context->errorHandlers = errorHandler;
}

Nucleus_Language_FeatureLevelOne_NoError() void
Nucleus_Language_FeatureLevelOne_Context_popErrorHandler
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    )
{
    assert(NULL != context && NULL != context->errorHandlers);
    context->errorHandlers = context->errorHandlers->previous;
}

Nucleus_Language_FeatureLevelOne_NoReturn() Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_raiseError
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Status status
    )
{
    assert(NULL != context && NULL != context->errorHandlers);
    context->status = status;
    longjmp(context->errorHandlers->environment, -1);
}

Nucleus_Language_FeatureLevelOne_NonNull() Nucleus_Language_FeatureLevelOne_Status
Nucleus_Language_FeatureLevelOne_Context_getStatus
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    )
{
    assert(NULL != context);
    return context->status;
}

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_setStatus
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Status status
    )
{
    assert(NULL != context);
    context->status = status;
}

Nucleus_Language_FeatureLevelOne_ReturnNonNull() Nucleus_Language_FeatureLevelOne_NonNull() void *
Nucleus_Language_FeatureLevelOne_Context_allocate
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        size_t size
    )
{
    void *memoryBlock = NULL;
    Nucleus_Status status = Nucleus_allocateMemory(&memoryBlock, size);
    if (status)
    {
        switch (status)
        {
        case Nucleus_Status_InvalidArgument:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_InvalidArgument);
        case Nucleus_Status_AllocationFailed:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_AllocationFailed);
        case Nucleus_Status_Overflow:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_Overflow);
        default:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_UnreachableCodeReached);
        };
    }
    Nucleus_fillMemory(memoryBlock, 0, size);
    return memoryBlock;
}

Nucleus_Language_FeatureLevelOne_ReturnNonNull() Nucleus_Language_FeatureLevelOne_NonNull() void *
Nucleus_Language_FeatureLevelOne_Context_allocateArray
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        size_t numberOfElements,
        size_t elementSize
    )
{
    void *memoryBlock = NULL;
    Nucleus_Status status = Nucleus_allocateArrayMemory(&memoryBlock, numberOfElements, elementSize);
    if (status)
    {
        switch (status)
        {
        case Nucleus_Status_InvalidArgument:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_InvalidArgument);
        case Nucleus_Status_AllocationFailed:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_AllocationFailed);
        case Nucleus_Status_Overflow:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_Overflow);
        default:
            Nucleus_Language_FeatureLevelOne_Context_raiseError(context, Nucleus_Language_FeatureLevelOne_Status_UnreachableCodeReached);
        };
    }
    Nucleus_fillArrayMemory(memoryBlock, 0, numberOfElements, elementSize);
    return memoryBlock;
}

Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_deallocate
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        void *memoryBlock
    )
{ Nucleus_deallocateMemory(memoryBlock); }
