#pragma once

#include "Nucleus/Interpreter/Context.h"
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

#define Nucleus_Interpreter_UnitTest_Status_AssertionFailed (1000)

#define Nucleus_Interpreter_UnitTest_AssertTrue(c, e) \
    if (!(e)) { \
        fprintf(stderr, "assertion %s == true failed\n", #e); \
        Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(c), Nucleus_Interpreter_UnitTest_Status_AssertionFailed); \
        Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(c)); \
    }

#define Nucleus_Interpreter_UnitTest_AssertEqualTo(c, x, y) \
    if (!((x) == (y))) { \
        fprintf(stderr, "assertion %s == %s failed\n", #x, #y); \
        Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(c), Nucleus_Interpreter_UnitTest_Status_AssertionFailed); \
        Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(c)); \
    }

#define Nucleus_Interpreter_UnitTest_AssertNotEqualTo(c, x, y) \
    if (!((x) != (y))) { \
        fprintf(stderr, "assertion %s != %s failed\n", #x, #y); \
        Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(c), Nucleus_Interpreter_UnitTest_Status_AssertionFailed); \
        Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(c)); \
    }

#define Nucleus_Interpreter_UnitTest_AssertGreaterThanOrEqualTo(c, x, y) \
    if (!((x) >= (y))) { \
        fprintf(stderr, "assertion %s >= %s failed\n", #x, #y); \
        Nucleus_Interpreter_CoreContext_setStatus(NUCLEUS_INTERPRETER_CORECONTEXT(c), Nucleus_Interpreter_UnitTest_Status_AssertionFailed); \
        Nucleus_Interpreter_CoreContext_jump(NUCLEUS_INTERPRETER_CORECONTEXT(c)); \
    }

Nucleus_Interpreter_NoError() Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Status
Nucleus_Interpreter_UnitTest_run
    (
        void (*test)(Nucleus_Interpreter_Context *)
    );
