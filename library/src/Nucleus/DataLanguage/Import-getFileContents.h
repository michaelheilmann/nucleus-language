#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-String.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"

DL_NonNull() void
DL_Context_getFileContentsStringBuffer
    (
        DL_Context *context,
        DL_String *pathname,
        DL_StringBuffer *stringBuffer
    );

DL_NonNull() DL_String *
DL_Context_getFileContentsString
    (
        DL_Context *context,
        DL_String *pathname
    );
