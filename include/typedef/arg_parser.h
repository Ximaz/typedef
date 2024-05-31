/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** arg_parser.h
*/

#ifndef __ARG_PARSER_H_
    #define __ARG_PARSER_H_

typedef struct s_args {
    const char *jsdoc_src_path;
    const char *intermediate_path;
} args_t;

int arg_parser(args_t *self, int argc, const char *argv[]);

#endif /* !__ARG_PARSER_H_ */
