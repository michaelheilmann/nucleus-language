#include "Nucleus/DataLanguage/SourceLocation.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/Context.h"
#include "Nucleus/Interpreter/HeapObject.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceLocation *self,
        DL_Source *source,
        size_t offset
    );

DL_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        DL_SourceLocation *self
    );

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_SourceLocation *self,
        DL_Source *source,
        size_t offset
    )
{
    self->source = source;
    self->offset = offset;
}

DL_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        DL_SourceLocation *sourceLocation
    )
{ /**@todo Add implementation.*/ }


DL_NonNull() DL_SourceLocation *
DL_SourceLocation_create
    (
        DL_Context *context,
        DL_Source *source,
        size_t offset
    )
{
    DL_SourceLocation *self = (DL_SourceLocation *)DL_Context_allocateObject(context, sizeof(DL_SourceLocation));
    initialize(context, self, source, offset);
    Nucleus_Interpreter_HeapObject_setVisitor(NUCLEUS_INTERPRETER_CONTEXT(context->context),
                                              NUCLEUS_INTERPRETER_HEAPOBJECT(self),
                                              NUCLEUS_INTERPRETER_HEAPOBJECT_VISIT(&visit));
    return self;
}

DL_NonNull() void
DL_SourceLocation_assign
    (
        DL_Context *context,
        DL_SourceLocation *target,
        DL_SourceLocation *source
    );
