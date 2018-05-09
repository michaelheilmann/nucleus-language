// Copyright (c) 2018 Michael Heilmann
#pragma once

#include "Nucleus/Interpreter/Annotations.h"
#include "Nucleus/Interpreter/Context.h"
#include "Nucleus/Interpreter/Conversions.h"
#include "Nucleus/Interpreter/getFileContents.h"
#include "Nucleus/Interpreter/JumpTarget.h"
#include "Nucleus/Interpreter/Object.h"
#include "Nucleus/Interpreter/PredefinedSymbols.h"
#include "Nucleus/Interpreter/Real.h"
#include "Nucleus/Interpreter/Status.h"
#include "Nucleus/Interpreter/String.h"
#include "Nucleus/Interpreter/StringBuffer.h"
#include "Nucleus/Interpreter/StringIterator.h"
#include "Nucleus/Interpreter/Symbol.h"
#include "Nucleus/Interpreter/UnitTesting.h"

// Forward declaration.
typedef struct Nucleus_DataLanguage_Context Nucleus_DataLanguage_Context;

/// @ingroup Nucleus-DataLanguage
/// @brief Status codes of this library.
#define Nucleus_DataLanguage_Status Nucleus_Interpreter_Status

#define Nucleus_DataLanguage_Status_Success Nucleus_Interpreter_Status_Success
#define Nucleus_DataLanguage_Status_AllocationFailed Nucleus_Interpreter_Status_AllocationFailed
#define Nucleus_DataLanguage_Status_InvalidArgument Nucleus_Interpreter_Status_InvalidArgument
#define Nucleus_DataLanguage_Status_UnreachableCodeReached Nucleus_Interpreter_Status_UnreachableCodeReached
#define Nucleus_DataLanguage_Status_Overflow Nucleus_Interpreter_Status_Overflow
#define Nucleus_DataLanguage_Status_LexicalError Nucleus_Interpreter_Status_LexicalError
#define Nucleus_DataLanguage_Status_SyntacticalError Nucleus_Interpreter_Status_SyntacticalError
#define Nucleus_DataLanguage_Status_SemanticalError Nucleus_Interpreter_Status_SemanticalError
#define Nucleus_DataLanguage_Status_InternalError Nucleus_Interpreter_Status_InternalError
#define Nucleus_DataLanguage_Status_EnvironmentFailed Nucleus_Interpreter_Status_EnvironmentFailed
#define Nucleus_DataLanguage_Status_ConversionFailed Nucleus_Interpreter_Status_ConversionFailed

Nucleus_DataLanguage_Status
Nucleus_DataLanguage_Status_toInternal
	(
		Nucleus_Interpreter_Status status
	);
