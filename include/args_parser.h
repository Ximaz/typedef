/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** args_parser.h
*/

#ifndef __ARGS_PARSER_H_
    #define __ARGS_PARSER_H_

typedef struct s_args {
    const char *jsdoc_src_path;
    const char *types_folder;
} args_t;

int args_parser(args_t *self, int argc, const char *argv[]);

#endif /* !__ARG_PARSER_H_ */
