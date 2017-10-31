#include "dl.h"
#include "nucleus-filesystem.h"
#include "UnitTesting.h"

static DL_Status testBase(size_t initialCapacity, size_t requiredFreeCapacity)
{
    DL_Context *context;
    DL_Status status = DL_Context_create(&context);
    if (status) {
        return status;
    }
    DL_JumpTarget jt;
    DL_StringBuffer stringBuffer;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        /// @remark Create a string buffer with initial capacity of @a initialCapacity.
        DL_StringBuffer_initialize(context, &stringBuffer, initialCapacity);
        DL_Context_popJumpTarget(context);
    }
    else
    {
        status = context->status;
        DL_Context_popJumpTarget(context);
        DL_Context_destroy(context);
        return status;
    }
    
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        /// @remark Assert the size is @a 0.
        UnitTest_AssertEqualTo(context, DL_StringBuffer_getSize(context, &stringBuffer), 0);
        /// @remark Assert the capacity is greater than or equal to @a initialCapacity.
        UnitTest_AssertGreaterThanOrEqualTo(context, DL_StringBuffer_getCapacity(context, &stringBuffer), initialCapacity);
        /// @remark Assert the free capacity is equal to <c>capacity - size</c>.
        UnitTest_AssertEqualTo(context,
                               DL_StringBuffer_getFreeCapacity(context, &stringBuffer),
                               DL_StringBuffer_getCapacity(context, &stringBuffer) -
                               DL_StringBuffer_getSize(context, &stringBuffer));
        /// @remark Ensure the free capacity is greater than or equal to @a requiredFreeCapacity.
        DL_StringBuffer_ensureFreeCapacity(context, &stringBuffer, requiredFreeCapacity);
        /// @remark Assert the size is @a 0.
        UnitTest_AssertEqualTo(context,
                               DL_StringBuffer_getSize(context, &stringBuffer),
                               0);
        /// @remark Assert the capacity is greater than @a requiredFreeCapacity.
        UnitTest_AssertGreaterThanOrEqualTo(context,
                                            DL_StringBuffer_getCapacity(context, &stringBuffer),
                                            requiredFreeCapacity);
        /// @remark Assert the free capacity is equal to <c>capacity - size</c>.
        UnitTest_AssertEqualTo(context,
                               DL_StringBuffer_getFreeCapacity(context, &stringBuffer),
                               DL_StringBuffer_getCapacity(context, &stringBuffer) -
                               DL_StringBuffer_getSize(context, &stringBuffer));
        DL_Context_popJumpTarget(context);
    }
    else
    {
        DL_Context_popJumpTarget(context);
        DL_StringBuffer_uninitialize(&stringBuffer);
        status = context->status;
        DL_Context_destroy(context);
        return status;
    }
    DL_StringBuffer_uninitialize(&stringBuffer);
    status = context->status;
    DL_Context_destroy(context);
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
