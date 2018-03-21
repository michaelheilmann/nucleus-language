#include "Nucleus/Language.h"

static Nucleus_Language_Status test()
{
    Nucleus_Language_Context *context;
    Nucleus_Language_Status status = Nucleus_Language_Context_create(&context);
    if (status) {
        return status;
    }
    Nucleus_Language_ErrorHandler eh;
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        Nucleus_Language_String *x = Nucleus_Language_String_create(context, "Hello, World\n", strlen("Hello, World!\n"));
        Nucleus_Language_UnitTest_AssertTrue(context, Nucleus_Language_String_equal(context, x, x));
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        status = Nucleus_Language_Context_getStatus(context);
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_Context_destroy(context);
        return status;
    }

    status = Nucleus_Language_Context_getStatus(context);
    Nucleus_Language_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    
    if (test()) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
