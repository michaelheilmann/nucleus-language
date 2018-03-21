/// @file Nucleus/Language/FeatureLevelOne_Context.h
/// @brief Declarations of a @a (Nucleus_Language_FeatureLevelOne_Context) object.
/// @author Michael Heilmann
#pragma once

#include "Nucleus/Language/FeatureLevelOne_Annotations.h"
#include "Nucleus/Language/FeatureLevelOne_Status.h"
#include <stddef.h> /// @todo For size_t. Remove this.

// Forward declarations.
typedef struct Nucleus_Language_FeatureLevelOne_ErrorHandler Nucleus_Language_FeatureLevelOne_ErrorHandler;

/// @ingroup language
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Language_FeatureLevelOne_Context) or derived pointer into a @a (Nucleus_Language_FeatureLevelOne_Context) pointer
/// @param pointer a @a (Nucleus_Language_FeatureLevelOne_Context) or derived pointer
#define NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(pointer) ((Nucleus_Language_FeatureLevelOne_Context *)(pointer))

/// @ingroup language
/// @internal
/// @brief The base of a context.
/// @details This base is required for creating @a (Nucleus_Language_Heap) objects.
/// @todo Add support for garbage collection types (visit and finalize).
typedef struct Nucleus_Language_FeatureLevelOne_Context Nucleus_Language_FeatureLevelOne_Context;

struct Nucleus_Language_FeatureLevelOne_Context
{
    /// @brief A null pointer or a pointer to the last element of the singly-linked list stack of @a (Nucleus_Language_FeatureLevelOne_ErrorHandler) objects.
    Nucleus_Language_FeatureLevelOne_ErrorHandler *errorHandlers;
    
    /// @brief The status variable of this context.
    /// Default value is Nucleus_Language_FeatureLevelOne_Status_Success.
    Nucleus_Language_FeatureLevelOne_Status status;

}; // struct Nucleus_Language_FeatureLevelOne_Context

/// @ingroup language
/// @internal
/// @brief Initialize this @a (Nucleus_Language_FeatureLevel_OneContext) object.
/// @param context a pointer to an uninitialized @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @return #Nucleus_Language_Status_Success on success, a non-zero status code on success
Nucleus_Language_FeatureLevelOne_NonNull() Nucleus_Language_FeatureLevelOne_Status
Nucleus_Language_FeatureLevelOne_Context_initialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    );

/// @ingroup language
/// @internal
/// @brief Uninitialize this @a (Nucleus_Language_FeatureLevelOne_Context) object.
/// @param context a pointer to an initialized @a (Nucleus_Language_FeatureLevelOne_Context) object
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_uninitialize
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    );

/// @ingroup language
/// @internal
/// @brief Push an error handler on the top of the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @param errorHandler a pointer to the @a (Nucleus_Language_FeatureLevelOne_ErrorHandler) object
Nucleus_Language_FeatureLevelOne_NoError() void
Nucleus_Language_FeatureLevelOne_Context_pushErrorHandler
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_ErrorHandler *errorHandler
    );

/// @ingroup language
/// @brief Pop an error handler from the stack of error handlers.
/// @param context a pointer to the @a (Nucleus_Language_FeatureLevelOne_Context) object
/// @undefined the error handler stack of the @a (Nucleus_Language_FeatureLevelOne_Context) object is empty
Nucleus_Language_FeatureLevelOne_NoError() void
Nucleus_Language_FeatureLevelOne_Context_popErrorHandler
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    );

/// @ingroup language
/// @internal
/// @brief Raise an error.
/// @detail
/// - Assign the status variable of the context as if
/// @code
/// Nucleus_Language_FeatureLevelOne_Context_setStatus(context, status)
/// @endcode
/// was called.
/// - Jump to the jump target on the top of the stack of jump targets.
/// In particular, the behavior of a call to this function is undefined if that stack is empty.
/// @param context a pointer to the @a (Nucleus_Language_FeatureLevelOne_Context) object
Nucleus_Language_FeatureLevelOne_NoReturn() Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_raiseError
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Status status
    );

/// @ingroup language
/// @internal
/// @brief Get the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_Language_FeatureLevelOne_Context) object
/// @return the value assigned to the status variable
Nucleus_Language_FeatureLevelOne_NonNull() Nucleus_Language_FeatureLevelOne_Status
Nucleus_Language_FeatureLevelOne_Context_getStatus
    (
        Nucleus_Language_FeatureLevelOne_Context *context
    );

/// @ingroup language
/// @internal
/// @brief Set the value of the status variable of a context.
/// @param context a pointer to the @ (Nucleus_Language_FeatureLevelOne_Context) object
/// @param status the value of to be assigned to the status variable
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_setStatus
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        Nucleus_Language_FeatureLevelOne_Status status
    );

/// @ingroup language
/// @internal
/// @brief Allocate an unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Language_FeatureLevelOne_Context) object
/// @param size the size, in Bytes, of the memory block to allocate. @a 0 is a valid size.
/// @return a pointer to the beginning of the unmanaged memory block of the size @a numberOfBytes
Nucleus_Language_FeatureLevelOne_ReturnNonNull() Nucleus_Language_FeatureLevelOne_NonNull() void *
Nucleus_Language_FeatureLevelOne_Context_allocate
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        size_t size
    );

/// @ingroup language
/// @internal
/// @brief Allocate an unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Language_FeatureLevelOne_Context) object
/// @param numberOfElements, elementSize the size, in Bytes, of the memory block to allocate. @a 0 is a valid size.
/// @return a pointer to the beginning of the unmanaged memory block of the size @a numberOfBytes
Nucleus_Language_FeatureLevelOne_ReturnNonNull() Nucleus_Language_FeatureLevelOne_NonNull() void *
Nucleus_Language_FeatureLevelOne_Context_allocateArray
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        size_t numberOfElements,
        size_t elementSize
    );

/// @ingroup language
/// @internal
/// @brief Deallocate unmanaged memory block.
/// @param context a pointer to the @ (Nucleus_Language_FeatureLevelOne_Context) object
/// @param memoryBlock a pointer to an unmanaged memory block previously allocated by @a (Nucleus_Language_FeatureLevelOne_Context_allocate)
Nucleus_Language_FeatureLevelOne_NonNull() void
Nucleus_Language_FeatureLevelOne_Context_deallocate
    (
        Nucleus_Language_FeatureLevelOne_Context *context,
        void *memoryBlock
    );
