#include "Nucleus/DataLanguage/Source.h"

#include "Nucleus/DataLanguage/Context.h"

DL_NonNull() DL_Source *
DL_Source_create
    (
        DL_Context *context,
        DL_String *name,
        DL_String *string
    )
{
    DL_Source *self = (DL_Source *)DL_Context_allocateObject(context, sizeof(DL_Source));
    self->name = name;
    self->string = string;
    self->begin = DL_String_getBytes(context, string);
    self->end = DL_String_getBytes(context, string)
              + DL_String_getNumberOfBytes(context, string);
    return self;
}

DL_NonNull() DL_String *
DL_Source_getName
    (
        DL_Context *context,
        DL_Source *source
    )
{ return source->name; }

DL_NonNull() DL_String *
DL_Source_getString
    (
        DL_Context *context,
        DL_Source *source
    )
{ return source->string; }

DL_NonNull() const char *
DL_Source_getBegin
    (
        DL_Context *context,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, source);
    return source->begin;
}
DL_NonNull() size_t
DL_Source_getBeginOffset
    (
        DL_Context *context,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, source);
    return 0;
}

DL_NonNull() const char *
DL_Source_getEnd
    (
        DL_Context *context,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, source);
    return source->end;
}
DL_NonNull() size_t
DL_Source_getEndOffset
    (
        DL_Context *context,
        DL_Source *source
    )
{
    DL_Context_assertNotNull(context, source);
    return source->end - source->begin;
}

DL_NonNull() const char *
DL_Source_get
    (
        DL_Context *context,
        DL_Source *source,
        size_t index
    )
{
    DL_Context_assertNotNull(context, source);
    if (index >= DL_String_getNumberOfBytes(context, source->string)) DL_Context_raiseError(context, DL_Status_InvalidArgument);
    return source->begin + index;
}

DL_NonNull() DL_Source *
DL_Source_createDefault
    (
        DL_Context *context
    )
{
    DL_String *defaultName = DL_String_create(context, "<default source>", sizeof("<default source>")),
              *defaultString = DL_String_create(context, "", sizeof(""));
    DL_Source *defaultSource = DL_Source_create(context, defaultName, defaultString);
    return defaultSource;
}
