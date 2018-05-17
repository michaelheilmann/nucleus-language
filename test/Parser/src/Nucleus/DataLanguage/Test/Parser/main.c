#include "Nucleus/DataLanguage.h"

Nucleus_Interpreter_NonNull(1) static Nucleus_DataLanguage_Status
test
    (
        const char *pathname
    )
{
    Nucleus_Interpreter_Context *context;
    Nucleus_Interpreter_Status status = Nucleus_Interpreter_Context_create(&context);
    if (status) { return status; }
    Nucleus_Interpreter_JumpTarget jt;
    Nucleus_Interpreter_ProcessContext_pushJumpTarget(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context), &jt);
    if (!setjmp(jt.environment))
    {
        Nucleus_DataLanguage_Scanner *scanner = Nucleus_DataLanguage_Scanner_create(context, true);
        Nucleus_DataLanguage_Parser *parser = Nucleus_DataLanguage_Parser_create(context, scanner);
        Nucleus_Interpreter_String *pathnameString = Nucleus_Interpreter_String_create(context, pathname, strlen(pathname));
        Nucleus_Interpreter_String *inputString = Nucleus_Interpreter_getFileContentsString(context, pathnameString);
        Nucleus_DataLanguage_Source *source = Nucleus_DataLanguage_Source_create(context, pathnameString, inputString);
        Nucleus_DataLanguage_Parser_setSource(context, parser, source);
        Nucleus_DataLanguage_Parser_run(context, parser);
    }
    Nucleus_Interpreter_ProcessContext_popJumpTarget(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
    status = Nucleus_Interpreter_ProcessContext_getStatus(NUCLEUS_INTERPRETER_PROCESSCONTEXT(context));
    Nucleus_Interpreter_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/emptyStructure.txt") ||
        test("data/emptyList.txt") ||
        test("data/nonEmptyStructure.txt"))
    { return EXIT_FAILURE; }
	return EXIT_SUCCESS;
}
