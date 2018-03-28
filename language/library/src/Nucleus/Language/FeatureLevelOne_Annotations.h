#pragma once

#include "Nucleus/Annotations.h"

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_NonNull.
#define Nucleus_Language_FeatureLevelOne_NonNull(...) Nucleus_NonNull(__VA_ARGS__)

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_NoError.
#define Nucleus_Language_FeatureLevelOne_NoError() Nucleus_NoError()

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_NoReturn.
#define Nucleus_Language_FeatureLevelOne_NoReturn() Nucleus_NoReturn()

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_ReturnNonNull.
#define Nucleus_Language_FeatureLevelOne_ReturnNonNull() Nucleus_ReturnNonNull()
