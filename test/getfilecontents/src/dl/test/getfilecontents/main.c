#include "dl.h"
#include "nucleus-filesystem.h"
#include "UnitTesting.h"

typedef struct Context
{
    DL_Context *context;
    DL_StringBuffer *stringBuffer;
} Context;

Nucleus_NoError() Nucleus_NonNull() static Nucleus_Status
Callback
    (
        void *object,
        const char *bytes,
        size_t numberOfBytes
    );

Nucleus_NoError() Nucleus_NonNull() static Nucleus_Status
Callback
    (
        void *object,
        const char *bytes,
        size_t numberOfBytes
    )
{
    Context *context = (Context *)object;
    DL_JumpTarget jt;
    DL_Context_pushJumpTarget(context->context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_StringBuffer_append(context->context, context->stringBuffer, bytes, numberOfBytes);
        DL_Context_popJumpTarget(context->context);
    }
    else
    {
        DL_Context_popJumpTarget(context->context);
        return context->context->status;
    }
    return DL_Status_Success;
}

DL_NonNull() void
DL_Context_fileContentsToStringBuffer
    (
        DL_Context *context,
        DL_String *pathname,
        DL_StringBuffer *stringBuffer
    )
{
    if (!pathname || !stringBuffer)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    // (1) pathname in C-compatible format
    size_t n = DL_String_getNumberOfBytes(context, pathname);
    char *p = DL_Context_acquireScratchSpace(context, n + 1);
    memcpy(p, DL_String_getBytes(context, pathname), n);
    p[n] = '\0';

    // (2) read file contents
    Context ctxt;
    ctxt.context = context;
    ctxt.stringBuffer = stringBuffer;
    Nucleus_getFileContentsExtendedCallbackFunction *cb = &Callback;
    DL_Status status = (DL_Status)Nucleus_getFileContentsExtended(p, &ctxt, &cb);
    DL_Context_relinquishScratchSpace(context, p);
    if (status)
    {
        DL_Context_raiseError(context, status);
    }
}

/// @return the contents of the file
DL_NonNull() DL_String *
DL_Context_fileContentsToString
    (
        DL_Context *context,
        DL_String *pathname
    )
{
    if (!pathname)
    {
        DL_Context_raiseError(context, DL_Status_InvalidArgument);
    }
    DL_JumpTarget jt;
    // (1) Provide a string buffer.
    DL_StringBuffer stringBuffer;
    DL_StringBuffer_initialize(context, &stringBuffer, 256);
    // (2) Read the file contents into the string buffer.
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_Context_fileContentsToStringBuffer(context, pathname, &stringBuffer);
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringBuffer_uninitialize(&stringBuffer);
        DL_Context_raiseError(context, context->status);
    }
    // (3) Convert string buffer to string.
    DL_String *string = NULL;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        string = DL_Context_createString(context, DL_StringBuffer_getBytes(context, &stringBuffer),
                                                  DL_StringBuffer_getSize(context, &stringBuffer));
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringBuffer_uninitialize(&stringBuffer);
        DL_Context_raiseError(context, context->status);
    }
    DL_StringBuffer_uninitialize(&stringBuffer);
    // Return the string.
    return string;
}

static DL_Status test()
{
    DL_Context *context;
    DL_Status status = DL_Context_create(&context);
    if (status) {
        return status;
    }
    DL_JumpTarget jt;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_String *contents = DL_Context_getFileContentsToString(context, DL_Context_createString(context, "data/helloworld.txt",
                                                                                                  strlen("data/helloworld.txt")));
        DL_Context_popJumpTarget(context);
    }
    DL_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    return EXIT_SUCCESS;
}
