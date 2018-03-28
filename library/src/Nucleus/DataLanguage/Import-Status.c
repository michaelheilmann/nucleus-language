#include "Nucleus/DataLanguage/Import-Status.h"

DL_Status DL_Status_toInternal(Nucleus_Language_Status status)
{
    switch (status)
    {
        case Nucleus_Language_Status_Success:
            return DL_Status_Success;
        case Nucleus_Language_Status_AllocationFailed:
            return DL_Status_AllocationFailed;
        case Nucleus_Language_Status_InvalidArgument:
            return DL_Status_InvalidArgument;
        case Nucleus_Language_Status_Overflow:
            return DL_Status_Overflow;
        default:
            exit(EXIT_FAILURE);
    };
}
