/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"
#include "DL/string.h"
#include "DL/scanner.h"
#include "DL/parser.h"
#include <setjmp.h>

typedef struct DL_ScratchSpace DL_ScratchSpace;
struct DL_ScratchSpace
{
    DL_ScratchSpace *next;
    size_t numberOfBytes;
    char bytes[];
};

typedef struct DL_JumpTarget DL_JumpTarget;
struct DL_JumpTarget
{
    DL_JumpTarget *previous;
    jmp_buf environment;
};

struct DL_Context
{
    DL_StringTable stringTable;
    DL_Object *objects;
    DL_Scanner scanner;
    DL_Parser parser;
    DL_Status status;
    DL_JumpTarget *jumpTargets;
    DL_ScratchSpace *scratchSpaces;
}; // struct DL_Context

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

DL_NonNull() void
DL_Context_pushJumpTarget
    (
        DL_Context *context,
        DL_JumpTarget *jumpTarget
    );

DL_NonNull() void
DL_Context_popJumpTarget
    (
        DL_Context *context
    );

DL_NonNull() void
DL_Context_raiseError
    (
        DL_Context *context,
        DL_Status status
    );
    
/// @brief Create a @a DL_Context object.
/// @return #DL_Status_Success on success, a non-zero DL_Status value on failure
DL_NonNull(1) DL_Status
DL_Context_initialize
    (
        DL_Context *context
    );

DL_NonNull() void
DL_Context_uninitialize
    (
        DL_Context *context
    );

/// @brief Create a context.
/// @return #DL_Status_Success on success, a non-zero status code on failure
/// @post @a *context was assigned a pointer to a @a Nucleus_Language_Context object on success.
/// @a context was not dereferenced on failure
DL_NonNull() DL_Status
DL_Context_create
    (
        DL_Context **context
    );

/// @brief Destroy a context.
/// @param context a pointer to a @a DL_Context object
/// @post The @a DL_Context and all its contained objects were destroyed
DL_NonNull() void
DL_Context_destroy
    (
        DL_Context *context
    );

/// @brief Compile input.
/// @param context a pointer to a @a DL_Context object
/// @param input a pointer to an array of @a inputLength Bytes
/// @param inputSize the length of the array pointed to by @a input. A size of @a 0 is a valid size.
/// @return #DL_Status_Success on success, a non-zero status code on failure.
/// The non-zero status codes include (but are not restricted to) the following:
/// - #DL_Status_ArgumentInvalid @a context or @a input is a null pointer
/// - #DL_Status_AllocationFailed an allocation failed
DL_NonNull() DL_Status
DL_Context_compile
    (
        DL_Context *context,
        char *input,
        size_t inputSize
    );

DL_NonNull() DL_String *
DL_Context_createString
    (
        DL_Context *context,
        const char *bytes,
        size_t numberOfBytes
    );

DL_NonNull() DL_Status
DL_Context_getStatus
    (
        DL_Context *context
    );