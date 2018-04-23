// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

struct Nucleus_DataLanguage_Context
{
    Nucleus_Interpreter_Context *context;
}; // struct Nucleus_DataLanguage_Context

/// @ingroup dl
/// @brief Create a context.
/// @return #Nucleus_DataLanguage_Status_Success on success, a non-zero status code on failure
/// @post @a *context was assigned a pointer to a @a Nucleus_DataLanguage_Context2 object on success.
/// @a context was not dereferenced on failure
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Status
Nucleus_DataLanguage_Context_create
    (
        Nucleus_DataLanguage_Context **context
    );

/// @ingroup dl
/// @brief Destroy a context.
/// @param context a pointer to a @a Nucleus_DataLanguage_Context2 object
/// @post The @a Nucleus_DataLanguage_Context2 and all its contained objects were destroyed
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_destroy
    (
        Nucleus_DataLanguage_Context *context
    );

/// @ingroup dl
/// @brief Push an error handler on the top of the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context2) object
/// @param errorHandler a pointer to the @a (Nucleus_DataLanguage_JumpTarget) object
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_pushJumpTarget
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_JumpTarget *jumpTarget
    );

/// @ingroup dl
/// @brief Pop an error handler from the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context) object
/// @undefined the error handler stack of the @a (Nucleus_DataLanguage_Context) object is empty
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_popJumpTarget
    (
        Nucleus_DataLanguage_Context *context
    );

/// @ingroup dl
/// @brief Jump to the jump target on the top of the stack of jump targets.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context) object
/// @undefined the jump target stack of the @a (Nucleus_DataLanguage_Context) object is empty
Nucleus_DataLanguage_NoReturn() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_jump
    (
        Nucleus_DataLanguage_Context *context
    );

/// @ingroup dl
/// @brief Jump to the jump target on the top of the stack of jump targets.
/// @param context a pointer to the @a (Nucleus_DataLanguage_Context2) object
/// @undefined the jump target stack of the @a (Nucleus_DataLanguage_Context2) object is empty
Nucleus_DataLanguage_NoReturn() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_raiseError
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Status status
    );

/// @ingroup dl
/// @brief Get the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_DataLanguage_Context2) object
/// @return the value assigned to the status variable
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Status
Nucleus_DataLanguage_Context_getStatus
    (
        Nucleus_DataLanguage_Context *context
    );

/// @ingroup language
/// @brief Set the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_DataLanguage_Context2) object
/// @param status the value of to be assigned to the status variable
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_setStatus
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Status status
    );

Nucleus_DataLanguage_NonNull() char *
Nucleus_DataLanguage_Context_acquireScratchSpace
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_relinquishScratchSpace
    (
        Nucleus_DataLanguage_Context *context,
        char *bytes
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() void *
Nucleus_DataLanguage_Context_allocate
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    );

Nucleus_DataLanguage_NonNull(1) void
Nucleus_DataLanguage_Context_deallocate
    (
        Nucleus_DataLanguage_Context *context,
        void *p
    );

Nucleus_DataLanguage_ReturnNonNull() Nucleus_DataLanguage_NonNull() Nucleus_Interpreter_Object *
Nucleus_DataLanguage_Context_allocateObject
    (
        Nucleus_DataLanguage_Context *context,
        size_t numberOfBytes
    );

#define Nucleus_DataLanguage_Context_assertNotNull(C, P) \
    if (NULL == (P)) { \
        Nucleus_DataLanguage_Context_setStatus((C), Nucleus_DataLanguage_Status_InvalidArgument); \
        Nucleus_DataLanguage_Context_jump((C)); \
    }
