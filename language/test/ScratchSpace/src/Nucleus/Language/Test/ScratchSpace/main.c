#include "Nucleus/Language.h"

Nucleus_NonNull() static void
test
    (
        Nucleus_Language_Context *context
    )
{
    char *p = Nucleus_Language_Context_acquireScratchSpace(context, 16);
    memcpy(p, "Hello, World!\r\n", strlen("Hello, World!\r\n"));
    Nucleus_Language_Context_relinquishScratchSpace(context, p);
}

int main(int argc, char **argv)
{
    
    if (Nucleus_Language_UnitTest_run(&test)) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
