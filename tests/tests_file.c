/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** tests_arg_parser.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "file.h"

TestSuite(file_read, .description = "File read unit tests");

Test(file_read, invalid_arguments)
{
    cr_assert(eq(ptr, NULL, file_read(NULL)));
    cr_assert(eq(ptr, NULL, file_read("invalid")));
    cr_assert(eq(ptr, NULL, file_read("tests/file_empty")));
    cr_assert(eq(int, 0, file_get_size("tests/file_read_empty")));
    cr_assert(eq(int, 0, file_get_size("invalid")));
}

Test(file_read, valid_arguments)
{
    char expected[2049] = { 0 };
    int fd = -1;
    unsigned int file_size = 0;
    char *buffer = NULL;
    const char *path = "tests/file_read_full";

    cr_assert(eq(int, 0, file_setup_read(path, &fd, &buffer, &file_size)));
    cr_assert(eq(int, 2048, file_size));
    cr_assert(ne(int, -1, fd));
    cr_assert(ne(ptr, NULL, buffer));
    memset(expected, 'A', 2048);
    cr_assert(eq(int, 0, file_read_content(fd, 1024, &buffer, 2048)));
    close(fd);
    cr_assert(eq(str, buffer, expected));
    free(buffer);
}
