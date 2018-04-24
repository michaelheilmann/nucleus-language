// Copyright (c) Michael Heilmann 2018
#pragma once

#include "Nucleus/Interpreter/UnitTesting.h"

#define Nucleus_DataLanguage_Status_AssertionFailed Nucleus_Interpreter_Status_AssertionFailed

#define DL_UnitTest_AssertTrue(c, e) \
    Nucleus_Interpreter_UnitTest_AssertTrue((c)->context, e)

#define DL_UnitTest_AssertEqualTo(c, x, y) \
    Nucleus_Interpreter_UnitTest_AssertEqual((c)->context, x, y)

#define DL_UnitTest_AssertNotEqual(c, x, y) \
    Nucleus_Interpreter_UnitTest_AssertNotEqual((c)->context, x, y)

#define UnitTest_AssertGreaterThanOrEqualTo(c, x, y) \
    Nucleus_Interpreter_UnitTest_AssertGreaterThanOrEqualTo((c)->context, x, y)
