#include "Nucleus/Language.h"

Nucleus_Language_NoError() bool
Nucleus_Language_runMain
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Main *main,
        int numberOfArguments,
        char **arguments
    )
{
    Nucleus_Language_ErrorHandler errorHandler;
    Nucleus_Language_Context_pushErrorHandler(context, &errorHandler);
    if (!setjmp(errorHandler.environment))
    {
        (*main)(context, numberOfArguments, arguments);
        Nucleus_Language_Context_popErrorHandler(context);
        return true;
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context);
        return false;
    }
}