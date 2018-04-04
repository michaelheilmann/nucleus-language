/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/Context.h"

#include "Nucleus/Interpreter/Context.h"

DL_NoError() static DL_Status
convertStatus
    (
        Nucleus_Interpreter_Status status
    );

/// @ingroup dl
/// @internal
/// @brief Initialize an @a (DL_Context2) object.
/// @param context a pointer to the @a (DL_Context2) object
/// @return #DL_Status_Success on success, a non-zero status code on failure
DL_NoError() DL_NonNull() static DL_Status
initialize
    (
        DL_Context *context
    );

/// @ingroup dl
/// @internal
/// @brief Uninitialize an @a (DL_Context2) object.
/// @param context a pointer to the @a (DL_Context2) object
DL_NoError() DL_NonNull() static void
uninitialize
    (
        DL_Context *context
    );

DL_NoError() DL_NonNull() static DL_Status
initialize
    (
        DL_Context *context
    )
{
    return convertStatus(Nucleus_Interpreter_Context_create(&context->context));
}

DL_NoError() DL_NonNull() static void
uninitialize
    (
        DL_Context *context
    )
{
    Nucleus_Interpreter_Context_destroy(context->context);
    context->context = NULL;
}

DL_NoError() static DL_Status
convertStatus
    (
        Nucleus_Interpreter_Status status
    )
{
    switch (status)
    {
        case Nucleus_Interpreter_Status_Success:
            return DL_Status_Success;
        case Nucleus_Interpreter_Status_AllocationFailed:
            return DL_Status_AllocationFailed;
        case Nucleus_Interpreter_Status_InvalidArgument:
            return DL_Status_InvalidArgument;
        case Nucleus_Interpreter_Status_UnreachableCodeReached:
            return DL_Status_UnreachableCodeReached;
        case Nucleus_Interpreter_Status_Overflow:
            return DL_Status_Overflow;
        case Nucleus_Interpreter_Status_LexicalError:
            return DL_Status_LexicalError;
        case Nucleus_Interpreter_Status_SyntacticalError:
            return DL_Status_SyntacticalError;
        case Nucleus_Interpreter_Status_SemanticalError:
            return DL_Status_SemanticalError;
        case Nucleus_Interpreter_Status_InternalError:
        default:
            return DL_Status_InternalError;
    };
}

DL_NonNull(1) DL_Status
DL_Context_create
    (
       DL_Context **context
    )
{
    if (!context)
    { return DL_Status_InvalidArgument; }
    DL_Context *temporary = malloc(sizeof(DL_Context));
    if (!temporary)
    { return DL_Status_AllocationFailed; }
    DL_Status status = initialize(temporary);
    if (status)
    {
        free(temporary);
        return status;
    }
    *context = temporary;
    return DL_Status_Success;
}

DL_NonNull() void
DL_Context_destroy
    (
        DL_Context *context
    )
{
    uninitialize(context);
    free(context);
}

DL_NoError() void
DL_Context_pushJumpTarget
    (
        DL_Context *context,
        DL_JumpTarget *jumpTarget
    )
{ Nucleus_Interpreter_CoreContext_pushJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), jumpTarget); }

DL_NoError() void
DL_Context_popJumpTarget
    (
        DL_Context *context
    )
{ Nucleus_Interpreter_CoreContext_popJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

DL_NoReturn() DL_NonNull() void
DL_Context_raiseError
    (
        DL_Context *context,
        DL_Status status
    )
{ Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), status); 
  Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

DL_NonNull() DL_Status
DL_Context_getStatus
    (
        DL_Context *context
    )
{ return Nucleus_Interpreter_CoreContext_getStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

DL_NonNull() void
DL_Context_setStatus
    (
        DL_Context *context,
        DL_Status status
    )
{ Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), status); }

DL_NonNull() char *
DL_Context_acquireScratchSpace
    (
        DL_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_Context_acquireScratchSpace(context->context, numberOfBytes); }

DL_NonNull() void
DL_Context_relinquishScratchSpace
    (
        DL_Context *context,
        char *bytes
    )
{ Nucleus_Interpreter_Context_relinquishScratchSpace(context->context, bytes); }

DL_ReturnNonNull() DL_NonNull() void *
DL_Context_allocate
    (
        DL_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_CoreContext_allocate(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), numberOfBytes); }

DL_NonNull(1) void
DL_Context_deallocate
    (
        DL_Context *context,
        void *p
    )
{ Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), p); }

DL_ReturnNonNull() DL_NonNull() DL_Object *
DL_Context_allocateObject
    (
        DL_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_Context_allocateHeapObject(context->context, numberOfBytes); }
