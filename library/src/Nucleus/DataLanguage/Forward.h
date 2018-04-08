/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "Nucleus/Interpreter/Context.h"

#include "Nucleus/DataLanguage/Import-Annotations.h"
#include "Nucleus/DataLanguage/Import-Status.h"
#include "Nucleus/DataLanguage/Import-StringBuffer.h"
#include "Nucleus/DataLanguage/Import-StringIterator.h"
#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-getFileContents.h"
#include "Nucleus/DataLanguage/Import-setFileContents.h"
#include "Nucleus/DataLanguage/Import-JumpTarget.h"
#include "Nucleus/DataLanguage/Import-Object.h"

typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source.
typedef struct Nucleus_DataLanguage_Source Nucleus_DataLanguage_Source;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language line map.
typedef struct DL_LineMap DL_LineMap;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source location.
typedef struct Nucleus_DataLanguage_SourceLocation Nucleus_DataLanguage_SourceLocation;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language source iterator.
typedef struct Nucleus_DataLanguage_SourceIterator Nucleus_DataLanguage_SourceIterator;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language scanner.
typedef struct Nucleus_DataLanguage_Scanner Nucleus_DataLanguage_Scanner;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Nucleus Data Language parser.
typedef struct Nucleus_DataLanguage_Parser Nucleus_DataLanguage_Parser;

/// @ingroup Nucleus-DataLanguage
/// @brief Type of a Data Language token.
typedef struct Nucleus_DataLanguage_Token Nucleus_DataLanguage_Token;
