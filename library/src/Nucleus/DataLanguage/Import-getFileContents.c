#include "Nucleus/DataLanguage/Import-getFileContents.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/Interpreter/getFileContents.h"

Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_getFileContentsStringBuffer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname,
        Nucleus_DataLanguage_StringBuffer *stringBuffer
    )
{ Nucleus_Interpreter_getFileContentsStringBuffer(context->context, pathname, stringBuffer); }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_getFileContentsString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *pathname
    )
{ return Nucleus_Interpreter_getFileContentsString(context->context, pathname); }
