/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/Token.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Token *self,
        DL_Token_Kind kind,
        DL_SourceLocation *begin,
        DL_SourceLocation *end,
        DL_String *text
    );

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Token *self
    );

struct DL_Token
{
    DL_Object __parent;
    DL_Token_Kind kind;
    DL_SourceLocation *begin,
                      *end;
    DL_String *text;
};

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_Token *self
    )
{}

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_Token *self,
        DL_Token_Kind kind,
        DL_SourceLocation *begin,
        DL_SourceLocation *end,
        DL_String *text
    )
{
    self->kind = kind;
    self->begin = begin;
    self->end = end;
    self->text = text;
}

DL_NonNull() DL_Token *
DL_Token_create
    (
        DL_Context *context,
        DL_Token_Kind kind,
        DL_SourceLocation *begin,
        DL_SourceLocation *end,
        DL_String *text
    )
{
    DL_Token *self = (DL_Token *)DL_Context_allocateObject(context, sizeof(DL_Token));
    initialize(context, self, kind, begin, end, text);
    ((DL_Object *)self)->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_SourceLocation *
DL_Token_getBegin
    (
        DL_Context *context,
        DL_Token *token
    )
{ return token->begin; }

DL_NonNull() DL_SourceLocation *
DL_Token_getEnd
    (
        DL_Context *context,
        DL_Token *token
    )
{ return token->end; }

DL_NonNull() DL_Token_Kind
DL_Token_getKind
    (
        DL_Context *context,
        DL_Token *token
    )
{ return token->kind; }

DL_NonNull() DL_String *
DL_Token_getText
    (
        DL_Context *context,
        DL_Token *token
    )
{ return token->text; }
