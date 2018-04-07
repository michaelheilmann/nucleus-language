#pragma once

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-Boolean.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_setFileContentsStringBuffer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_StringBuffer *contents
    );

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_setFileContentsString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_String *contents
    );
