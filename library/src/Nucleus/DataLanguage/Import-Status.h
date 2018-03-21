#pragma once

#include "Nucleus/Language.h"

/// @ingroup Nucleus-DataLanguage
/// @brief Status codes of this library.
#define DL_Status Nucleus_Language_Status

#define DL_Status_Success Nucleus_Language_Status_Success
#define DL_Status_AllocationFailed Nucleus_Language_Status_AllocationFailed
#define DL_Status_InvalidArgument Nucleus_Language_Status_InvalidArgument
#define DL_Status_UnreachableCodeReached Nucleus_Language_Status_UnreachableCodeReached
#define DL_Status_Overflow Nucleus_Language_Status_Overflow
#define DL_Status_LexicalError Nucleus_Language_Status_LexicalError
#define DL_Status_SyntacticalError Nucleus_Language_Status_SyntacticalError
#define DL_Status_SemanticalError Nucleus_Language_Status_SemanticalError
#define DL_Status_InternalError Nucleus_Language_Status_InternalError

DL_Status DL_Status_toInternal(Nucleus_Language_Status status);