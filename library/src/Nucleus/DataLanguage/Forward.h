/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Interpreter/Context.h"

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-Status.h"
#include "Nucleus/DataLanguage/Import-String.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"
#include "Nucleus/DataLanguage/Import-StringIterator.h"
#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-getFileContents.h"
#include "Nucleus/DataLanguage/Import-setFileContents.h"
#include "Nucleus/DataLanguage/Import-Boolean.h"
#include "Nucleus/DataLanguage/Import-JumpTarget.h"
#include "Nucleus/DataLanguage/Import-HeapObject.h"

#define DL_Context_assertNotNull(c, e) Nucleus_Interpreter_Context_assertNotNull((c)->context, e)

typedef struct DL_Context DL_Context;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source.
typedef struct DL_Source DL_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language line map.
typedef struct DL_LineMap DL_LineMap;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source location.
typedef struct DL_SourceLocation DL_SourceLocation;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source iterator.
typedef struct DL_SourceIterator DL_SourceIterator;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language scanner.
typedef struct DL_Scanner DL_Scanner;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language parser.
typedef struct DL_Parser DL_Parser;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Data Language token.
typedef struct DL_Token DL_Token;
