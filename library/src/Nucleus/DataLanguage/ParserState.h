/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/DataLanguage/Forward.h"

DL_NonNull() DL_ParserState *
DL_ParserState_create
    (
        DL_Context *context,
        DL_ScannerState *scannerState
    );
