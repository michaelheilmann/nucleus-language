#pragma once

#include "Nucleus/Language.h"

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Language_NonNull.
#define DL_NonNull(...) Nucleus_Language_NonNull(__VA_ARGS__)

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Language_NoError.
#define DL_NoError() Nucleus_Language_NoError()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Language_NoReturn.
#define DL_NoReturn() Nucleus_Language_NoReturn()

/// @ingroup Nucleus-DataLanguage
/// @internal
/// @brief Alias for Nucleus_Language_ReturnNonNull.
#define DL_ReturnNonNull() Nucleus_Language_ReturnNonNull()