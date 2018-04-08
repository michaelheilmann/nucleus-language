/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/Context.h"

#include "Nucleus/Interpreter/Context.h"

Nucleus_DataLanguage_NoError() static Nucleus_DataLanguage_Status
convertStatus
    (
        Nucleus_Interpreter_Status status
    );

/// @ingroup dl
/// @internal
/// @brief Initialize an @a (Nucleus_DataLanguage_Context2) object.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context2) object
/// @return #Nucleus_DataLanguage_Status_Success on success, a non-zero status code on failure
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Status
initialize
    (
        Nucleus_DataLanguage_Context *context
    );

/// @ingroup dl
/// @internal
/// @brief Uninitialize an @a (Nucleus_DataLanguage_Context2) object.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context2) object
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() static void
uninitialize
    (
        Nucleus_DataLanguage_Context *context
    );

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() static Nucleus_DataLanguage_Status
initialize
    (
        Nucleus_DataLanguage_Context *context
    )
{
    return convertStatus(Nucleus_Interpreter_Context_create(&context->context));
}

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() static void
uninitialize
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_Interpreter_Context_destroy(context->context);
    context->context = NULL;
}

Nucleus_DataLanguage_NoError() static Nucleus_DataLanguage_Status
convertStatus
    (
        Nucleus_Interpreter_Status status
    )
{
    switch (status)
    {
        case Nucleus_Interpreter_Status_Success:
            return Nucleus_DataLanguage_Status_Success;
        case Nucleus_Interpreter_Status_AllocationFailed:
            return Nucleus_DataLanguage_Status_AllocationFailed;
        case Nucleus_Interpreter_Status_InvalidArgument:
            return Nucleus_DataLanguage_Status_InvalidArgument;
        case Nucleus_Interpreter_Status_UnreachableCodeReached:
            return Nucleus_DataLanguage_Status_UnreachableCodeReached;
        case Nucleus_Interpreter_Status_Overflow:
            return Nucleus_DataLanguage_Status_Overflow;
        case Nucleus_Interpreter_Status_LexicalError:
            return Nucleus_DataLanguage_Status_LexicalError;
        case Nucleus_Interpreter_Status_SyntacticalError:
            return Nucleus_DataLanguage_Status_SyntacticalError;
        case Nucleus_Interpreter_Status_SemanticalError:
            return Nucleus_DataLanguage_Status_SemanticalError;
        case Nucleus_Interpreter_Status_InternalError:
        default:
            return Nucleus_DataLanguage_Status_InternalError;
    };
}

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Status
Nucleus_DataLanguage_Context_create
    (
       Nucleus_DataLanguage_Context **context
    )
{
    if (!context)
    { return Nucleus_DataLanguage_Status_InvalidArgument; }
    Nucleus_DataLanguage_Context *temporary = malloc(sizeof(Nucleus_DataLanguage_Context));
    if (!temporary)
    { return Nucleus_DataLanguage_Status_AllocationFailed; }
    Nucleus_DataLanguage_Status status = initialize(temporary);
    if (status)
    {
        free(temporary);
        return status;
    }
    *context = temporary;
    return Nucleus_DataLanguage_Status_Success;
}

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_destroy
    (
        Nucleus_DataLanguage_Context *context
    )
{
    uninitialize(context);
    free(context);
}

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_pushJumpTarget
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_JumpTarget *jumpTarget
    )
{ Nucleus_Interpreter_CoreContext_pushJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), jumpTarget); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_popJumpTarget
    (
        Nucleus_DataLanguage_Context *context
    )
{ Nucleus_Interpreter_CoreContext_popJumpTarget(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

Nucleus_DataLanguage_NoReturn() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_jump
    (
        Nucleus_DataLanguage_Context *context
    )
{ Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

Nucleus_DataLanguage_NoReturn() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_raiseError
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Status status
    )
{ Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), status);
  Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Status
Nucleus_DataLanguage_Context_getStatus
    (
        Nucleus_DataLanguage_Context *context
    )
{ return Nucleus_Interpreter_CoreContext_getStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context)); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_setStatus
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Status status
    )
{ Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), status); }

Nucleus_DataLanguage_NonNull() char *
Nucleus_DataLanguage_Context_acquireScratchSpace
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_Context_acquireScratchSpace(context->context, numberOfBytes); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_relinquishScratchSpace
    (
        Nucleus_DataLanguage_Context *context,
        char *bytes
    )
{ Nucleus_Interpreter_Context_relinquishScratchSpace(context->context, bytes); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() void *
Nucleus_DataLanguage_Context_allocate
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_CoreContext_allocate(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), numberOfBytes); }

Nucleus_DataLanguage_NonNull(1) void
Nucleus_DataLanguage_Context_deallocate
    (
        Nucleus_DataLanguage_Context *context,
        void *p
    )
{ Nucleus_Interpreter_CoreContext_deallocate(NUCLEUS_INTERPRETER_CORECONTEXT(context->context), p); }

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object *
Nucleus_DataLanguage_Context_allocateObject
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    )
{ return Nucleus_Interpreter_Context_allocateObject(context->context, numberOfBytes); }
