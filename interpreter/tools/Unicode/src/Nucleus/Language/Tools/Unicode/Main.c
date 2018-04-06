#include <stdlib.h>  // For atexit(), EXIT_SUCCESS and EXIT_FAILURE.
#include <stdio.h>   // For FILE, fopen(), fclose(), and fprintf().
#include <stdint.h>  // For uint32_t.
#include <string.h>  // For strdup().
#include <stdbool.h> // For bool.

#include "Nucleus/CommandLine.h"

typedef struct CodePoint
{
    const char *cname;
    const char *uname;
    uint32_t value;
} CodePoint;

/// @brief The list of code points.
static const CodePoint g_codePoints[] =
{
#define CODEPOINT(cname, uname, value) { cname, uname, value },

#include "Nucleus/Language/Tools/Unicode/CodePoints.i"

#undef CODEPOINT
}; // g_codePoints

/// @brief The number of code points in @a g_codePoints.
static const size_t g_numberOfCodePoints = sizeof(g_codePoints) / sizeof(CodePoint);

static Nucleus_CommandLine_Command *g_cmd = NULL;

static bool streq(const char *x, const char *y) { return (0 == strcmp(x, y)); }

static void atExit(void)
{
    if (g_cmd)
    {
        Nucleus_CommandLine_Command_destroy(g_cmd);
        g_cmd = NULL;
    }
}

int main(int argc, char **argv)
{
    Nucleus_Status status;

    // Register at exit function.
    if (atexit(&atExit))
    { fprintf(stderr, "atexit() failed\n"); exit(EXIT_FAILURE); }

    // Parse command.
    if (Nucleus_CommandLine_parse(&g_cmd, argc, argv))
    { exit(EXIT_FAILURE); }

    // Check number of arguments. Must be two (the input file, the output file).
    size_t n;
    if (Nucleus_CommandLine_Command_getParameterCount(g_cmd, &n))
    { exit(EXIT_FAILURE); }
    if (n < 2)
    {
        fprintf(stderr, "too few arguments\n");
        exit(EXIT_FAILURE);
    }

    // Assert "prefix=<string>" option is present and proper.
    Nucleus_CommandLine_Option *prefixOption;
    status = Nucleus_CommandLine_Command_getOption(g_cmd, "prefix", &prefixOption);
    if (status && status != Nucleus_Status_NotExists)
    {
        fprintf(stderr, "<internal error>\n");
        exit(EXIT_FAILURE);
    }
    if (status == Nucleus_Status_NotExists)
    {
        fprintf(stderr, "missing 'prefix' option\n");
        exit(EXIT_FAILURE);
    }
    if (Nucleus_CommandLine_Option_getParameterCount(prefixOption, &n))
    {
        exit(EXIT_FAILURE);
    }
    if (n != 1)
    {
        fprintf(stderr, "'prefix' option requires one parameter\n");
        exit(EXIT_FAILURE);
    }
    Nucleus_CommandLine_Parameter *prefixParameter;
    if (Nucleus_CommandLine_Option_getParameter(prefixOption, 0, &prefixParameter))
    {
        exit(EXIT_FAILURE);
    }
    const char *prefixParameterValue;
    if (Nucleus_CommandLine_Parameter_getValue(prefixParameter, &prefixParameterValue))
    { exit(EXIT_FAILURE); }
    fprintf(stdout, "prefix=%s\n", prefixParameterValue);

    // Assert "--generator=(inlay|header)" is present and proper.
    Nucleus_CommandLine_Option *generatorOption;
    status = Nucleus_CommandLine_Command_getOption(g_cmd, "generator", &generatorOption);
    if (status && status != Nucleus_Status_NotExists)
    {
        fprintf(stderr, "<internal error>\n");
        exit(EXIT_FAILURE);
    }
    if (status == Nucleus_Status_NotExists)
    {
        fprintf(stderr, "missing 'generator' option\n");
        exit(EXIT_FAILURE);
    }
    if (Nucleus_CommandLine_Option_getParameterCount(generatorOption, &n))
    {
        exit(EXIT_FAILURE);
    }
    if (n != 1)
    {
        fprintf(stderr, "'generator' option requires one parameter\n");
        exit(EXIT_FAILURE);
    }
    Nucleus_CommandLine_Parameter *generatorParameter;
    if (Nucleus_CommandLine_Option_getParameter(generatorOption, 0, &generatorParameter))
    { exit(EXIT_FAILURE); }
    const char *generatorParameterValue;
    if (Nucleus_CommandLine_Parameter_getValue(generatorParameter, &generatorParameterValue))
    { exit(EXIT_FAILURE); }
    fprintf(stdout, "generator=%s\n", generatorParameterValue);
    if (!streq(generatorParameterValue, "Inlay") && !streq(generatorParameterValue, "Header"))
    {
        fprintf(stderr, "'generator' option requires either 'Header' or 'Inlay'\n");
        exit(EXIT_FAILURE);
    }

    // Generate!
    Nucleus_CommandLine_Parameter *targetPathnameParameter;
    if (Nucleus_CommandLine_Command_getParameter(g_cmd, 1, &targetPathnameParameter))
    {
        exit(EXIT_FAILURE);
    }
    const char *targetPathnameParameterValue;
    if (Nucleus_CommandLine_Parameter_getValue(targetPathnameParameter, &targetPathnameParameterValue))
    { exit(EXIT_FAILURE); }
    FILE *target = fopen(targetPathnameParameterValue, "w");
    if (!target)
    { exit(EXIT_FAILURE); }
    if (streq(generatorParameterValue, "Inlay"))
    {
        fprintf(target, "/* Generated by Nucleus.Language.Tools.Unicode */\n");
        for (size_t i = 0, n = g_numberOfCodePoints; i < n; ++i)
        {
            const CodePoint *codePoint = &(g_codePoints[i]);
            fprintf(target, "%sDEFINE(%s, \"%s\", 0x%.4X)\n", prefixParameterValue,
                    codePoint->cname, codePoint->uname, codePoint->value);
        }
    }
    else if (streq(generatorParameterValue, "Header"))
    {
        fprintf(target, "/* Generated by Nucleus.Language.Tools.Unicode */\n");
        fprintf(target, "#pragma once\n\n");
        for (size_t i = 0, n = g_numberOfCodePoints; i < n; ++i)
        {
            const CodePoint *codePoint = &(g_codePoints[i]);
            fprintf(target, "#define %s%s 0x%.4X /* %s */\n", prefixParameterValue,
                    codePoint->cname, codePoint->value, codePoint->uname);
        }
    }
    fclose(target);
    return EXIT_SUCCESS;
}