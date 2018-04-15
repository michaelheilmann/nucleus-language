#include "Nucleus/Interpreter/GC/OnVisit.h"

#include "Nucleus/Interpreter/GC/Object.h"
#include "Nucleus/Interpreter/GC/Type.h"
#include "Nucleus/Interpreter/GC/Heap.h"
#include "Nucleus/Interpreter/Context.h"

Nucleus_Interpreter_NonNull() static void
onMark
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() static void
onMark
    (
        Nucleus_Interpreter_Context *context
    )
{
    Nucleus_Interpreter_GC *gc = &(NUCLEUS_INTERPRETER_CORECONTEXT(context)->gc);
#if DEBUG
    if (gc->state != Nucleus_Interpreter_GC_State_Mark)
    {
        fprintf(stderr, "%s:%d: internal error\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }
#endif
    while (gc->gray)
    {
        Nucleus_Interpreter_GC_Tag *tag = gc->gray; gc->gray = tag->gray;
        Nucleus_Interpreter_GC_Type *type = Nucleus_Interpreter_GC_Tag_getType(context, tag);
        if (type)
        {
            if (Nucleus_Interpreter_GC_Type_isArray(type))
            {
                Nucleus_Interpreter_GC_Type *elementType = type->arrayType.elementType;
                if (Nucleus_Interpreter_GC_Type_isArray(elementType) || Nucleus_Interpreter_GC_Type_isForeign(elementType))
                {
                    void **elements =  tag2Address(tag);
                    for (size_t i = 0, n = tag2ArrayTag(tag)->length; i < n; ++i)
                    {
                        void *element = elements[i];
                        if (NULL != element)
                        {
                            Nucleus_Interpreter_GC_Tag *elementTag = address2Tag(element);
                            if (Nucleus_Interpreter_GC_Tag_isWhite(elementTag))
                            {
                                elementTag->next = gc->gray;
                                gc->gray = elementTag;
                                Nucleus_Interpreter_GC_Tag_setGray(elementTag);
                            }
                        }
                    }
                }
            }
            else if (Nucleus_Interpreter_GC_Type_isForeign(type))
            {
                if (type->foreignType.visit)
                {
                    type->foreignType.visit(context, tag2Address(tag));
                }
            }
        }
        Nucleus_Interpreter_GC_Tag_setBlack(tag);
    }
}

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_onRun
    (
        Nucleus_Interpreter_Context *context
    )
{
    Nucleus_Interpreter_GC *gc = &(NUCLEUS_INTERPRETER_CORECONTEXT(context)->gc);
    do
    {
        if (gc->state == Nucleus_Interpreter_GC_State_Idle)
        {
            gc->state = Nucleus_Interpreter_GC_State_Premark;
        }
        else if (gc->state == Nucleus_Interpreter_GC_State_Premark)
        {
            Nucleus_Interpreter_GC_Heap_premark(context, NUCLEUS_INTERPRETER_GC_HEAP(&context->generalHeap));
            Nucleus_Interpreter_GC_Heap_premark(context, NUCLEUS_INTERPRETER_GC_HEAP(&context->stringHeap));
            gc->state = Nucleus_Interpreter_GC_State_Mark;
        }
        else if (gc->state == Nucleus_Interpreter_GC_State_Mark)
        {
            onMark(context);
            gc->state = Nucleus_Interpreter_GC_State_Sweep;
        }
        if (gc->state == Nucleus_Interpreter_GC_State_Sweep)
        {
            Nucleus_Interpreter_GC_Heap_sweep(context, NUCLEUS_INTERPRETER_GC_HEAP(&context->generalHeap));
            Nucleus_Interpreter_GC_Heap_sweep(context, NUCLEUS_INTERPRETER_GC_HEAP(&context->stringHeap));
            gc->state = Nucleus_Interpreter_GC_State_Idle;
        }
    } while (gc->state == Nucleus_Interpreter_GC_State_Idle);
}
