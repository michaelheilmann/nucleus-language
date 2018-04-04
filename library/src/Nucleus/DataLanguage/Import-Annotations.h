#pragma once

#include "Nucleus/Interpreter/Annotations.h"

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NonNull.
#define DL_NonNull(...) Nucleus_Interpreter_NonNull(__VA_ARGS__)

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NoError.
#define DL_NoError() Nucleus_Interpreter_NoError()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NoReturn.
#define DL_NoReturn() Nucleus_Interpreter_NoReturn()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_ReturnNonNull.
#define DL_ReturnNonNull() Nucleus_Interpreter_ReturnNonNull()