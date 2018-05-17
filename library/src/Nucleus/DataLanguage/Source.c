// Copyright (c) 2018 Michael Heilmann
#include "Nucleus/DataLanguage/Source.h"

#include "Nucleus/DataLanguage/LineMap.h"

static Nucleus_Interpreter_Type *g_type = NULL;

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *self
    );

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    );

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    );

Nucleus_Interpreter_NonNull() static void
visit
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *self
    )
{}

Nucleus_Interpreter_NoError() static void
finalizeType
    (
    )
{ g_type = NULL; }

Nucleus_Interpreter_ReturnNonNull() Nucleus_Interpreter_NonNull() static Nucleus_Interpreter_Type *
getOrCreateType
    (
        Nucleus_Interpreter_Context *context
    )
{
    if (!g_type)
    {
        g_type = Nucleus_Interpreter_getOrCreateForeignType
                    (
                        context,
                        NULL,
                        NUCLEUS_INTERPRETER_VISITFOREIGNOBJECT(&visit),
                        NUCLEUS_INTERPRETER_FINALIZETYPE(&finalizeType)
                    );
    }
    return g_type;
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_create
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_Interpreter_String *name,
        Nucleus_Interpreter_String *string
    )
{
    Nucleus_DataLanguage_Source *self = (Nucleus_DataLanguage_Source *)Nucleus_Interpreter_Context_allocateManaged(context, sizeof(Nucleus_DataLanguage_Source));
    self->name = name;
    self->string = string;
    self->lineMap = Nucleus_DataLanguage_LineMap_create(context, string);
    Nucleus_Interpreter_Type *type = getOrCreateType(context);
    Nucleus_Interpreter_Object_setType(context, NUCLEUS_INTERPRETER_OBJECT(self), type);
    return self;
}

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Source_getName
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{ return source->name; }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_String *
Nucleus_DataLanguage_Source_getString
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{ return source->string; }

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_Source_getBeginOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_Interpreter_Context_assertNotNull(context, source);
    return 0;
}

Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Size
Nucleus_DataLanguage_Source_getEndOffset
    (
        Nucleus_Interpreter_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_Interpreter_Context_assertNotNull(context, source);
    return Nucleus_Interpreter_String_getNumberOfBytes(context, source->string);
}

Nucleus_Interpreter_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_createDefault
    (
        Nucleus_Interpreter_Context *context
    )
{
    Nucleus_Interpreter_String *defaultName = Nucleus_Interpreter_String_create(context, "<default source>", sizeof("<default source>")),
              *defaultString = Nucleus_Interpreter_String_create(context, "", sizeof(""));
    Nucleus_DataLanguage_Source *defaultSource = Nucleus_DataLanguage_Source_create(context, defaultName, defaultString);
    return defaultSource;
}
