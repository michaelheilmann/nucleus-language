#include "Nucleus/Language/Forward.h"

#include <stdlib.h>

#if 0
Nucleus_Language_Status Nucleus_Language_Status_fromNucleus(Nucleus_Status status)
{
    switch (status)
    {
        case Nucleus_Status_Success:
            return Nucleus_Language_Status_Success;
        case Nucleus_Status_AllocationFailed:
            return Nucleus_Language_Status_AllocationFailed;
        case Nucleus_Status_InvalidArgument:
            return Nucleus_Language_Status_InvalidArgument;
        case Nucleus_Status_Overflow:
            return Nucleus_Language_Status_Overflow;
        case Nucleus_Status_InternalError:
            return Nucleus_Language_Status_InternalError;
        default:
        exit(EXIT_FAILURE);
    };
}
#endif
