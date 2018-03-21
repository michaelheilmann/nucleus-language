/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/Context.h"

DL_NoError() static DL_Status
convertStatus
    (
        Nucleus_Language_Status status
    );

/// @ingroup dl
/// @internal
/// @brief Initialize an @a (DL_Context2) object.
/// @param context a pointer to the @a (DL_Context2) object
/// @return #DL_Status_Success on success, a non-zero status code on failure
DL_NoError() DL_NonNull() static DL_Status
initialize
    (
        DL_Context *context
    );

/// @ingroup dl
/// @internal
/// @brief Uninitialize an @a (DL_Context2) object.
/// @param context a pointer to the @a (DL_Context2) object
DL_NoError() DL_NonNull() static void
uninitialize
    (
        DL_Context *context
    );

DL_NoError() DL_NonNull() static DL_Status
initialize
    (
        DL_Context *context
    )
{
    return convertStatus(Nucleus_Language_Context_create(&context->context));
}

DL_NoError() DL_NonNull() static void
uninitialize
    (
        DL_Context *context
    )
{
    Nucleus_Language_Context_destroy(context->context);
    context->context = NULL;
}

DL_NoError() static DL_Status
convertStatus
    (
        Nucleus_Language_Status status
    )
{
    switch (status)
    {
        case Nucleus_Language_Status_Success:
            return DL_Status_Success;
        case Nucleus_Language_Status_AllocationFailed:
            return DL_Status_AllocationFailed;
        case Nucleus_Language_Status_InvalidArgument:
            return DL_Status_InvalidArgument;
        case Nucleus_Language_Status_UnreachableCodeReached:
            return DL_Status_UnreachableCodeReached;
        case Nucleus_Language_Status_Overflow:
            return DL_Status_Overflow;
        case Nucleus_Language_Status_LexicalError:
            return DL_Status_LexicalError;
        case Nucleus_Language_Status_SyntacticalError:
            return DL_Status_SyntacticalError;
        case Nucleus_Language_Status_SemanticalError:
            return DL_Status_SemanticalError;
        case Nucleus_Language_Status_InternalError:
        default:
            return DL_Status_InternalError;
    };
}

DL_NonNull(1) DL_Status
DL_Context_create
    (
       DL_Context **context
    )
{
    if (!context)
    { return DL_Status_InvalidArgument; }
    DL_Context *temporary = malloc(sizeof(DL_Context));
    if (!temporary)
    { return DL_Status_AllocationFailed; }
    DL_Status status = initialize(temporary);
    if (status)
    {
        free(temporary);
        return status;
    }
    *context = temporary;
    return DL_Status_Success;
}

DL_NonNull() void
DL_Context_destroy
    (
        DL_Context *context
    )
{
    uninitialize(context);
    free(context);
}
