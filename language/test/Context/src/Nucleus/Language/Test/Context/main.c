#include "Nucleus/Language.h"

static Nucleus_Language_Status test()
{
    Nucleus_Language_Context *context;
    Nucleus_Language_Status status = Nucleus_Language_Context_create(&context);
    if (status) {
        return status;
    }
    Nucleus_Language_Context_destroy(context);
    return Nucleus_Language_Status_Success;
}

int main(int argc, char **argv)
{
    if (test()) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
