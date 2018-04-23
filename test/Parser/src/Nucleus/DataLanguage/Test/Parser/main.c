#include "Nucleus/DataLanguage.h"

Nucleus_DataLanguage_NonNull(1) static Nucleus_DataLanguage_Status
test
    (
        const char *pathname
    )
{
    Nucleus_DataLanguage_Context *context;
    Nucleus_DataLanguage_Status status = Nucleus_DataLanguage_Context_create(&context);
    if (status) { return status; }
    Nucleus_DataLanguage_JumpTarget jt;
    Nucleus_DataLanguage_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        Nucleus_DataLanguage_Scanner *scanner = Nucleus_DataLanguage_Scanner_create(context, true);
        Nucleus_DataLanguage_Parser *parser = Nucleus_DataLanguage_Parser_create(context, scanner);
        Nucleus_DataLanguage_String *pathnameString = Nucleus_DataLanguage_String_create(context, pathname, strlen(pathname));
        Nucleus_DataLanguage_String *inputString = Nucleus_DataLanguage_getFileContentsString(context, pathnameString);
        Nucleus_DataLanguage_Source *source = Nucleus_DataLanguage_Source_create(context, pathnameString, inputString);
        Nucleus_DataLanguage_Parser_setSource(context, parser, source);
        Nucleus_DataLanguage_Parser_run(context, parser);
    }
    Nucleus_DataLanguage_Context_popJumpTarget(context);
    status = Nucleus_DataLanguage_Context_getStatus(context);
    Nucleus_DataLanguage_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    if (test("data/emptyStructure.txt") ||
        test("data/emptyList.txt") ||
        test("data/nonEmptyStructure.txt"))
    { return EXIT_FAILURE; }
    else
    { return EXIT_SUCCESS; }
}
