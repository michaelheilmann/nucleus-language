#pragma once

#include "Nucleus/Language/ErrorHandler.h"
#include "Nucleus/Language/Context.h"
#include "Nucleus/Language/String.h"
#include "Nucleus/Language/StringBuffer.h"
#include "Nucleus/Language/StringIterator.h"
#include "Nucleus/Language/Symbol.h"
#include "Nucleus/Language/Context_getFileContents.h"
#include "Nucleus/Language/Context_setFileContents.h"
#include "Nucleus/Language/UnitTesting.h"
#include "Nucleus/Language/HeapObject.h"

/// @brief The type of a Nucleus main function.
typedef void Nucleus_Language_Main(Nucleus_Language_Context *, int, char **);

/// @brief Execute a main function in an @a (Nucleus_Context) object.
/// @param context a pointer to the @a (Nucleus_Context) object
/// @param numberOfArguments, arguments the program arguments specified by the C ain function
/// @return @a true on success, @a false on failure
Nucleus_Language_NoError() bool
Nucleus_Language_runMain
    (
        Nucleus_Language_Context *context,
        Nucleus_Language_Main *main,
        int numberOfArguments,
        char **arguments
    );
