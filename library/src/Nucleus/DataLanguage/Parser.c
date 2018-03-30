#include "Nucleus/DataLanguage/Parser-private.c.i"

DL_ReturnNonNull() DL_Parser *
DL_Parser_create
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{
    DL_Parser *self = (DL_Parser *)DL_Context_allocateObject(context, sizeof(DL_Parser));
    initialize(context, self, scanner);
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_Source *
DL_Parser_getSource
    (
        DL_Context *context,
        DL_Parser *parser
    )
{ return DL_Scanner_getSource(context, parser->scanner); }

DL_NonNull() void
DL_Parser_setSource
    (
        DL_Context *context,
        DL_Parser *parser,
        DL_Source *source
    )
{ DL_Scanner_setSource(context, parser->scanner, source); }
