// Copyright (c) Michael Heilmann 2018
// Provides getting/setting a status, pushing/popping/jumping to jump targets, and memory allocations/deallocations.
#pragma once

#include "Nucleus/Interpreter/Annotations.h"
#include "Nucleus/Interpreter/Status.h"
#include "Nucleus/Interpreter/GC.h"
#include <stddef.h> /// @todo For size_t. Remove this.

// Forward declaration.
typedef struct Nucleus_Interpreter_JumpTarget Nucleus_Interpreter_JumpTarget;

/// @ingroup interpreter
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_CoreContext) or derived pointer into a @a (Nucleus_Interpreter_CoreContext) pointer
/// @param pointer a @a (Nucleus_Interpreter_CoreContext) or derived pointer
#define NUCLEUS_INTERPRETER_CORECONTEXT(pointer) ((Nucleus_Interpreter_CoreContext *)(pointer))

/// @ingroup interpreter
/// @internal
/// @brief Core context which provides
/// - setting/getting the context status,
/// - pushing/popping jump targets,
/// - jumping to jump targets, and
/// - raw memory allocations and deallocations.
/// This is the required functionality derived contexts to add heaps and stack.
typedef struct Nucleus_Interpreter_CoreContext Nucleus_Interpreter_CoreContext;

struct Nucleus_Interpreter_CoreContext
{
    /// @brief A null pointer or a pointer to the last element of the singly-linked list stack of @a (Nucleus_Interpreter_JumpTarget) objects.
    Nucleus_Interpreter_JumpTarget *jumpTargets;
    /// @brief The status variable of this context.
    /// Default value is Nucleus_Language_FeatureLevelOne_Status_Success.
    Nucleus_Interpreter_Status status;
    /// @brief The garbage collector.
    Nucleus_Interpreter_GC gc;
}; // struct Nucleus_Interpreter_CoreContext

/// @ingroup interpreter
/// @internal
/// @brief Initialize this @a (Nucleus_Interpreter_CoreContext) object.
/// @param context a pointer to an uninitialized @a (Nucleus_Interpreter_CoreContext) object
/// @return #Nucleus_Interpreter_Status_Success on success, a non-zero status code on success
Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Status
Nucleus_Interpreter_CoreContext_initialize
    (
        Nucleus_Interpreter_CoreContext *context
    );

/// @ingroup interpreter
/// @internal
/// @brief Uninitialize this @a (Nucleus_Interpreter_CoreContext) object.
/// @param context a pointer to an initialized @a (Nucleus_Interpreter_CoreContext) object
Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_uninitialize
    (
        Nucleus_Interpreter_CoreContext *context
    );

/// @ingroup language
/// @internal
/// @brief Push a jump target on the top of the stack of jump targets of a @a (Nucleus_Interpreter_CoreContext).
/// @param context a pointer to the @a (Nucleus_Interpreter_CoreContext) object
/// @param errorHandler a pointer to the @a (Nucleus_Interpreter_JumpTarget) object
Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_pushJumpTarget
    (
        Nucleus_Interpreter_CoreContext *context,
        Nucleus_Interpreter_JumpTarget *jumpTarget
    );

/// @ingroup interpreter
/// @internal
/// @brief Pop a jump target from the stack of jump targets of a @a (Nucleus_Interpreter_CoreContext).
/// @param context a pointer to the @a (Nucleus_Interpreter_CoreContext) object
/// @undefined the error handler stack of the @a (Nucleus_Interpreter_CoreContext) object is empty
Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_popJumpTarget
    (
        Nucleus_Interpreter_CoreContext *context
    );

/// @ingroup interpreter
/// @internal
/// @brief Get the value of the status variable of a @a (Nucleus_Interpreter_CoreContext).
/// @param context a pointer to the @ (Nucleus_Interpreter_CoreContext) object
/// @return the value assigned to the status variable
Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Status
Nucleus_Interpreter_CoreContext_getStatus
    (
        Nucleus_Interpreter_CoreContext *context
    );

/// @ingroup interpreter
/// @internal
/// @brief Set the value of the status variable of a @a (Nucleus_Interpreter_CoreContext).
/// @param context a pointer to the @ (Nucleus_Interpreter_CoreContext) object
/// @param status the value of to be assigned to the status variable
Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_setStatus
    (
        Nucleus_Interpreter_CoreContext *context,
        Nucleus_Interpreter_Status status
    );

/// @ingroup interpreter
/// @internal
/// @brief Allocate an unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Interpreter_CoreContext) object
/// @param size the size, in Bytes, of the memory block to allocate. @a 0 is a valid size.
/// @return a pointer to the beginning of the unmanaged memory block of the size @a numberOfBytes
Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() void *
Nucleus_Interpreter_CoreContext_allocate
    (
        Nucleus_Interpreter_CoreContext *context,
        size_t size
    );

/// @ingroup interpreter
/// @internal
/// @brief Allocate an unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Interpreter_CoreContext) object
/// @param numberOfElements, elementSize the size, in Bytes, of the memory block to allocate. @a 0 is a valid size.
/// @return a pointer to the beginning of the unmanaged memory block of the size @a numberOfBytes
Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() void *
Nucleus_Interpreter_CoreContext_allocateArray
    (
        Nucleus_Interpreter_CoreContext *context,
        size_t numberOfElements,
        size_t elementSize
    );

/// @ingroup interpreter
/// @internal
/// @brief Deallocate unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Interpreter_CoreContext) object
/// @param memoryBlock a pointer to an unmanaged memory block previously allocated by
/// @a (Nucleus_Interpreter_CoreContext_allocate) or @a (Nucleus_Interpreter_CoreContext_allocateArray)
Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_deallocate
    (
        Nucleus_Interpreter_CoreContext *context,
        void *memoryBlock
    );

Nucleus_Interpreter_NoReturn() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_CoreContext_jump
    (
        Nucleus_Interpreter_CoreContext *context
    );
