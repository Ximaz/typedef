/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "args_parser.h"
#include "file.h"

#ifndef UNIT_TESTS

static void usage(const char *program)
{
    printf(
        "USAGE :\n"
        "    %s <jsdoc_src_path.js> <types_folder>\n", program
    );
}

int main(int argc, const char *argv[])
{
    char *jsdoc_src = NULL;
    args_t args = { 0 };

    if (-1 == args_parser(&args, argc, argv)) {
        usage(*argv);
        return 0;
    }
    jsdoc_src = file_read(args.jsdoc_src_path);
    if (NULL == jsdoc_src) {
        printf("Unable to read the JSDoc file at '%s'.", args.jsdoc_src_path);
        return 0;
    }
    free(jsdoc_src);
    return 0;
}

#endif /* !UNIT_TESTS */
