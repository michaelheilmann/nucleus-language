/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "DL/scanner.h"

#include "DL/context.h"
#include "DL/source.h"

#include <string.h>

DL_NonNull() void
DL_Scanner_initialize
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_StringTable *stringTable
    )
{
    if (!scanner || !stringTable)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    scanner->stringTable = stringTable;
    DL_StringBuffer_initialize(context, &scanner->stringBuffer, 512);
    scanner->tokenKind = DL_Token_Kind_Begin;
    DL_JumpTarget jt;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        scanner->source = DL_Source_create(context,
                                           DL_Context_createString(context, "<default source>", strlen("<default source>")),
                                           DL_Context_createString(context, "", strlen("")));
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringBuffer_uninitialize(&scanner->stringBuffer);
        DL_Context_raiseError(context, context->status);
    }
}

DL_NonNull() void
DL_Scanner_uninitialize
    (
        DL_Scanner *scanner
    )
{
    DL_StringBuffer_uninitialize(&scanner->stringBuffer);
}

DL_NonNull() void
DL_Scanner_setInput
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_Source *source
    )
{
    if (!scanner || !source)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    scanner->source = source;
    scanner->tokenKind = DL_Token_Kind_Begin;
}

DL_NonNull() DL_Source *
DL_Scanner_getSource
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return scanner->source; }
