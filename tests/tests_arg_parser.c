/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** tests_arg_parser.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "typedef/arg_parser.h"
#include "typedef/path.h"

const char *JS_SRC_PATH = "tests/jsdoc_src.js";
const char *TYPES_FOLDER = "tests/types/";

TestSuite(arg_parser, .description = "Argument parser unit tests");

Test(arg_parser, invalid_arguments)
{
    args_t args = {
        .jsdoc_src_path = (const char *) 0xabc,
        .types_folder = (const char *) 0xdef
    };
    const char *argv[3] = { 0 };

    cr_assert(eq(int, -1, arg_parser(&args, 2, argv)));
    cr_assert(eq(int, -1, arg_parser(&args, 4, argv)));
    cr_assert(eq(int, -1, arg_parser(NULL, 2, argv)));
    cr_assert(eq(int, -1, arg_parser(NULL, 4, argv)));
    cr_assert(eq(int, -1, arg_parser(&args, 3, NULL)));
    cr_assert(eq(int, -1, arg_parser(NULL, 3, NULL)));
    cr_assert(eq(ptr, (void *) 0xabc, (void *) args.jsdoc_src_path));
    cr_assert(eq(ptr, (void *) 0xdef, (void *) args.types_folder));
}

Test(arg_parser, invalid_file_path)
{
    args_t args = {
        .jsdoc_src_path = (const char *) 0xabc,
        .types_folder = (const char *) 0xdef
    };
    int argc = 3;
    const char *argv[3] = { "./typedef", "invalid", TYPES_FOLDER };

    cr_assert(eq(int, -1, arg_parser(&args, argc, argv)));
    cr_assert(eq(int, 0, directory_exists(TYPES_FOLDER)));
    cr_assert(eq(ptr, (void *) 0xabc, (void *) args.jsdoc_src_path));
    cr_assert(eq(ptr, (void *) 0xdef, (void *) args.types_folder));
}

Test(arg_parser, valid_arguments)
{
    args_t args = {
        .jsdoc_src_path = (const char *) 0xabc,
        .types_folder = (const char *) 0xdef
    };
    int argc = 3;
    const char *argv[3] = { "./typedef", JS_SRC_PATH, TYPES_FOLDER };

    cr_assert(eq(int, 0, arg_parser(&args, argc, argv)));
    cr_assert(eq(int, 1, directory_exists(TYPES_FOLDER)));
    cr_assert(eq(int, 0, rmdir_s(TYPES_FOLDER)));
    cr_assert(eq(ptr, (void *) JS_SRC_PATH, (void *) args.jsdoc_src_path));
    cr_assert(eq(ptr, (void *) TYPES_FOLDER, (void *) args.types_folder));
}
