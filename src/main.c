/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** main.c
*/

#include <stdio.h>
#include "args_parser.h"

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
    args_t args = { 0 };

    if (-1 == args_parser(&args, argc, argv)) {
        usage(*argv);
        return 0;
    }
    return 0;
}

#endif /* !UNIT_TESTS */
