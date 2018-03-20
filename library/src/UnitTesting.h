#pragma once

#include "dl.h"
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

#define UnitTest_Status_AssertionFailed (1000)

#define UnitTest_AssertTrue(c, e) \
    if (!(e)) { \
        fprintf(stderr, "assertion %s == true failed\n", #e); \
        DL_Context_raiseError(c, UnitTest_Status_AssertionFailed); \
    }

#define UnitTest_AssertEqualTo(c, x, y) \
    if (!((x) == (y))) { \
        fprintf(stderr, "assertion %s == %s failed\n", #x, #y); \
        DL_Context_raiseError(c, UnitTest_Status_AssertionFailed); \
    }

#define UnitTest_AssertNotEqualTo(c, x, y) \
    if (!((x) != (y))) { \
        fprintf(stderr, "assertion %s != %s failed\n", #x, #y); \
        DL_Context_raiseError(c, UnitTest_Status_AssertionFailed); \
    }

#define UnitTest_AssertGreaterThanOrEqualTo(c, x, y) \
    if (!((x) >= (y))) { \
        fprintf(stderr, "assertion %s >= %s failed\n", #x, #y); \
        DL_Context_raiseError(c, UnitTest_Status_AssertionFailed); \
    }
