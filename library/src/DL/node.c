/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#if 0
#include "DL/node.h"

DL_NonNull() Node *
Node_create
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		String *kind,
		String *value
	)
{
	Node *node = malloc(sizeof(Node));
	if (!node) longjmp(*environment, -1);
	node->kind = kind;
	node->value = value;
	return node;
}
	
DL_NonNull() String *
Node_getKind
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		Node *node
	)
{
	return node->kind;
}
	
DL_NonNull() String *
Node_getValue
	(
		jmp_buf *environment,
		Nucleus_Status *status,
		Node *node
	)
{
	return 	node->value;
}
#endif