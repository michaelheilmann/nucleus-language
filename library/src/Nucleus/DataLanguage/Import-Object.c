#include "Nucleus/DataLanguage/Import-Object.h"

#include "Nucleus/DataLanguage/Context.h"
    
Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Finalize *
Nucleus_DataLanguage_Object_getFinalizer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    )
{ return Nucleus_Interpreter_Object_getFinalizer(context->context, object); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setFinalizer
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Finalize *finalize
    )
{ Nucleus_Interpreter_Object_setFinalizer(context->context, object, finalize); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() Nucleus_DataLanguage_Object_Visit *
Nucleus_DataLanguage_Object_getVisitor
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object
    )
{ return Nucleus_Interpreter_Object_getVisitor(context->context, object); }

Nucleus_DataLanguage_NoError() Nucleus_DataLanguage_NonNull() void
Nucleus_DataLanguage_Object_setVisitor
    (
        Nucleus_DataLanguage_Context *context,
        Nucleus_DataLanguage_Object *object,
        Nucleus_DataLanguage_Object_Visit *visitor
    )
{ return Nucleus_Interpreter_Object_setVisitor(context->context, object, visitor); }
