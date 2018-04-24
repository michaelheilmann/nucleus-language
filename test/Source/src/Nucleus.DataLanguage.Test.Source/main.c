#include "Nucleus/DataLanguage.h"

Nucleus_DataLanguage_NonNull() static void
testListOpeningDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testListClosingDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testStructureOpeningDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testStructureClosingDelimiter
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testTrueLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testFalseLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testVoidLiteral
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testStringLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testColon
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testComma
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testIntegerLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testRealLiterals
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testSingleLineComment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull() static void
testMultiLineComment
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
}

Nucleus_DataLanguage_NonNull(1) static Nucleus_DataLanguage_Status
test
    (
        const char *pathname,
        void (*test)(Nucleus_DataLanguage_Context *, Nucleus_DataLanguage_Source *)
    )
{
    Nucleus_DataLanguage_Context *context;
    Nucleus_DataLanguage_Status status = Nucleus_DataLanguage_Context_create(&context);
    if (status) { return status; }
    Nucleus_DataLanguage_JumpTarget jt;
    Nucleus_DataLanguage_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        Nucleus_DataLanguage_String *pathnameString = Nucleus_DataLanguage_String_create(context, pathname, strlen(pathname));
        Nucleus_DataLanguage_String *inputString = Nucleus_DataLanguage_getFileContentsString(context, pathnameString);
        Nucleus_DataLanguage_Source *source = Nucleus_DataLanguage_Source_create(context, pathnameString, inputString);
        (*test)(context, source);
    }
    Nucleus_DataLanguage_Context_popJumpTarget(context);
    status = Nucleus_DataLanguage_Context_getStatus(context);
    Nucleus_DataLanguage_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/voidLiteral.txt", &testVoidLiteral) ||
        test("data/colon.txt", &testColon) ||
        test("data/comma.txt", &testComma) ||
        test("data/stringLiterals.txt", &testStringLiterals) ||
        test("data/integerLiterals.txt", &testIntegerLiterals) ||
        test("data/realLiterals.txt", &testRealLiterals) ||
        test("data/singleLineComment.txt", &testSingleLineComment) ||
        test("data/multiLineComment.txt", &testMultiLineComment))
    { return EXIT_FAILURE; }

    if (test("data/listOpeningDelimiter.txt", &testListOpeningDelimiter) ||
        test("data/listClosingDelimiter.txt", &testListClosingDelimiter))
    { return EXIT_FAILURE; }

    if (test("data/trueLiteral.txt", &testTrueLiteral) ||
        test("data/falseLiteral.txt", &testFalseLiteral))
    { return EXIT_FAILURE; }

    if (test("data/structureOpeningDelimiter.txt", &testStructureOpeningDelimiter) ||
        test("data/structureClosingDelimiter.txt", &testStructureClosingDelimiter))
    { return EXIT_FAILURE; }

    return EXIT_SUCCESS;
}
