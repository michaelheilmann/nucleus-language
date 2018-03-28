#pragma once

#include "Nucleus/Language.h"
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

#define Nucleus_Language_UnitTest_Status_AssertionFailed (1000)

#define Nucleus_Language_UnitTest_AssertTrue(c, e) \
    if (!(e)) { \
        fprintf(stderr, "assertion %s == true failed\n", #e); \
        Nucleus_Language_Context_raiseError(c, Nucleus_Language_UnitTest_Status_AssertionFailed); \
    }

#define Nucleus_Language_UnitTest_AssertEqualTo(c, x, y) \
    if (!((x) == (y))) { \
        fprintf(stderr, "assertion %s == %s failed\n", #x, #y); \
        Nucleus_Language_Context_raiseError(c, Nucleus_Language_UnitTest_Status_AssertionFailed); \
    }

#define Nucleus_Language_UnitTest_AssertNotEqualTo(c, x, y) \
    if (!((x) != (y))) { \
        fprintf(stderr, "assertion %s != %s failed\n", #x, #y); \
        Nucleus_Language_Context_raiseError(c, Nucleus_Language_UnitTest_Status_AssertionFailed); \
    }

#define Nucleus_Language_UnitTest_AssertGreaterThanOrEqualTo(c, x, y) \
    if (!((x) >= (y))) { \
        fprintf(stderr, "assertion %s >= %s failed\n", #x, #y); \
        Nucleus_Language_Context_raiseError(c, Nucleus_Language_UnitTest_Status_AssertionFailed); \
    }

Nucleus_Language_NoError() Nucleus_Language_NonNull() Nucleus_Language_Status
Nucleus_Language_UnitTest_run
    (
        void (*test)(Nucleus_Language_Context *)
    );
