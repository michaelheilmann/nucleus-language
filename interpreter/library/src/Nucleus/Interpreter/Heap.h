#pragma once

#include "Nucleus/Interpreter/Annotations.h"

// Forward declaration.
typedef struct Nucleus_Interpreter_Context Nucleus_Interpreter_Context;

#define NUCLEUS_INTERPRETER_HEAP(pointer) ((Nucleus_Interpreter_Heap *)(pointer))
typedef struct Nucleus_Interpreter_Heap Nucleus_Interpreter_Heap;

#define NUCLEUS_INTERPRETER_HEAP_SWEEP(pointer) ((Nucleus_Interpreter_Heap_Sweep *)(pointer))
typedef void (Nucleus_Interpreter_Heap_Sweep)(Nucleus_Interpreter_Context *, Nucleus_Interpreter_Heap *);

#define NUCLEUS_INTERPRETER_HEAP_UNINITIALIZE(pointer) ((Nucleus_Interpreter_Heap_Uninitialize *)(pointer))
typedef void (Nucleus_Interpreter_Heap_Uninitialize)(Nucleus_Interpreter_Context *, Nucleus_Interpreter_Heap *);


struct Nucleus_Interpreter_Heap
{
    Nucleus_Interpreter_Heap_Sweep *sweep;
    Nucleus_Interpreter_Heap_Uninitialize *uninitialize;
};

/// @ingroup language
/// @internal
/// @brief Initialize a @a (Nucleus_Interpreter_Heap) object.
Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Heap_initialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Heap *heap
    );

/// @ingroup language
/// @internal
/// @brief Uninitialize a @a (Nucleus_Interpreter_Heap) object.
Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Heap_uninitialize
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Heap *heap
    );

/// @ingroup language
/// @internal
/// @brief Sweep a @a (Nucleus_Interpreter_Heap) object i.e. finalize and deallocate dead objects on the heap.
/// @param context a pointer to a @a (Nucleus_Interpreter_Context) object
/// @param heap a pointer to the initialized @a (Nucleus_Interpreter_Heap) object
Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_Heap_sweep
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Heap *heap
    );
