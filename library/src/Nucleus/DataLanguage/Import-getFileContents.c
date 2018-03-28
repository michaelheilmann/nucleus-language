#include "Nucleus/DataLanguage/Import-getFileContents.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() void
DL_Context_getFileContentsStringBuffer
    (
        DL_Context *context,
        DL_String *pathname,
        DL_StringBuffer *stringBuffer
    )
{ Nucleus_Language_Context_getFileContentsStringBuffer(context->context, pathname, stringBuffer); }

DL_NonNull() DL_String *
DL_Context_getFileContentsString
    (
        DL_Context *context,
        DL_String *pathname
    )
{ return Nucleus_Language_Context_getFileContentsString(context->context, pathname); }