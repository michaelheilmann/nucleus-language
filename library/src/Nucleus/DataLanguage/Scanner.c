#include "Nucleus/DataLanguage/Scanner-private.c.i"

DL_NonNull() DL_Scanner *
DL_Scanner_create
    (
        DL_Context *context
    )
{
    DL_Scanner *self = (DL_Scanner *)DL_Context_allocateObject(context, sizeof(DL_Scanner));
    initialize(context, self);
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() DL_Token *
DL_Scanner_scan
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return scan(context, scanner); }

DL_NonNull() DL_Source *
DL_Scanner_getSource
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_SourceIterator_getSource(context, scanner->sourceIterator); }

DL_NonNull() void
DL_Scanner_setSource
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_Source *source
    )
{ DL_SourceIterator_setSource(context, scanner->sourceIterator, source); }

DL_NonNull() DL_SourceLocation *
DL_Scanner_getSourceLocation
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_SourceIterator_getSourceLocation(context, scanner->sourceIterator); }

DL_NonNull() void
DL_Scanner_setSourceLocation
    (
        DL_Context *context,
        DL_Scanner *scanner,
        DL_SourceLocation *sourceLocation
    )
{ DL_SourceIterator_setSourceLocation(context, scanner->sourceIterator, sourceLocation); }

DL_NonNull() DL_Symbol
DL_Scanner_getSymbol
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ return DL_SourceIterator_getSymbol(context, scanner->sourceIterator); }

DL_NonNull() void
DL_Scanner_increment
    (
        DL_Context *context,
        DL_Scanner *scanner
    )
{ DL_SourceIterator_increment(context, scanner->sourceIterator); }
