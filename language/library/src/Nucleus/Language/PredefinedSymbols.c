#include "Nucleus/Language/PredefinedSymbols.h"

#include "Nucleus/Interpreter/Context.h"
#include "Nucleus/Language/UnicodeCodePoints.h"

#define DEFINE(CNAME, UNAME, VALUE) \
Nucleus_Interpreter_NonNull() Nucleus_Interpreter_Symbol \
Nucleus_Interpreter_Symbol_##CNAME \
    ( \
        Nucleus_Interpreter_Context *context \
    ) \
{ return Nucleus_Interpreter_Symbol_create_uint32(context, Nucleus_Language_##CNAME); }

#include "Nucleus/Language/UnicodeCodePoints.i"

#undef DEFINE
