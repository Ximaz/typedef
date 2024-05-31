/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** arg_parser.c
*/

#include <stddef.h>
#include <unistd.h>
#include "typedef/arg_parser.h"
#include "typedef/path.h"

int arg_parser(args_t *self, int argc, const char *argv[])
{
    if (NULL == self || 3 != argc || NULL == argv)
        return -1;
    if (0 == file_exists(argv[1]))
        return -1;
    if (-1 == mkdir_s(argv[2], 0644))
        return -1;
    self->jsdoc_src_path = argv[1];
    self->types_folder = argv[2];
    return 0;
}
