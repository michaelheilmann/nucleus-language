#include "Nucleus/DataLanguage.h"
#include "Nucleus/DataLanguage/SourceIterator.h"

Nucleus_Interpreter_NonNull() static void
testListOpeningDelimiter
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testListClosingDelimiter
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testStructureOpeningDelimiter
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testStructureClosingDelimiter
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testTrueLiteral
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testFalseLiteral
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testVoidLiteral
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testStringLiterals
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testColon
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testComma
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testIntegerLiterals
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testRealLiterals
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testSingleLineComment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull() static void
testMultiLineComment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_SourceIterator *iterator
    )
{
}

Nucleus_Interpreter_NonNull(1) static Nucleus_DataLanguage_Status
test
    (
        const char *pathname,
        void (*test)(Nucleus_Interpreter_Context *, Nucleus_DataLanguage_SourceIterator *)
    )
{
    Nucleus_Interpreter_Context *context;
    Nucleus_Interpreter_Status status = Nucleus_Interpreter_Context_create(&context);
    if (status) { return status; }
    Nucleus_Interpreter_JumpTarget jt;
    Nucleus_Interpreter_ProcessContext_pushJumpTarget(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context), &jt);
    if (!setjmp(jt.environment))
    {
        Nucleus_Interpreter_String *pathnameString = Nucleus_Interpreter_String_create(context, pathname, strlen(pathname));
        Nucleus_Interpreter_String *inputString = Nucleus_Interpreter_getFileContentsString(context, pathnameString);
        Nucleus_DataLanguage_Source *source = Nucleus_DataLanguage_Source_create(context, pathnameString, inputString);
        Nucleus_DataLanguage_SourceIterator *sourceIterator = Nucleus_DataLanguage_SourceIterator_create(context);
        Nucleus_DataLanguage_SourceIterator_setSource(context, sourceIterator, source);
        (*test)(context, sourceIterator);
    }
    Nucleus_Interpreter_ProcessContext_popJumpTarget(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
    status = Nucleus_Interpreter_ProcessContext_getStatus(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
    Nucleus_Interpreter_Context_destroy(context);
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
