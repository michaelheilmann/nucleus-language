#include "Nucleus/DataLanguage/LineMap.h"

#include "Nucleus/DataLanguage/Import-Symbol.h"
#include "Nucleus/DataLanguage/Import-StringIterator.h"
#include "Nucleus/Memory.h"

#define MAX_LINES (5012)

DL_NonNull() static void
build
    (
        DL_Context *context,
        DL_String *source,
        size_t **lines,
        size_t *numberOfLines
    );

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_LineMap *lineMap,
        DL_String *source
    );

DL_NonNull() static void
build
    (
        DL_Context *context,
        DL_String *source,
        size_t **lines,
        size_t *numberOfLines
    )
{
    if (!source || !lines || !numberOfLines) DL_Context_raiseError(context, DL_Status_AllocationFailed);
    // Regardless of wether the file is empty, there is one source line (with line index 0) with start offset 0.
    // That is, the number of lines is always greater than or equal to 1.
    
    size_t *lines0;
    Nucleus_Status status;
    
    status = Nucleus_allocateArrayMemory((void **)&lines0, MAX_LINES, sizeof(size_t));
    if (status) DL_Context_raiseError(context, DL_Status_AllocationFailed);
    lines0[0] = 0;
    size_t lineIndex = 0; // The index of the first line.
    DL_JumpTarget jt;
    DL_Context_pushJumpTarget(context, &jt);
    if (!setjmp(jt.environment))
    {
        const DL_Symbol carriageReturn = DL_Symbol_carriageReturn(context),
            lineFeed = DL_Symbol_lineFeed(context),
            end = DL_Symbol_end(context);

        DL_StringIterator *sourceIterator = DL_StringIterator_create(context, source);
        DL_StringIterator_increment(context, sourceIterator);

        DL_Symbol currentSymbol = DL_StringIterator_get(context, sourceIterator);
        while (DL_Symbol_notEqual(context, end, currentSymbol))
        {
            // '\r', '\n', '\r\n'
            if (DL_Symbol_equal(context, carriageReturn, currentSymbol) ||
                DL_Symbol_equal(context, lineFeed, currentSymbol))
            {
                DL_StringIterator_increment(context, sourceIterator);

                DL_Symbol nextSymbol = DL_StringIterator_get(context, sourceIterator);
                if (DL_Symbol_equal(context, carriageReturn, currentSymbol) &&
                    DL_Symbol_equal(context, lineFeed, nextSymbol))
                {
                    DL_StringIterator_increment(context, sourceIterator);
                    nextSymbol = DL_StringIterator_get(context, sourceIterator);
                }
                currentSymbol = nextSymbol;
                lineIndex++;
                lines0[lineIndex] = DL_StringIterator_getOffset(context, sourceIterator);
            }
            else
            {
                DL_StringIterator_increment(context, sourceIterator);
                currentSymbol = DL_StringIterator_get(context, sourceIterator);
            }
        }
        DL_Context_popJumpTarget(context);
    } else {
        DL_Context_popJumpTarget(context);
        Nucleus_deallocateMemory(lines0);
        DL_Context_raiseError(context, DL_Context_getStatus(context));
    }
    // Regardless of wether the file is empty or not,
    // there is always
    status = Nucleus_reallocateArrayMemory((void **)&lines0, lineIndex + 1, sizeof(size_t));
    if (status)
    {
        Nucleus_deallocateMemory(lines0);
        DL_Context_raiseError(context, DL_Status_AllocationFailed);
    }
    *lines = lines0;
    *numberOfLines = lineIndex+1;
}

DL_NonNull() static void
initialize
    (
        DL_Context *context,
        DL_LineMap *lineMap,
        DL_String *source
    )
{
    lineMap->source = source;
    build(context, source, &lineMap->lines, &lineMap->numberOfLines);
}

DL_NonNull() static void
visit
    (
        DL_Context *context,
        DL_LineMap *lineMap
    )
{}

DL_NonNull() static void
finalize
    (
        DL_Context *context,
        DL_LineMap *lineMap
    )
{
    free(lineMap->lines);
    lineMap->lines = NULL;
}

DL_NonNull() DL_LineMap *
DL_LineMap_create
    (
        DL_Context *context,
        DL_String *source
    )
{
    DL_LineMap *self = (DL_LineMap *)DL_Context_allocateObject(context, sizeof(DL_LineMap));
    initialize(context, self, source);
    ((DL_Object *)(self))->finalize = (DL_Visit *)&finalize;
    ((DL_Object *)(self))->visit = (DL_Visit *)&visit;
    return self;
}

DL_NonNull() size_t
DL_LineMap_getLineIndex
    (
        DL_Context *context,
        DL_LineMap *lineMap,
        size_t offset
    )
{
    size_t l = 0,
           r = (lineMap->numberOfLines) - 1;
    while (l <= r)
    {
        size_t m = (l + r) / 2;
        size_t o = lineMap->lines[m];
        if (offset > o)
            l = m + 1;
        else if (offset < o)
            r = m - 1;
        else
            return m;
    }
    return l;
}
