/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "DL/context.h"

#include "DL/string.h"
#include "DL/scanner.h"
#include "DL/hash-byte-array.h"

#include <setjmp.h>



DL_NonNull() static DL_Status
DL_ScratchSpace_create
    (
        DL_ScratchSpace **scratchSpace,
        size_t numberOfBytes
    );

DL_NonNull() static void
DL_ScratchSpace_destroy
    (
        DL_ScratchSpace *scratchSpace
    );



DL_NonNull() static DL_Status
DL_ScratchSpace_create
    (
        DL_ScratchSpace **scratchSpace,
        size_t numberOfBytes
    )
{
    if (!scratchSpace)
    { return DL_Status_InvalidArgument; }
    DL_ScratchSpace *temporary = malloc(sizeof(DL_ScratchSpace));
    if (!temporary)
    { return DL_Status_AllocationFailed; }
    temporary->bytes = malloc(sizeof(char) * (numberOfBytes > 0 ? numberOfBytes : 1));
    if (temporary->bytes)
    {
        free(temporary);
        return DL_Status_AllocationFailed;
    }
    temporary->numberOfBytes = numberOfBytes;
    *scratchSpace = temporary;
    return DL_Status_Success;
}

DL_NonNull() static void
DL_ScratchSpace_destroy
    (
        DL_ScratchSpace *scratchSpace
    )
{
    free(scratchSpace->bytes);
    free(scratchSpace);
}

DL_NonNull() DL_Status
DL_Context_initialize
    (
        DL_Context *context
    )
{
    if (!context)
    {
        return DL_Status_InvalidArgument;
    }

    context->jumpTargets = NULL;
    context->status = DL_Status_Success;
    context->scratchSpaces = NULL;
    context->status = DL_StringTable_initialize(&context->stringTable);
    if (context->status)
    { return context->status; }
    context->objects = NULL;

    DL_JumpTarget jt;

    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_Scanner_initialize(context, &context->scanner, &context->stringTable);
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringTable_uninitialize(&context->stringTable);
        return context->status;
    }

    DL_Context_pushJumpTarget(context, &jt);
    if (setjmp(jt.environment))
    {
        DL_Parser_initialize(context, &context->parser, &context->scanner);
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_Scanner_uninitialize(&context->scanner);
        DL_StringTable_uninitialize(&context->stringTable);
        return context->status;
    }

    return DL_Status_Success;
}

DL_NonNull() void
DL_Context_uninitialize
    (
        DL_Context *context
    )
{
    DL_Parser_uninitialize(&context->parser);
    DL_Scanner_uninitialize(&context->scanner);
    while (context->objects)
    {
        DL_Object *object = context->objects; context->objects = object->next;
        if (object->finalize)
        {
            object->finalize(object);
        }
        free(object);
    }
    DL_StringTable_uninitialize(&context->stringTable);
    while (context->scratchSpaces)
    {
        DL_ScratchSpace *scratchSpace = context->scratchSpaces; context->scratchSpaces = scratchSpace->next;
        DL_ScratchSpace_destroy(scratchSpace);
    }
    context->status = DL_Status_Success;
}

DL_NonNull(1) DL_Status
DL_Context_create
    (
       DL_Context **context
    )
{
   if (!context)
   {
      return DL_Status_InvalidArgument;
   }
   DL_Context *temporary = malloc(sizeof(DL_Context));
   if (!temporary)
   {
      return DL_Status_AllocationFailed;
   }
   DL_Status status = DL_Context_initialize(temporary);
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
    DL_Context_uninitialize(context);
    free(context);
}

DL_NonNull() char *
DL_Context_acquireScratchSpace
    (
        DL_Context *context,
        size_t numberOfBytes
    )
{
    DL_ScratchSpace *scratchSpace = context->scratchSpaces;
    if (!scratchSpace)
    {
        Nucleus_Status status = DL_ScratchSpace_create(&scratchSpace, numberOfBytes);
        if (status)
        {
            DL_Context_raiseError(context, status);
        }
        return ((char *)scratchSpace) + sizeof(DL_ScratchSpace);
    }
    if (scratchSpace->numberOfBytes < numberOfBytes)
    {
        char *newBytes = realloc(scratchSpace->bytes, sizeof(char) * numberOfBytes);
        if (!newBytes)
        {
            scratchSpace->next = context->scratchSpaces; context->scratchSpaces = scratchSpace;
            DL_Context_raiseError(context, DL_Status_AllocationFailed);
        }
        scratchSpace->bytes = newBytes;
        scratchSpace->numberOfBytes = numberOfBytes;
    }
    return ((char *)scratchSpace) + sizeof(DL_ScratchSpace);
}

DL_NonNull() void
DL_Context_relinquishScratchSpace
    (
        DL_Context *context,
        char *bytes
    )
{
    DL_ScratchSpace *scratchSpace = (DL_ScratchSpace *)(bytes - sizeof(DL_ScratchSpace));
    scratchSpace->next = context->scratchSpaces; context->scratchSpaces = scratchSpace;
}

DL_NonNull() void
DL_Context_pushJumpTarget
    (
        DL_Context *context,
        DL_JumpTarget *jumpTarget
    )
{
    jumpTarget->previous = context->jumpTargets;
    context->jumpTargets = jumpTarget;
}

DL_NonNull() void
DL_Context_popJumpTarget
    (
        DL_Context *context
    )
{
    context->jumpTargets = context->jumpTargets->previous;
}

DL_NonNull() void
DL_Context_raiseError
    (
        DL_Context *context,
        DL_Status status
    )
{
    context->status = status;
    longjmp(context->jumpTargets->environment, -1);
}

DL_NonNull() DL_Status
DL_Context_compile
    (
        DL_Context *context,
        char *input,
        size_t inputSize
    )
{
    if (!context || !input)
    {
        return DL_Status_InvalidArgument;
    }
    return DL_Status_Success;
}

DL_NonNull() DL_String *
DL_Context_createString
    (
        DL_Context *context,
        const char *bytes,
        size_t numberOfBytes
    )
{
    return DL_StringTable_getOrCreateString(context, &context->stringTable, bytes, numberOfBytes);
}
