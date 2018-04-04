#include "Nucleus/DataLanguage.h"

DL_NonNull() static void
testListOpeningDelimiter
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_ListOpeningDelimiter);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "[", sizeof("[") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testListClosingDelimiter
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_ListClosingDelimiter);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "]", sizeof("]") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testStructureOpeningDelimiter
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_StructureOpeningDelimiter);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "{", sizeof("{") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testStructureClosingDelimiter
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_StructureClosingDelimiter);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "}", sizeof("}") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testTrueLiteral
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_TrueLiteral);
    DL_UnitTest_AssertTrue(context,DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "true", sizeof("true") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testFalseLiteral
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_FalseLiteral);
    DL_UnitTest_AssertTrue(context,DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "false", sizeof("false") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testNullLiteral
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_NullLiteral);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "null", sizeof("null") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testStringLiterals
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_StringLiteral);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "Hello, World!\n", sizeof("Hello, World!\n") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testColon
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_Colon);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, ":", sizeof(":") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testComma
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_Comma);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, ",", sizeof(",") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testIntegerLiterals
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_IntegerLiteral);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "-218", sizeof("-218") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testRealLiterals
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_RealLiteral);
    DL_UnitTest_AssertTrue(context, DL_String_equal(context, DL_Token_getText(context, token), DL_String_create(context, "-218.3e10", sizeof("-218.3e10") - 1)));

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testSingleLineComment
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_Comment);

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull() static void
testMultiLineComment
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Token *token;

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_Comment);

    token = DL_Scanner_scan(context, scanner);
    DL_UnitTest_AssertTrue(context, DL_Token_getKind(context, token) == DL_Token_Kind_End);
}

DL_NonNull(1) static DL_Status
test
    (
        const char *pathname,
        void (*test)(DL_Context *, DL_Scanner *)
    )
{
    DL_Context *context;
    DL_Status status = DL_Context_create(&context);
    if (status) { return status; }
    DL_JumpTarget jt;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        DL_Scanner *scanner = DL_Scanner_create(context);
        DL_String *pathnameString = DL_String_create(context, pathname,
                                                      strlen(pathname));
        DL_String *inputString = DL_Context_getFileContentsString(context, pathnameString);
        DL_Source *source = DL_Source_create(context, pathnameString, inputString);
        DL_Scanner_setSource(context, scanner, source);
        DL_UnitTest_AssertTrue(context, DL_Symbol_equal(context, DL_Scanner_getSymbol(context, scanner), DL_Symbol_begin(context)));
        DL_Scanner_increment(context, scanner);
        (*test)(context, scanner);
    }
    DL_Context_popJumpTarget(context);
    status = DL_Context_getStatus(context);
    DL_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/trueLiteral.txt", &testTrueLiteral) ||
        test("data/falseLiteral.txt", &testFalseLiteral) ||
        test("data/nullLiteral.txt", &testNullLiteral) ||
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
