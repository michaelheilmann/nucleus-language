#include "Nucleus/Language.h"

static Nucleus_Language_Status testBase(size_t initialCapacity, size_t requiredFreeCapacity)
{
    Nucleus_Language_Context *context;
    Nucleus_Language_Status status = Nucleus_Language_Context_create(&context);
    if (status) {
        return status;
    }
    Nucleus_Language_ErrorHandler eh;
    Nucleus_Language_StringBuffer stringBuffer;
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        /// @remark Create a string buffer with initial capacity of @a initialCapacity.
        Nucleus_Language_StringBuffer_initialize(context, &stringBuffer, initialCapacity);
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        status = Nucleus_Language_Context_getStatus(context);
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_Context_destroy(context);
        return status;
    }
    
    Nucleus_Language_Context_pushErrorHandler(context, &eh);
    if (!setjmp(eh.environment))
    {
        /// @remark Assert the size is @a 0.
        Nucleus_Language_UnitTest_AssertEqualTo(context, Nucleus_Language_StringBuffer_getSize(context, &stringBuffer), 0);
        /// @remark Assert the capacity is greater than or equal to @a initialCapacity.
        Nucleus_Language_UnitTest_AssertGreaterThanOrEqualTo(context, Nucleus_Language_StringBuffer_getCapacity(context, &stringBuffer), initialCapacity);
        /// @remark Assert the free capacity is equal to <c>capacity - size</c>.
        Nucleus_Language_UnitTest_AssertEqualTo(context,
                                                Nucleus_Language_StringBuffer_getFreeCapacity(context, &stringBuffer),
                                                Nucleus_Language_StringBuffer_getCapacity(context, &stringBuffer) -
                                                Nucleus_Language_StringBuffer_getSize(context, &stringBuffer));
        /// @remark Ensure the free capacity is greater than or equal to @a requiredFreeCapacity.
        Nucleus_Language_StringBuffer_ensureFreeCapacity(context, &stringBuffer, requiredFreeCapacity);
        /// @remark Assert the size is @a 0.
        Nucleus_Language_UnitTest_AssertEqualTo(context,
                                                Nucleus_Language_StringBuffer_getSize(context, &stringBuffer),
                                                0);
        /// @remark Assert the capacity is greater than @a requiredFreeCapacity.
        Nucleus_Language_UnitTest_AssertGreaterThanOrEqualTo(context,
                                                             Nucleus_Language_StringBuffer_getCapacity(context, &stringBuffer),
                                                             requiredFreeCapacity);
        /// @remark Assert the free capacity is equal to <c>capacity - size</c>.
        Nucleus_Language_UnitTest_AssertEqualTo(context,
                                                Nucleus_Language_StringBuffer_getFreeCapacity(context, &stringBuffer),
                                                Nucleus_Language_StringBuffer_getCapacity(context, &stringBuffer) -
                                                Nucleus_Language_StringBuffer_getSize(context, &stringBuffer));
        Nucleus_Language_Context_popErrorHandler(context);
    }
    else
    {
        Nucleus_Language_Context_popErrorHandler(context);
        Nucleus_Language_StringBuffer_uninitialize(context, &stringBuffer);
        status = Nucleus_Language_Context_getStatus(context);
        Nucleus_Language_Context_destroy(context);
        return status;
    }
    Nucleus_Language_StringBuffer_uninitialize(context, &stringBuffer);
    status = Nucleus_Language_Context_getStatus(context);
    Nucleus_Language_Context_destroy(context);
    return status;
}

int main(int argc, char **argv)
{
    
    if (//
        testBase(0, 0) ||
        testBase(0, 1) ||
        testBase(1, 0) ||
        testBase(1, 1) ||
        //
        /*
        testBase(0, 0) ||
        */
        testBase(0, 8) ||
        /*
        testBase(1, 0) ||
        */
        testBase(1, 8))
        return EXIT_FAILURE;
    else return EXIT_SUCCESS;
}
