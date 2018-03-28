#include "Nucleus/Language.h"

Nucleus_NonNull() static void
test
    (
        Nucleus_Language_Context *context
    )
{
    Nucleus_Language_String *contents = Nucleus_Language_Context_getFileContentsString(context, Nucleus_Language_String_create(context, "data/helloworld.txt",
                                                                                                                               strlen("data/helloworld.txt")));
    Nucleus_Language_String *reference = Nucleus_Language_String_create(context, "Hello, World!\r\n", strlen("Hello, World!\r\n"));
    Nucleus_Language_UnitTest_AssertTrue(context, Nucleus_Language_String_equal(context, contents, reference));
}

int main(int argc, char **argv)
{
    if (Nucleus_Language_UnitTest_run(&test)) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
