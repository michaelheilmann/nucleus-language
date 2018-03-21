#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-String.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"

DL_NonNull() void
DL_Context_setFileContentsStringBuffer
    (
        DL_Context *context,
        DL_String *pathname,
        DL_StringBuffer *contents
    );

DL_NonNull() void
DL_Context_setFileContentsString
    (
        DL_Context *context,
        DL_String *pathname,
        DL_String *contents
    );
