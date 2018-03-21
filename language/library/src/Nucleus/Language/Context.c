/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/Language/Context-private.c.in"

Nucleus_Language_NonNull(1) Nucleus_Language_Status
Nucleus_Language_Context_create
    (
       Nucleus_Language_Context **context
    )
{
   if (!context)
   {
      return Nucleus_Language_Status_InvalidArgument;
   }
   Nucleus_Language_Context *temporary = malloc(sizeof(Nucleus_Language_Context));
   if (!temporary)
   {
      return Nucleus_Language_Status_AllocationFailed;
   }
   Nucleus_Language_Status status = Nucleus_Language_Context_initialize(temporary);
   if (status)
   {
      free(temporary);
      return status;
   }
   *context = temporary;
   return Nucleus_Language_Status_Success;
}

Nucleus_Language_NonNull() void
Nucleus_Language_Context_destroy
    (
        Nucleus_Language_Context *context
    )
{
    Nucleus_Language_Context_uninitialize(context);
    free(context);
}

Nucleus_Language_NoError() void
Nucleus_Language_Context_pushErrorHandler
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_ErrorHandler *errorHandler
    )
{ Nucleus_Language_FeatureLevelOne_Context_pushErrorHandler(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), errorHandler); }

Nucleus_Language_NoError() void
Nucleus_Language_Context_popErrorHandler
    (
        Nucleus_Language_Context *context
    )
{ Nucleus_Language_FeatureLevelOne_Context_popErrorHandler(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context)); }

Nucleus_Language_NoReturn() Nucleus_Language_NonNull() void
Nucleus_Language_Context_raiseError
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Status status
    )
{ Nucleus_Language_FeatureLevelOne_Context_raiseError(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), status); }

Nucleus_Language_NonNull() Nucleus_Language_Status
Nucleus_Language_Context_getStatus
    (
        Nucleus_Language_Context *context
    )
{ return Nucleus_Language_FeatureLevelOne_Context_getStatus(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context)); }

Nucleus_Language_NonNull() void
Nucleus_Language_Context_setStatus
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Status status
    )
{ Nucleus_Language_FeatureLevelOne_Context_setStatus(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), status); }

Nucleus_Language_NonNull() char *
Nucleus_Language_Context_acquireScratchSpace
    (
        Nucleus_Language_Context *context,
        size_t numberOfBytes
    )
{
    Nucleus_Language_ScratchSpace *scratchSpace = context->scratchSpaces;
    if (!scratchSpace)
    {
        scratchSpace = Nucleus_Language_ScratchSpace_create(context, numberOfBytes);
    }
    if (scratchSpace->numberOfBytes < numberOfBytes)
    {
        Nucleus_Language_ScratchSpace *newScratchSpace = realloc(scratchSpace, sizeof(Nucleus_Language_ScratchSpace) + sizeof(char) * numberOfBytes);
        if (!newScratchSpace)
        {
            scratchSpace->next = context->scratchSpaces; context->scratchSpaces = scratchSpace;
            Nucleus_Language_Context_raiseError(context, Nucleus_Language_Status_AllocationFailed);
        }
        scratchSpace = newScratchSpace;
        scratchSpace->numberOfBytes = numberOfBytes;
    }
    return ((char *)scratchSpace) + sizeof(Nucleus_Language_ScratchSpace);
}

Nucleus_Language_NonNull() void
Nucleus_Language_Context_relinquishScratchSpace
    (
        Nucleus_Language_Context *context,
        char *bytes
    )
{
    Nucleus_Language_ScratchSpace *scratchSpace = (Nucleus_Language_ScratchSpace *)(bytes - sizeof(Nucleus_Language_ScratchSpace));
    scratchSpace->next = context->scratchSpaces; context->scratchSpaces = scratchSpace;
}

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() void *
Nucleus_Language_Context_allocate
    (
        Nucleus_Language_Context *context,
        size_t size
    )
{ return Nucleus_Language_FeatureLevelOne_Context_allocate(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), size); }

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() void *
Nucleus_Language_Context_allocateArray
    (
        Nucleus_Language_Context *context,
        size_t numberOfElements,
        size_t elementSize
    )
{ return Nucleus_Language_FeatureLevelOne_Context_allocateArray(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), numberOfElements, elementSize); }


Nucleus_Language_NonNull(1) void
Nucleus_Language_Context_deallocate
    (
        Nucleus_Language_Context *context,
        void *p
    )
{ Nucleus_Language_FeatureLevelOne_Context_deallocate(NUCLEUS_LANGUAGE_FEATURELEVELONE_CONTEXT(context), p); }

Nucleus_Language_ReturnNonNull() Nucleus_Language_NonNull() Nucleus_Language_Object *
Nucleus_Language_Context_allocateObject
    (
        Nucleus_Language_Context *context,
        size_t numberOfBytes
    )
{
    Nucleus_Language_Object *object = Nucleus_Language_Context_allocate(context, numberOfBytes);
    object->next = context->generalHeap.objects; context->generalHeap.objects = object;
    return object;
}
