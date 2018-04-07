/// @author Michael Heilmann
/// @copyright Copyright (c) Michael Heilmann 2017, 2018
#include "Nucleus/DataLanguage/Token.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_DataLanguage_String *text
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self
    );

struct Nucleus_DataLanguage_Token
{
    Nucleus_DataLanguage_Object __parent;
    Nucleus_DataLanguage_Token_Kind kind;
    Nucleus_DataLanguage_SourceLocation *begin,
                      *end;
    Nucleus_DataLanguage_String *text;
};

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self
    )
{}

Nucleus_DataLanguage_NonNull() static void
initialize
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *self,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_DataLanguage_String *text
    )
{
    self->kind = kind;
    self->begin = begin;
    self->end = end;
    self->text = text;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Token_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_DataLanguage_String *text
    )
{
    Nucleus_DataLanguage_Token *self = (Nucleus_DataLanguage_Token *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(Nucleus_DataLanguage_Token));
    initialize(context, self, kind, begin, end, text);
    Nucleus_DataLanguage_Object_setVisitor(context, NUCLEUS_DATALANGUAGE_OBJECT(self),
                                           NUCLEUS_DATALANGUAGE_OBJECT_VISIT(&visit));
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getBegin
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->begin; }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getEnd
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->end; }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Token_Kind
Nucleus_DataLanguage_Token_getKind
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->kind; }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Token_getText
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->text; }
