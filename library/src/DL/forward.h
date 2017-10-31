/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "nucleus-annotations.h"
#include <setjmp.h>
#include <stdbool.h>

typedef bool DL_Boolean;
#define DL_True (true)
#define DL_False (false)

typedef struct DL_Object DL_Object;
struct DL_Object
{
    DL_Object *next;
    void (*visit)(DL_Object *);
    void (*finalize)(DL_Object *);
}; // struct DL_Object

/// @ingroup dl
/// @internal
/// @brief Alias for Nucleus_NonNull.
#define DL_NonNull Nucleus_NonNull

/// @ingroup dl
/// @brief Status codes of this library.
typedef enum DL_Status DL_Status;

enum DL_Status
{
    /// @brief Status code indicating success.
    /// @invariant This is the only status code with the value @a 0.
    DL_Status_Success = 0,
    /// 
    DL_Status_InvalidArgument,
    DL_Status_AllocationFailed,
    DL_Status_UnreachableCodeReached,
}; // enum DL_Status

/// @ingroup dl
/// @brief A DL string.
typedef struct DL_String DL_String;

/// @ingroup dll
/// @brief A DL string table.
typedef struct DL_StringTable DL_StringTable;

/// @ingroup dl
/// @brief A DL source.
typedef struct DL_Source DL_Source;

/// @ingroup dll
/// @brief A DL context.
typedef struct DL_Context DL_Context;

/// @ingroup dll
/// @brief A DL scanner.
typedef struct DL_Scanner DL_Scanner;

/// @ingroup dll
/// @brief A DL parser.
typedef struct DL_Parser DL_Parser;

/// @ingroup dll
typedef struct DL_StringBuffer DL_StringBuffer;
