#pragma once

#include "Nucleus/Interpreter/Annotations.h"
#include <stddef.h> // For size_t.

// Forward declaration.
typedef struct Nucleus_Interpreter_Context Nucleus_Interpreter_Context;

/// @ingroup interpreter
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_HeapObject) or derived pointer to a @a (Nucleus_Interpreter_HeapObject) pointer.
#define NUCLEUS_INTERPRETER_HEAPOBJECT(pointer) ((Nucleus_Interpreter_HeapObject *)(pointer))

/// @ingroup interpreter
/// @internal
/// @brief Base type of all heap objects.
typedef struct Nucleus_Interpreter_HeapObject Nucleus_Interpreter_HeapObject;

/// @ingroup interpreter
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_HeapObject_Finalize) or derived pointer to a @a (Nucleus_Interpreter_HeapObject_Finalize) pointer.
#define NUCLEUS_INTERPRETER_HEAPOBJECT_FINALIZE(pointer) ((Nucleus_Interpreter_HeapObject_Finalize *)(pointer))

/// @ingroup interpreter
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef void Nucleus_Interpreter_HeapObject_Finalize(Nucleus_Interpreter_Context *context, Nucleus_Interpreter_HeapObject *heapObject);

/// @ingroup interpreter
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_HeapObject_Visit) or derived pointer to a @a (Nucleus_Interpreter_HeapObject_Visit) pointer.
#define NUCLEUS_INTERPRETER_HEAPOBJECT_VISIT(pointer) ((Nucleus_Interpreter_HeapObject_Visit *)(pointer))

/// @ingroup interpreter
/// @internal
/// @brief Type of a finalizer function of managed heap objects.
typedef void Nucleus_Interpreter_HeapObject_Visit(Nucleus_Interpreter_Context *context, Nucleus_Interpreter_HeapObject *heapObject);

struct Nucleus_Interpreter_HeapObject
{
    Nucleus_Interpreter_HeapObject *next;
    size_t lockCount;
    Nucleus_Interpreter_HeapObject_Finalize *finalize;
    Nucleus_Interpreter_HeapObject_Visit *visit;
}; // struct Nucleus_Interpreter_HeapObject

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_lock
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_unlock
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject,
        Nucleus_Interpreter_HeapObject_Visit *visit
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_HeapObject_Visit *
Nucleus_Interpreter_HeapObject_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_HeapObject_setFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject,
        Nucleus_Interpreter_HeapObject_Finalize *finalize
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_HeapObject_Finalize *
Nucleus_Interpreter_HeapObject_getFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_HeapObject *heapObject
    );
