#include "Nucleus/DataLanguage.h"

Nucleus_DataLanguage_NonNull() static void
testListOpeningDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_ListOpeningDelimiter);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "[", sizeof("[") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testListClosingDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_ListClosingDelimiter);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "]", sizeof("]") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testStructureOpeningDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_StructureOpeningDelimiter);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "{", sizeof("{") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testStructureClosingDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_StructureClosingDelimiter);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "}", sizeof("}") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testTrueLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_TrueLiteral);
    DL_UnitTest_AssertTrue(context,Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "true", sizeof("true") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testFalseLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_FalseLiteral);
    DL_UnitTest_AssertTrue(context,Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "false", sizeof("false") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testVoidLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_VoidLiteral);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "void", sizeof("void") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testStringLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_StringLiteral);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "Hello, World!\n", sizeof("Hello, World!\n") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testColon
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_Colon);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, ":", sizeof(":") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testComma
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_Comma);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, ",", sizeof(",") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testIntegerLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_IntegerLiteral);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "-218", sizeof("-218") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testRealLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_RealLiteral);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_String_equal(context, Nucleus_DataLanguage_Token_getText(context, token), Nucleus_DataLanguage_String_create(context, "-218.3e10", sizeof("-218.3e10") - 1)));

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testSingleLineComment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_Comment);

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull() static void
testMultiLineComment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{
    Nucleus_DataLanguage_Token *token;

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_Comment);

    token = Nucleus_DataLanguage_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Token_getKind(context, token) == Nucleus_DataLanguage_Token_Kind_End);
}

Nucleus_DataLanguage_NonNull(1) static Nucleus_DataLanguage_Status
test
    (
        const char *pathname,
        void (*test)(Nucleus_DataLanguage_Context *, Nucleus_DataLanguage_Scanner *)
    )
{
    Nucleus_DataLanguage_Context *context;
    Nucleus_DataLanguage_Status status = Nucleus_DataLanguage_Context_create(&context);
    if (status) { return status; }
    Nucleus_DataLanguage_JumpTarget jt;
    Nucleus_DataLanguage_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        Nucleus_DataLanguage_Scanner *scanner = Nucleus_DataLanguage_Scanner_create(context, false);
        Nucleus_DataLanguage_String *pathnameString = Nucleus_DataLanguage_String_create(context, pathname, strlen(pathname));
        Nucleus_DataLanguage_String *inputString = Nucleus_DataLanguage_getFileContentsString(context, pathnameString);
        Nucleus_DataLanguage_Source *source = Nucleus_DataLanguage_Source_create(context, pathnameString, inputString);
        Nucleus_DataLanguage_Scanner_setSource(context, scanner, source);
        DL_UnitTest_AssertTrue(context, Nucleus_DataLanguage_Symbol_equalTo(context, Nucleus_DataLanguage_Scanner_getSymbol(context, scanner), Nucleus_DataLanguage_Symbol_begin(context)));
        Nucleus_DataLanguage_Scanner_increment(context, scanner);
        (*test)(context, scanner);
    }
    Nucleus_DataLanguage_Context_popJumpTarget(context);
    status = Nucleus_DataLanguage_Context_getStatus(context);
    Nucleus_DataLanguage_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/trueLiteral.txt", &testTrueLiteral) ||
        test("data/falseLiteral.txt", &testFalseLiteral) ||
        test("data/voidLiteral.txt", &testVoidLiteral) ||
        test("data/listOpeningDelimiter.txt", &testListOpeningDelimiter) ||
        test("data/listClosingDelimiter.txt", &testListClosingDelimiter) ||
        test("data/structureOpeningDelimiter.txt", &testStructureOpeningDelimiter) ||
        test("data/structureClosingDelimiter.txt", &testStructureClosingDelimiter) ||
        test("data/colon.txt", &testColon) ||
        test("data/comma.txt", &testComma) ||
        test("data/stringLiterals.txt", &testStringLiterals) ||
        test("data/integerLiterals.txt", &testIntegerLiterals) ||
        test("data/realLiterals.txt", &testRealLiterals) ||
        test("data/singleLineComment.txt", &testSingleLineComment) ||
        test("data/multiLineComment.txt", &testMultiLineComment))
    { return EXIT_FAILURE; }
    else
    { return EXIT_SUCCESS; }
}
