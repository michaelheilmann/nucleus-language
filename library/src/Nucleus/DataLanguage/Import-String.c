#include "Nucleus/DataLanguage/Import-String.h"

#include "Nucleus/DataLanguage/Context.h"

DL_ReturnNonNull() DL_NonNull() DL_String *
DL_String_create(DL_Context *context, const char *bytes, size_t numberOfBytes)
{ return Nucleus_Language_String_create(context->context, bytes, numberOfBytes); }

DL_ReturnNonNull() DL_NonNull() const char *
DL_String_getBytes(DL_Context *context, DL_String *string)
{ return Nucleus_Language_String_getBytes(context->context, string); }

DL_NonNull() size_t
DL_String_getNumberOfBytes(DL_Context *context, DL_String *string)
{ return Nucleus_Language_String_getNumberOfBytes(context->context, string); }

DL_NonNull() bool
DL_String_equal(DL_Context *context, DL_String *first, DL_String *second)
{ return Nucleus_Language_String_equal(context->context, first, second); }

DL_ReturnNonNull() DL_NonNull() DL_String *
DL_String_concatenate(DL_Context *context, DL_String *first, DL_String *second)
{ return Nucleus_Language_String_concatenate(context->context, first, second); }
