// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/Scanner-private.c.i"

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Scanner *
Nucleus_DataLanguage_Scanner_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_Boolean skipComments
    )
{
    Nucleus_DataLanguage_Scanner *self = (Nucleus_DataLanguage_Scanner *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_Scanner));
    initialize(context, self, skipComments);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Token *
Nucleus_DataLanguage_Scanner_scan
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return scan(context, scanner); }

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Scanner_getSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return Nucleus_DataLanguage_SourceIterator_getSource(context, scanner->sourceIterator); }

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_setSource
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_Source *source
    )
{ Nucleus_DataLanguage_SourceIterator_setSource(context, scanner->sourceIterator, source); }

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_SourceLocation *
Nucleus_DataLanguage_Scanner_getSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return Nucleus_DataLanguage_SourceIterator_getSourceLocation(context, scanner->sourceIterator); }

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_setSourceLocation
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner,
        Nucleus_DataLanguage_SourceLocation *sourceLocation
    )
{ Nucleus_DataLanguage_SourceIterator_setSourceLocation(context, scanner->sourceIterator, sourceLocation); }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol
Nucleus_DataLanguage_Scanner_getSymbol
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ return Nucleus_DataLanguage_SourceIterator_getSymbol(context, scanner->sourceIterator); }

Nucleus_Interpreter_NonNull() void
Nucleus_DataLanguage_Scanner_increment
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Scanner *scanner
    )
{ Nucleus_DataLanguage_SourceIterator_increment(context, scanner->sourceIterator); }
