/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Language/Forward.h"
#include "Nucleus/Language/Annotations.h"

Nucleus_Language_NonNull() void
Nucleus_Language_Context_setFileContentsStringBuffer
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        Nucleus_Language_StringBuffer *contents
    );

Nucleus_Language_NonNull() void
Nucleus_Language_Context_setFileContentsString
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_String *pathname,
        Nucleus_Language_String *contents
    );
