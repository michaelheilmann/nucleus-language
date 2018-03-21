/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Annotations.h"
#include "Nucleus/Language/ErrorHandler.h"
#include "Nucleus/Language/HeapObject.h"
#include "Nucleus/Language/Status.h"
#include <stddef.h>

#define Nucleus_Language_Context_assertNotNull(C, A) \
    if (!(A)) { \
        Nucleus_Language_Context_raiseError((C), Nucleus_Language_Status_InvalidArgument); \
    }

/// @ingroup language
/// @brief Create a context.
/// @return #Nucleus_Language_Status_Success on success, a non-zero status code on failure
/// @post @a *context was assigned a pointer to a @a Nucleus_Language_Context object on success.
/// @a context was not dereferenced on failure
Nucleus_Language_NonNull() Nucleus_Language_Status
Nucleus_Language_Context_create
    (
        Nucleus_Language_Context **context
    );

/// @ingroup language
/// @brief Destroy a context.
/// @param context a pointer to a @a Nucleus_Language_Context object
/// @post The @a Nucleus_Language_Context and all its contained objects were destroyed
Nucleus_Language_NonNull() void
Nucleus_Language_Context_destroy
    (
        Nucleus_Language_Context *context
    );

/// @ingroup language
/// @brief Push an error handler on the top of the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_Language_Context) object
/// @param errorHandler a pointer to the @a (Nucleus_Language_ErrorHandler) object
Nucleus_Language_NoError() void
Nucleus_Language_Context_pushErrorHandler
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_ErrorHandler *errorHandler
    );

/// @ingroup language
/// @brief Pop an error handler from the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_Language_Context) object
/// @undefined the error handler stack of the @a (Nucleus_Language_Context) object is empty
Nucleus_Language_NoError() void
Nucleus_Language_Context_popErrorHandler
    (
        Nucleus_Language_Context *context
    );

/// @ingroup language
/// @brief Jump to the jump target on the top of the stack of jump targets.
/// @param context a pointer to the @a (Nucleus_Language_Context) object
/// @undefined the jump target stack of the @a (Nucleus_Language_Context) object is empty
Nucleus_Language_NoReturn() Nucleus_Language_NonNull() void
Nucleus_Language_Context_raiseError
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Status status
    );

/// @ingroup language
/// @brief Get the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_Language_Context) object
/// @return the value assigned to the status variable
Nucleus_Language_NonNull() Nucleus_Language_Status
Nucleus_Language_Context_getStatus
    (
        Nucleus_Language_Context *context
    );

/// @ingroup language
/// @brief Set the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_Language_Context) object
/// @param status the value of to be assigned to the status variable
Nucleus_Language_NonNull() void
Nucleus_Language_Context_setStatus
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Status status
    );

Nucleus_Language_NonNull() char *
Nucleus_Language_Context_acquireScratchSpace
    (
        Nucleus_Language_Context *context,
        size_t numberOfBytes
    );

Nucleus_Language_NonNull() void
Nucleus_Language_Context_relinquishScratchSpace
    (
        Nucleus_Language_Context *context,
        char *bytes
    );

// Allocate raw memory
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() void *
Nucleus_Language_Context_allocate
    (
        Nucleus_Language_Context *context,
        size_t size
    );

// Allocate raw memory
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() void *
Nucleus_Language_Context_allocateArray
    (
        Nucleus_Language_Context *context,
        size_t numberOfElements,
        size_t elementSize
    );

// Deallocate raw memory
Nucleus_Language_NonNull(1) void
Nucleus_Language_Context_deallocate
    (
        Nucleus_Language_Context *context,
        void *p
    );

// Allocate object
Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_Object *
Nucleus_Language_Context_allocateObject
    (
        Nucleus_Language_Context *context,
        size_t numberOfBytes
    );
