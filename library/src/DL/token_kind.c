#include "DL/token_kind.h"

#include "DL/context.h"
#include <string.h>

DL_NonNull() DL_String *
DL_Token_Kind_toString
    (
        DL_Context *context,
        DL_Token_Kind kind
    )
{
    switch (kind)
    {
    case DL_Token_Kind_StructureElementAssignmentOperator:
        return DL_Context_createString(context, "':'", strlen("':'"));
    case DL_Token_Kind_ValueSeparator:
        return DL_Context_createString(context, "','", strlen("','"));
    case DL_Token_Kind_TrueLiteral:
        return DL_Context_createString(context, "'true'", strlen("'true'"));
    case DL_Token_Kind_FalseLiteral:
        return DL_Context_createString(context, "'false'", strlen("'false'"));
    case DL_Token_Kind_NullLiteral:
        return DL_Context_createString(context, "'null'", strlen("'null'"));
    case DL_Token_Kind_StringLiteral:
        return DL_Context_createString(context, "<string>", strlen("<string>"));
    case DL_Token_Kind_IntegerLiteral:
        return DL_Context_createString(context, "<integer>", strlen("<integer>"));
    case DL_Token_Kind_RealLiteral:
        return DL_Context_createString(context, "<real>", strlen("<real>"));
    case DL_Token_Kind_StructureOpeningDelimiter:
        return DL_Context_createString(context, "'{'", strlen("'{'"));
    case DL_Token_Kind_StructureClosingDelimiter:
        return DL_Context_createString(context, "'}'", strlen("'}'"));
    case DL_Token_Kind_ListOpeningDelimiter:
        return DL_Context_createString(context, "'['", strlen("'['"));
    case DL_Token_Kind_ListClosingDelimiter:
        return DL_Context_createString(context, "']'", strlen("']'"));
    default:
        DL_Context_raiseError(context, DL_Status_UnreachableCodeReached);
    };
}
