#include "Nucleus/DataLanguage/Import-setFileContents.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/Context_setFileContents.h"

DL_NonNull() void
DL_Context_setFileContentsStringBuffer
    (
        DL_Context *context,
        DL_String *pathname,
        DL_StringBuffer *contents
    )
{ Nucleus_Interpreter_Context_setFileContentsStringBuffer(context->context, pathname, contents); }

DL_NonNull() void
DL_Context_setFileContentsString
    (
        DL_Context *context,
        DL_String *pathname,
        DL_String *contents
    )
{ Nucleus_Interpreter_Context_setFileContentsString(context->context, pathname, contents); }
