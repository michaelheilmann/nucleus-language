#include "DL/source.h"

#include "DL/context.h"
#include <malloc.h>

DL_NonNull() DL_Source *
DL_Source_create
    (
        DL_Context *context,
        DL_String *name,
        DL_String *string
    )
{
    DL_Source *self = malloc(sizeof(DL_Source));
    if (!self)
    {
        DL_Context_raiseError(context, DL_Status_AllocationFailed);
    }
    self->name = name;
    self->string = string;
    ((DL_Object *)(self))->next = context->objects; context->objects = (DL_Object *)self;
    ((DL_Object *)(self))->finalize = NULL;
    return self;
}

DL_NonNull() DL_String *
DL_Source_getName
    (
        DL_Context *context,
        DL_Source *source
    )
{ return source->name; }

DL_NonNull() DL_String *
DL_Source_getString
    (
        DL_Context *context,
        DL_Source *source
    )
{ return source->string; }
