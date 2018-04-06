#pragma once

#include "Nucleus/Interpreter/Annotations.h"

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NonNull.
#define Nucleus_DataLanguage_NonNull(...) Nucleus_Interpreter_NonNull(__VA_ARGS__)

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NoError.
#define Nucleus_DataLanguage_NoError() Nucleus_Interpreter_NoError()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_NoReturn.
#define Nucleus_DataLanguage_NoReturn() Nucleus_Interpreter_NoReturn()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Interpreter_ReturnNonNull.
#define Nucleus_DataLanguage_ReturnNonNull() Nucleus_Interpreter_ReturnNonNull()