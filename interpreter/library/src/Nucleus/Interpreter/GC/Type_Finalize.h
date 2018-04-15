#pragma once

// Forward declaration.
typedef struct Nucleus_Interpreter_GC_Type Nucleus_Interpreter_GC_Type;
typedef struct Nucleus_Interpreter_GC Nucleus_Interpreter_GC;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/// @ingroup gc
/// @internal
/// @brief Unconditionally cast a @a (Nucleus_Interpreter_GC_Type_Finalize) or derived pointer to a @a (Nucleus_Interpreter_GC_Type_Finalize) pointer.
#define NUCLEUS_INTERPRETER_GC_TYPE_FINALIZE(pointer) ((Nucleus_Interpreter_GC_Type_Finalize *)(pointer))

/// @ingroup gc
/// @internal
/// @brief Type of a GC type finalizer.
typedef void (Nucleus_Interpreter_GC_Type_Finalize)(Nucleus_Interpreter_GC *gc, Nucleus_Interpreter_GC_Type *type);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
