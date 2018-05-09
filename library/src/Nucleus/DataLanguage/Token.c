// Copyright (c) 2017, 2018 Michael Heilmann
#include "Nucleus/DataLanguage/Token-private.c.i"

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Token_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token_Kind kind,
        Nucleus_DataLanguage_SourceLocation *begin,
        Nucleus_DataLanguage_SourceLocation *end,
        Nucleus_Interpreter_String *text
    )
{
    Nucleus_DataLanguage_Token *self = (Nucleus_DataLanguage_Token *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_Token));
    initialize(context, self, kind, begin, end, text);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getBegin
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->begin; }

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Token_getEnd
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->end; }

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token_Kind
Nucleus_DataLanguage_Token_getKind
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->kind; }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Token_getText
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token *token
    )
{ return token->text; }
