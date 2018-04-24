// Copyright (c) Michael Heilmann 2018
#include "Nucleus/DataLanguage/Import-setFileContents.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/setFileContents.h"

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_setFileContentsStringBuffer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_StringBuffer *contents
    )
{ Nucleus_Interpreter_setFileContentsStringBuffer(context->context, pathname, contents); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_setFileContentsString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_String *contents
    )
{ Nucleus_Interpreter_setFileContentsString(context->context, pathname, contents); }
