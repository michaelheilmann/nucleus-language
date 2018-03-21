#include "Nucleus/Language.h"

static void emptyString(Nucleus_Language_Context *context)
{
        Nucleus_Language_String *w = Nucleus_Language_String_create(context, "", strlen(""));
        Nucleus_Language_StringIterator *it = Nucleus_Language_StringIterator_create(context, w);
        Nucleus_Language_UnitTest_AssertTrue(context, Nucleus_Language_Symbol_equal(context, Nucleus_Language_Symbol_begin(context),
                                                                                    Nucleus_Language_StringIterator_get(context, it)));
        Nucleus_Language_StringIterator_increment(context, it);
        Nucleus_Language_UnitTest_AssertTrue(context, Nucleus_Language_Symbol_equal(context, Nucleus_Language_Symbol_end(context),
                                                                                    Nucleus_Language_StringIterator_get(context, it)));
}

int main(int argc, char **argv)
{
    if (Nucleus_Language_UnitTest_run(&emptyString)) return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
