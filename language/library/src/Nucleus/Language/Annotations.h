#pragma once

#include "Nucleus/Language/FeatureLevelOne_Annotations.h"

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_FeatureLevelOne_NonNull.
#define Nucleus_Language_NonNull(...) Nucleus_Language_FeatureLevelOne_NonNull(__VA_ARGS__)

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_FeatureLevelOne_NoError.
#define Nucleus_Language_NoError() Nucleus_Language_FeatureLevelOne_NoError()

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_Language_FeatureLevelOne_NoReturn.
#define Nucleus_Language_NoReturn() Nucleus_Language_FeatureLevelOne_NoReturn()

/// @ingroup language
/// @internal
/// @brief Alias for Nucleus_Language_FeatureLevelOne_ReturnNonNull.
#define Nucleus_Language_ReturnNonNull() Nucleus_Language_FeatureLevelOne_ReturnNonNull()
