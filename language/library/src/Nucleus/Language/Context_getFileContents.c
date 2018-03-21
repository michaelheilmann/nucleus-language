/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/Language/Context_getFileContents.h"

#include "Nucleus/FileSystem.h"
#include "Nucleus/Memory.h"
#include "Nucleus/Language/Context.h"
#include "Nucleus/Language/String.h"
#include "Nucleus/Language/ErrorHandler.h"
#include "Nucleus/Language/StringBuffer.h"

typedef struct Context
{
    Nucleus_Language_Context *context;
    Nucleus_Language_StringBuffer *stringBuffer;
} Context;

Nucleus_NoError() Nucleus_NonNull() static Nucleus_Status
Callback
    (
        void *object,
        const char *bytes,
        size_t numberOfBytes
    );

Nucleus_Language_NoError() Nucleus_Language_NonNull() static Nucleus_Status
Callback
    (
        void *object,
        const char *bytes,
        size_t numberOfBytes
    )
{
    Context *context = (Context *)object;
    Nucleus_Language_ErrorHandler eh;
    Nucleus_Language_Context_pushErrorHandler(context->context, &eh);
    if (!setjmp(eh.environment))
    {
        Nucleus_Language_StringBuffer_append(context->context, context->stringBuffer, bytes, numberOfBytes);
        Nucleus_Language_Context_popErrorHandler(context->context);
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context->context);
        return Nucleus_Language_Context_getStatus(context->context);
    }
    return Nucleus_Language_Status_Success;
}

Nucleus_Language_NonNull() void
Nucleus_Language_Context_getFileContentsStringBuffer
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        Nucleus_Language_StringBuffer *stringBuffer
    )
{
    if (!pathname || !stringBuffer)
    {
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Status_InvalidArgument);
    }
    // (1) pathname in C-compatible format
    size_t n = Nucleus_Language_String_getNumberOfBytes(context, pathname);
    char *p = Nucleus_Language_Context_acquireScratchSpace(context, n + 1);
    Nucleus_copyMemory(p, Nucleus_Language_String_getBytes(context, pathname), n);
    p[n] = '\0';

    // (2) read file contents
    Context ctxt;
    ctxt.context = context;
    ctxt.stringBuffer = stringBuffer;
    Nucleus_getFileContentsExtendedCallbackFunction *cb = &Callback;
    Nucleus_Language_Status status = (Nucleus_Language_Status)Nucleus_getFileContentsExtended(p, &ctxt, cb);
    Nucleus_Language_Context_relinquishScratchSpace(context, p);
    if (status)
    {
        Nucleus_Language_Context_raiseError(context, status);
    }
}

Nucleus_Language_NonNull() Nucleus_Language_String *
Nucleus_Language_Context_getFileContentsString
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname
    )
{
    if (!pathname)
    {
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Status_InvalidArgument);
    }
    Nucleus_Language_ErrorHandler eh;
    // (1) Provide a string buffer.
    Nucleus_Language_StringBuffer stringBuffer;
    Nucleus_Language_StringBuffer_initialize(context, &stringBuffer, 256);
    // (2) Read the file contents into the string buffer.
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        Nucleus_Language_Context_getFileContentsStringBuffer(context, pathname, &stringBuffer);
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_StringBuffer_uninitialize(context, &stringBuffer);
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Context_getStatus(context));
    }
    // (3) Convert string buffer to string.
    Nucleus_Language_String *string = NULL;
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        string = Nucleus_Language_String_create(context, Nucleus_Language_StringBuffer_getBytes(context, &stringBuffer),
                                                Nucleus_Language_StringBuffer_getSize(context, &stringBuffer));
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_StringBuffer_uninitialize(context, &stringBuffer);
        Nucleus_Language_Context_raiseError(context, Nucleus_Language_Context_getStatus(context));
    }
    Nucleus_Language_StringBuffer_uninitialize(context, &stringBuffer);
    // Return the string.
    return string;
}
