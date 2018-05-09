// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/Token_Kind.h"

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Token_Kind_toString
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Token_Kind kind
    )
{
    switch (kind)
    {
    case Nucleus_DataLanguage_Token_Kind_Name:
        return Nucleus_Interpreter_String_create(context, "<name>", sizeof("<name>")-1); 
    case Nucleus_DataLanguage_Token_Kind_Colon:
        return Nucleus_Interpreter_String_create(context, "':'", sizeof("':'")-1);
    case Nucleus_DataLanguage_Token_Kind_Comma:
        return Nucleus_Interpreter_String_create(context, "','", sizeof("','")-1);
    case Nucleus_DataLanguage_Token_Kind_TrueLiteral:
        return Nucleus_Interpreter_String_create(context, "'true'", sizeof("'true'")-1);
    case Nucleus_DataLanguage_Token_Kind_FalseLiteral:
        return Nucleus_Interpreter_String_create(context, "'false'", sizeof("'false'")-1);
    case Nucleus_DataLanguage_Token_Kind_StringLiteral:
        return Nucleus_Interpreter_String_create(context, "<string>", sizeof("<string>")-1);
    case Nucleus_DataLanguage_Token_Kind_IntegerLiteral:
        return Nucleus_Interpreter_String_create(context, "<integer>", sizeof("<integer>")-1);
    case Nucleus_DataLanguage_Token_Kind_RealLiteral:
        return Nucleus_Interpreter_String_create(context, "<real>", sizeof("<real>")-1);
    case Nucleus_DataLanguage_Token_Kind_VoidLiteral:
        return Nucleus_Interpreter_String_create(context, "'void'", sizeof("'void'")-1);
    case Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter:
        return Nucleus_Interpreter_String_create(context, "'{'", sizeof("'{'")-1);
    case Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter:
        return Nucleus_Interpreter_String_create(context, "'}'", sizeof("'}'")-1);
    case Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter:
        return Nucleus_Interpreter_String_create(context, "'['", sizeof("'['")-1);
    case Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter:
        return Nucleus_Interpreter_String_create(context, "']'", sizeof("']'")-1);
    default:
		{
			Nucleus_Interpreter_ProcessContext_setStatus(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context), Nucleus_Interpreter_Status_UnreachableCodeReached);
			Nucleus_Interpreter_ProcessContext_jump(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
		}
    };
}
