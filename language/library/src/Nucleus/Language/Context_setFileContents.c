/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/Language/Context_setFileContents.h"

#include "Nucleus/FileSystem.h"
#include "Nucleus/Memory.h"
#include "Nucleus/Language/Context.h"
#include "Nucleus/Language/String.h"
#include "Nucleus/Language/StringBuffer.h"

Nucleus_Language_NonNull() static void
setFileContents
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        const char *bytes,
        size_t numberOfBytes
    );

Nucleus_NonNull() static void
setFileContents
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        const char *bytes,
        size_t numberOfBytes
    )
{
    // (1) pathname in C-compatible format
    size_t n = Nucleus_Language_String_getNumberOfBytes(context, pathname);
    char *p = Nucleus_Language_Context_acquireScratchSpace(context, n + 1);
    Nucleus_copyMemory(p, Nucleus_Language_String_getBytes(context, pathname), n);
    p[n] = '\0';
    // (2) set file contents
    Nucleus_Language_Status status = (Nucleus_Language_Status)Nucleus_setFileContents(p, bytes, numberOfBytes);
    if (status)
    {
        Nucleus_Language_Context_raiseError(context, status);
    }
}

Nucleus_Language_NonNull() void
Nucleus_Language_Context_setFileContentsStringBuffer
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        Nucleus_Language_StringBuffer *contents
    )
{
    Nucleus_Language_Context_assertNotNull(context, pathname);
    Nucleus_Language_Context_assertNotNull(context, contents);
    setFileContents(context, pathname, Nucleus_Language_StringBuffer_getBytes(context, contents),
                                       Nucleus_Language_StringBuffer_getSize(context, contents));
}

Nucleus_Language_NonNull() void
Nucleus_Language_Context_setFileContentsString
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        Nucleus_Language_String *contents
    )
{
    Nucleus_Language_Context_assertNotNull(context, pathname);
    Nucleus_Language_Context_assertNotNull(context, contents);
    setFileContents(context, pathname, Nucleus_Language_String_getBytes(context, contents),
                                       Nucleus_Language_String_getNumberOfBytes(context, contents));
}
