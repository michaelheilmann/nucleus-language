/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#pragma once

#include "DL/forward.h"

typedef struct DL_Token DL_Token;
struct DL_Token
{
    DL_Object __parent;
};

#if 0
#include "dl/string.h"

struct Nucleus_Language_Node
{
	Node *next;
	String *kind;
	String *value;
}; // struct Nucleus_Language_Node

DL_NonNull() Node *
Node_create
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		String *kind,
		String *value
	);
	
DL_NonNull() String *
Node_getKind
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		Node *node
	);
	
DL_NonNull() String *
Node_getValue
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		Node *node
	);
#endif
