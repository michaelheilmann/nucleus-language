#include "Nucleus/DataLanguage/Import-setFileContents.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/Context_setFileContents.h"

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_setFileContentsStringBuffer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_StringBuffer *contents
    )
{ Nucleus_Interpreter_Context_setFileContentsStringBuffer(context->context, pathname, contents); }

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Context_setFileContentsString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_String *contents
    )
{ Nucleus_Interpreter_Context_setFileContentsString(context->context, pathname, contents); }
