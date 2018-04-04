#include "Nucleus/DataLanguage/Token_Kind.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Token_Kind_toString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Token_Kind kind
    )
{
    switch (kind)
    {
    case Nucleus_DataLanguage_Token_Kind_Name:
        return Nucleus_DataLanguage_String_create(context, "<name>", sizeof("<name>")-1); 
    case Nucleus_DataLanguage_Token_Kind_Colon:
        return Nucleus_DataLanguage_String_create(context, "':'", sizeof("':'")-1);
    case Nucleus_DataLanguage_Token_Kind_Comma:
        return Nucleus_DataLanguage_String_create(context, "','", sizeof("','")-1);
    case Nucleus_DataLanguage_Token_Kind_TrueLiteral:
        return Nucleus_DataLanguage_String_create(context, "'true'", sizeof("'true'")-1);
    case Nucleus_DataLanguage_Token_Kind_FalseLiteral:
        return Nucleus_DataLanguage_String_create(context, "'false'", sizeof("'false'")-1);
    case Nucleus_DataLanguage_Token_Kind_StringLiteral:
        return Nucleus_DataLanguage_String_create(context, "<string>", sizeof("<string>")-1);
    case Nucleus_DataLanguage_Token_Kind_IntegerLiteral:
        return Nucleus_DataLanguage_String_create(context, "<integer>", sizeof("<integer>")-1);
    case Nucleus_DataLanguage_Token_Kind_RealLiteral:
        return Nucleus_DataLanguage_String_create(context, "<real>", sizeof("<real>")-1);
    case Nucleus_DataLanguage_Token_Kind_VoidLiteral:
        return Nucleus_DataLanguage_String_create(context, "'void'", sizeof("'void'")-1);
    case Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter:
        return Nucleus_DataLanguage_String_create(context, "'{'", sizeof("'{'")-1);
    case Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter:
        return Nucleus_DataLanguage_String_create(context, "'}'", sizeof("'}'")-1);
    case Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter:
        return Nucleus_DataLanguage_String_create(context, "'['", sizeof("'['")-1);
    case Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter:
        return Nucleus_DataLanguage_String_create(context, "']'", sizeof("']'")-1);
    default:
        Nucleus_DataLanguage_Context_raiseError(context, Nucleus_DataLanguage_Status_UnreachableCodeReached);
    };
}
