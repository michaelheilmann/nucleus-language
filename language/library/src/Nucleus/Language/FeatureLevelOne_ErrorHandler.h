#pragma once

#include <setjmp.h>

/// @ingroup language
/// @internal
/// @brief An error handler.
typedef struct Nucleus_Language_FeatureLevelOne_ErrorHandler Nucleus_Language_FeatureLevelOne_ErrorHandler;

struct Nucleus_Language_FeatureLevelOne_ErrorHandler
{
    Nucleus_Language_FeatureLevelOne_ErrorHandler *previous;
    jmp_buf environment;
}; // struct Nucleus_Language_FeatureLevelOne_ErrorHandler