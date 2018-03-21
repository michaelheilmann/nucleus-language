#include "Nucleus/DataLanguage/Token_Kind.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() DL_String *
DL_Token_Kind_toString
    (
        DL_Context *context,
        DL_Token_Kind kind
    )
{
    switch (kind)
    {
    case DL_Token_Kind_Colon:
        return DL_String_create(context, "':'", sizeof("':'")-1);
    case DL_Token_Kind_Comma:
        return DL_String_create(context, "','", sizeof("','")-1);
    case DL_Token_Kind_TrueLiteral:
        return DL_String_create(context, "'true'", sizeof("'true'")-1);
    case DL_Token_Kind_FalseLiteral:
        return DL_String_create(context, "'false'", sizeof("'false'")-1);
    case DL_Token_Kind_NullLiteral:
        return DL_String_create(context, "'null'", sizeof("'null'")-1);
    case DL_Token_Kind_StringLiteral:
        return DL_String_create(context, "<string>", sizeof("<string>")-1);
    case DL_Token_Kind_IntegerLiteral:
        return DL_String_create(context, "<integer>", sizeof("<integer>")-1);
    case DL_Token_Kind_RealLiteral:
        return DL_String_create(context, "<real>", sizeof("<real>")-1);
    case DL_Token_Kind_StructureOpeningDelimiter:
        return DL_String_create(context, "'{'", sizeof("'{'")-1);
    case DL_Token_Kind_StructureClosingDelimiter:
        return DL_String_create(context, "'}'", sizeof("'}'")-1);
    case DL_Token_Kind_ListOpeningDelimiter:
        return DL_String_create(context, "'['", sizeof("'['")-1);
    case DL_Token_Kind_ListClosingDelimiter:
        return DL_String_create(context, "']'", sizeof("']'")-1);
    default:
        DL_Context_raiseError(context, DL_Status_UnreachableCodeReached);
    };
}
