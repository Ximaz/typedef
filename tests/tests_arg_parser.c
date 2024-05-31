/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** tests_arg_parser.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "typedef/arg_parser.h"

TestSuite(arg_parser, .description = "Argument parser unit tests");

Test(arg_parser, invalid_arguments)
{
    args_t args = {
        .jsdoc_src_path = (const char *) 0xabc,
        .intermediate_path = (const char *) 0xdef
    };
    const char *argv[3] = { 0 };

    cr_assert(eq(int, -1, arg_parser(&args, 2, argv)));
    cr_assert(eq(int, -1, arg_parser(&args, 4, argv)));
    cr_assert(eq(int, -1, arg_parser(NULL, 2, argv)));
    cr_assert(eq(int, -1, arg_parser(NULL, 4, argv)));
    cr_assert(eq(int, -1, arg_parser(&args, 3, NULL)));
    cr_assert(eq(int, -1, arg_parser(NULL, 3, NULL)));
    cr_assert(eq(ptr, (void *) 0xabc, (void *) args.jsdoc_src_path));
    cr_assert(eq(ptr, (void *) 0xdef, (void *) args.intermediate_path));
}
