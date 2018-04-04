#include "Nucleus/DataLanguage/Import-Status.h"

DL_Status DL_Status_toInternal(Nucleus_Interpreter_Status status)
{
    switch (status)
    {
        case Nucleus_Interpreter_Status_Success:
            return DL_Status_Success;
        case Nucleus_Interpreter_Status_AllocationFailed:
            return DL_Status_AllocationFailed;
        case Nucleus_Interpreter_Status_InvalidArgument:
            return DL_Status_InvalidArgument;
        case Nucleus_Interpreter_Status_Overflow:
            return DL_Status_Overflow;
        case Nucleus_Interpreter_Status_InternalError:
        default:
            return DL_Status_InternalError;
    };
}
