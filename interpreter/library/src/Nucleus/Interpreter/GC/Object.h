// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/Interpreter/Annotations.h"
#include <stdbool.h> // For bool.
#include <stddef.h> // For size_t.

// Forward declaration.
typedef struct Nucleus_Interpreter_Context Nucleus_Interpreter_Context;


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/// @ingroup gc
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_GC_Object) or derived pointer to a @a (Nucleus_Interpreter_GC_Object) pointer.
#define NUCLEUS_INTERPRETER_GC_OBJECT(pointer) ((Nucleus_Interpreter_GC_Object *)(pointer))

/// @ingroup gc
/// @internal
/// @brief Base type of all GC objects.
typedef struct Nucleus_Interpreter_GC_Object Nucleus_Interpreter_GC_Object;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define Nucleus_Interpreter_GC_Color_Black (1)

#define Nucleus_Interpreter_GC_Color_White (2)

#define Nucleus_Interpreter_GC_Color_Gray (Nucleus_Interpreter_GC_Color_Black | Nucleus_Interpreter_GC_Color_White)

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/// @ingroup gc
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_GC_Object_Finalize) or derived pointer to a @a (Nucleus_Interpreter_GC_Object_Finalize) pointer.
#define NUCLEUS_INTERPRETER_GC_OBJECT_FINALIZE(pointer) ((Nucleus_Interpreter_GC_Object_Finalize *)(pointer))

/// @ingroup gc
/// @internal
/// @brief Type of a finalizer function of GC objects.
typedef void Nucleus_Interpreter_GC_Object_Finalize(Nucleus_Interpreter_Context *context, Nucleus_Interpreter_GC_Object *object);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/// @ingroup gc
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_GC_Object_Visit) or derived pointer to a @a (Nucleus_Interpreter_GC_Object_Visit) pointer.
#define NUCLEUS_INTERPRETER_GC_OBJECT_VISIT(pointer) ((Nucleus_Interpreter_GC_Object_Visit *)(pointer))

/// @ingroup gc
/// @internal
/// @brief Type of a finalizer function of GC objects.
typedef void Nucleus_Interpreter_GC_Object_Visit(Nucleus_Interpreter_Context *context, Nucleus_Interpreter_GC_Object *object);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

struct Nucleus_Interpreter_GC_Object
{
    Nucleus_Interpreter_GC_Object *next;
    char flags;
    size_t lockCount;
    Nucleus_Interpreter_GC_Object *gray;
    Nucleus_Interpreter_GC_Object_Finalize *finalize;
    Nucleus_Interpreter_GC_Object_Visit *visit;
}; // struct Nucleus_Interpreter_GC_Object

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_lock
    (
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_unlock
    (
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isLocked
    (
        Nucleus_Interpreter_GC_Object *object
    );

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_GC_Object_Finalize *
Nucleus_Interpreter_GC_Object_getFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setFinalizer
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object,
        Nucleus_Interpreter_GC_Object_Finalize *finalize
    );

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_GC_Object_Visit *
Nucleus_Interpreter_GC_Object_getVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setVisitor
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_GC_Object *object,
        Nucleus_Interpreter_GC_Object_Visit *visit
    );

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isGray
    (
        const Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setGray
    (
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isBlack
    (
        const Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setBlack
    (
        Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NonNull() bool
Nucleus_Interpreter_GC_Object_isWhite
    (
        const Nucleus_Interpreter_GC_Object *object
    );

Nucleus_Interpreter_NonNull() void
Nucleus_Interpreter_GC_Object_setWhite
    (
        Nucleus_Interpreter_GC_Object *object
    );
