#include "Nucleus/DataLanguage/Import-Object.h"

#include "Nucleus/DataLanguage/Context.h"

Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Type *
Nucleus_DataLanguage_getOrCreateForeignType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object_Finalize *finalize,
        Nucleus_DataLanguage_Object_Visit *visit
    )
{ return Nucleus_Interpreter_Object_getOrCreateForeignType(context->context, finalize, visit, NULL); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Type *
Nucleus_DataLanguage_Object_getType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    )
{ return Nucleus_Interpreter_Object_getType(context->context, object); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setType
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Type *type
    )
{ Nucleus_Interpreter_Object_setType(context->context, object, type); }
