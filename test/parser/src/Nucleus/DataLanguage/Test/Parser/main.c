#include "Nucleus/DataLanguage.h"

DL_NonNull() static void
testEmptyStructure
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
    DL_ErrorHandler eh;
    DL_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
    #if 0
        //DL_ScannerState *scannerState = DL_ScannerState_create(context);
        //DL_Scanner *scanner = DL_Scanner_create(context, scannerState);
        DL_ParserState *parseState = DL_Parser_create(context);
        DL_String *pathnameString = DL_String_create(context, pathname,
                                                            strlen(pathname));
        DL_String *inputString = DL_Context_getFileContentsString(context, pathnameString);
        DL_Source *source = DL_Source_create(context, pathnameString, inputString);
        DL_ScannerState_setInput(context, scannerState, source);
        UnitTest_AssertTrue(context, DL_Symbol_equal(context, DL_ScannerState_getCurrentSymbol(context, scannerState), DL_Symbol_begin(context)));
        DL_ScannerState_increment(context, scannerState);
        (*test)(context, scanner);
    #endif
    }
    DL_Context_popErrorHandler(context);
    status = DL_Context_getStatus(context);
    DL_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/emptyStructure.txt", &testEmptyStructure))
    { return EXIT_FAILURE; }
    else
    { return EXIT_SUCCESS; }
}
