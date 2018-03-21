/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Language.h"

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-Status.h"
#include "Nucleus/DataLanguage/Import-String.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"
#include "Nucleus/DataLanguage/Import-StringIterator.h"
#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-getFileContents.h"
#include "Nucleus/DataLanguage/Import-setFileContents.h"
#include "Nucleus/DataLanguage/Import-Boolean.h"

#define DL_Context_assertNotNull(c, e) Nucleus_Language_Context_assertNotNull((c)->context, e)

typedef Nucleus_Language_ErrorHandler DL_ErrorHandler;
typedef struct DL_Context DL_Context;

typedef Nucleus_Language_Object DL_Object;
#define DL_Finalize Nucleus_Language_Finalize
#define DL_Visit Nucleus_Language_Visit

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source.
typedef struct DL_Source DL_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source location.
typedef struct DL_SourceLocation DL_SourceLocation;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language scanner state.
typedef struct DL_ScannerState DL_ScannerState;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language parser state.
typedef struct DL_ParserState DL_ParserState;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Data Language token.
typedef struct DL_Token DL_Token;
