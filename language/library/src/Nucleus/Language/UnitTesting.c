#include "Nucleus/Language/UnitTesting.h"

Nucleus_Language_NoError() Nucleus_Language_NonNull() Nucleus_Language_Status
Nucleus_Language_UnitTest_run
    (
        void (*test)(Nucleus_Language_Context *)
    )
{
    Nucleus_Language_Context *context;
    Nucleus_Language_Status status = Nucleus_Language_Context_create(&context);
    if (status)
    { return status; }
    Nucleus_Language_ErrorHandler eh;
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    { (*test)(context); }
    Nucleus_Language_Context_popErrorHandler(context);
    status = Nucleus_Language_Context_getStatus(context);
    Nucleus_Language_Context_destroy(context);
    return status;
}
