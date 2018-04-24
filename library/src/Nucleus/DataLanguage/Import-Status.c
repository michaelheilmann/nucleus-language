// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/Import-Status.h"

Nucleus_DataLanguage_Status Nucleus_DataLanguage_Status_toInternal(Nucleus_Interpreter_Status status)
{
    switch (status)
    {
        case Nucleus_Interpreter_Status_Success:
            return Nucleus_DataLanguage_Status_Success;
        case Nucleus_Interpreter_Status_AllocationFailed:
            return Nucleus_DataLanguage_Status_AllocationFailed;
        case Nucleus_Interpreter_Status_InvalidArgument:
            return Nucleus_DataLanguage_Status_InvalidArgument;
        case Nucleus_Interpreter_Status_Overflow:
            return Nucleus_DataLanguage_Status_Overflow;
        case Nucleus_Interpreter_Status_InternalError:
        default:
            return Nucleus_DataLanguage_Status_InternalError;
    };
}
