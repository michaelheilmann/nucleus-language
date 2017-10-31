#include "dl.h"
#include "UnitTesting.h"
#include <stdlib.h>

static DL_Status test()
{
    DL_Context *context;
    DL_Status status = DL_Context_create(&context);
    if (status) {
        return status;
    }
    DL_Context_destroy(context);
    return DL_Status_Success;
}

int main(int argc, char **argv)
{
    if (test()) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
