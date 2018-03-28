#pragma once

#include "Nucleus/Language/UnitTesting.h"

#define DL_Status_AssertionFailed Nucleus_Language_Status_AssertionFailed

#define DL_UnitTest_AssertTrue(c, e) \
    Nucleus_Language_UnitTest_AssertTrue(c->context, e)

#define DL_UnitTest_AssertEqualTo(c, x, y) \
    Nucleus_Language_UnitTest_AssertEqual((c)->context, x, y)

#define DL_UnitTest_AssertNotEqual(c, x, y) \
    Nucleus_Language_UnitTest_AssertNotEqual((c)->context, x, y)

#define UnitTest_AssertGreaterThanOrEqualTo(c, x, y) \
    Nucleus_Language_UnitTest_AssertGreaterThanOrEqualTo((c)->context, x, y)
