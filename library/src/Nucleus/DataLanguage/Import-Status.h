#pragma once

#include "Nucleus/Interpreter/Status.h"

/// @ingroup Nucleus-DataLanguage
/// @brief Status codes of this library.
#define DL_Status Nucleus_Interpreter_Status

#define DL_Status_Success Nucleus_Interpreter_Status_Success
#define DL_Status_AllocationFailed Nucleus_Interpreter_Status_AllocationFailed
#define DL_Status_InvalidArgument Nucleus_Interpreter_Status_InvalidArgument
#define DL_Status_UnreachableCodeReached Nucleus_Interpreter_Status_UnreachableCodeReached
#define DL_Status_Overflow Nucleus_Interpreter_Status_Overflow
#define DL_Status_LexicalError Nucleus_Interpreter_Status_LexicalError
#define DL_Status_SyntacticalError Nucleus_Interpreter_Status_SyntacticalError
#define DL_Status_SemanticalError Nucleus_Interpreter_Status_SemanticalError
#define DL_Status_InternalError Nucleus_Interpreter_Status_InternalError

DL_Status DL_Status_toInternal(Nucleus_Interpreter_Status status);