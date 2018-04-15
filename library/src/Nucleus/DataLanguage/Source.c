#include "Nucleus/DataLanguage/Source.h"

#include "Nucleus/DataLanguage/Context.h"
#include "Nucleus/DataLanguage/LineMap.h"

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *self
    );

Nucleus_DataLanguage_NonNull() static void
visit
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *self
    )
{}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_create
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_String *name,
        Nucleus_DataLanguage_String *string
    )
{
    Nucleus_DataLanguage_Source *self = (Nucleus_DataLanguage_Source *)Nucleus_DataLanguage_Context_allocateObject(context, sizeof(Nucleus_DataLanguage_Source));
    self->name = name;
    self->string = string;
    self->lineMap = DL_LineMap_create(context, string);
    Nucleus_DataLanguage_Object_Type *type = Nucleus_DataLanguage_getOrCreateForeignType
        (
            context,
            NULL,
            NUCLEUS_DATALANGUAGE_OBJECT_VISIT(&visit)
        );
    Nucleus_DataLanguage_Object_setType(context, NUCLEUS_DATALANGUAGE_OBJECT(self), type);
    return self;
}

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Source_getName
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{ return source->name; }

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_String *
Nucleus_DataLanguage_Source_getString
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{ return source->string; }

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_Source_getBeginOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_DataLanguage_Context_assertNotNull(context, source);
    return 0;
}

Nucleus_DataLanguage_NonNull() size_t
Nucleus_DataLanguage_Source_getEndOffset
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Source *source
    )
{
    Nucleus_DataLanguage_Context_assertNotNull(context, source);
    return Nucleus_DataLanguage_String_getNumberOfBytes(context, source->string);
}


Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Source *
Nucleus_DataLanguage_Source_createDefault
    (
        Nucleus_DataLanguage_Context *context
    )
{
    Nucleus_DataLanguage_String *defaultName = Nucleus_DataLanguage_String_create(context, "<default source>", sizeof("<default source>")),
              *defaultString = Nucleus_DataLanguage_String_create(context, "", sizeof(""));
    Nucleus_DataLanguage_Source *defaultSource = Nucleus_DataLanguage_Source_create(context, defaultName, defaultString);
    return defaultSource;
}
