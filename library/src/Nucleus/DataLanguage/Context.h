/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

struct DL_Context
{
    Nucleus_Interpreter_Context *context;
}; // struct DL_Context

/// @ingroup dl
/// @brief Create a context.
/// @return #DL_Status_Success on success, a non-zero status code on failure
/// @post @a *context was assigned a pointer to a @a DL_Context2 object on success.
/// @a context was not dereferenced on failure
DL_NonNull() DL_Status
DL_Context_create
    (
        DL_Context **context
    );

/// @ingroup dl
/// @brief Destroy a context.
/// @param context a pointer to a @a DL_Context2 object
/// @post The @a DL_Context2 and all its contained objects were destroyed
DL_NonNull() void
DL_Context_destroy
    (
        DL_Context *context
    );

/// @ingroup dl
/// @brief Push an error handler on the top of the stack of error handlers.
/// @param context a pointer to the @a (DL_Context2) object
/// @param errorHandler a pointer to the @a (DL_JumpTarget) object
DL_NoError() void
DL_Context_pushJumpTarget
    (
        DL_Context *context,
        DL_JumpTarget *jumpTarget
    );

/// @ingroup dl
/// @brief Pop an error handler from the stack of error handlers.
/// @param context a pointer to the @a (DL_Context) object
/// @undefined the error handler stack of the @a (DL_Context) object is empty
DL_NoError() void
DL_Context_popJumpTarget
    (
        DL_Context *context
    );

/// @ingroup dl
/// @brief Jump to the jump target on the top of the stack of jump targets.
/// @param context a pointer to the @a (DL_Context2) object
/// @undefined the jump target stack of the @a (DL_Context2) object is empty
DL_NoReturn() DL_NonNull() void
DL_Context_raiseError
    (
        DL_Context *context,
        DL_Status status
    );

/// @ingroup dl
/// @brief Get the value of the status variable of a context.
/// @param context a pointer to the @ (DL_Context2) object
/// @return the value assigned to the status variable
DL_NonNull() DL_Status
DL_Context_getStatus
    (
        DL_Context *context
    );

/// @ingroup language
/// @brief Set the value of the status variable of a context.
/// @param context a pointer to the @ (DL_Context2) object
/// @param status the value of to be assigned to the status variable
DL_NonNull() void
DL_Context_setStatus
    (
        DL_Context *context,
        DL_Status status
    );

DL_NonNull() char *
DL_Context_acquireScratchSpace
    (
        DL_Context *context,
        size_t numberOfBytes
    );

DL_NonNull() void
DL_Context_relinquishScratchSpace
    (
        DL_Context *context,
        char *bytes
    );

DL_ReturnNonNull() DL_NonNull() void *
DL_Context_allocate
    (
        DL_Context *context,
        size_t numberOfBytes
    );

DL_NonNull(1) void
DL_Context_deallocate
    (
        DL_Context *context,
        void *p
    );

DL_ReturnNonNull() DL_NonNull() DL_Object *
DL_Context_allocateObject
    (
        DL_Context *context,
        size_t numberOfBytes
    );
