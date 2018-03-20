#include "dl.h"
#include "nucleus-filesystem.h"
#include "UnitTesting.h"

static DL_Status test()
{
    DL_Context *context;
    DL_Status status = DL_Context_create(&context);
    if (status) {
        return status;
    }
    DL_JumpTarget jt;
    DL_StringBuffer stringBuffer;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_String *x = DL_Context_createString(context, "Hello, World\n", strlen("Hello, World!\n"));
        UnitTest_AssertTrue(context, DL_String_equal(context, x, x));
        DL_Context_popJumpTarget(context);
    }
    else
    {
        status = context->status;
        DL_Context_popJumpTarget(context);
        DL_Context_destroy(context);
        return status;
    }

    status = context->status;
    DL_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    
    if (test()) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
