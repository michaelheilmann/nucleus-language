#include "Nucleus/Interpreter/HeapObject.h"

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_lock
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    )
{ heapObject->lockCount++; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_unlock
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    )
{ heapObject->lockCount--; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject,
        Nucleus_Interpreter_HeapObject_Visit *visit
    )
{ heapObject->visit = visit; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_HeapObject_Visit *
Nucleus_Interpreter_HeapObject_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    )
{ return heapObject->visit; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_setFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject,
        Nucleus_Interpreter_HeapObject_Finalize *finalize
    )
{ heapObject->finalize = finalize; }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_HeapObject_Finalize *
Nucleus_Interpreter_HeapObject_getFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    )
{ return heapObject->finalize; }
