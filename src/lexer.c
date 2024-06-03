/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** lexer.c
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"

token_type_t lexer_match_keyword(const char *source, unsigned int start)
{
    int i = 0;
    token_repr_t repr = { 0 };

    for (; TT_TOTAL_COUNT > i; ++i) {
        repr = TOKENS_REPR[i];
        if (0 == repr.length)
            continue;
        if (0 == strncmp(repr.repr, &source[start], repr.length))
            return repr.type;
    }
    return TT_TOTAL_COUNT;
}

unsigned int lexer_trim(const char *source, unsigned int start)
{
    while (0 != source[start]) {
        if (NULL == strchr(" */", source[start]))
            return start;
        ++start;
    }
    return start;
}

unsigned int trim_until_token(const char *source, unsigned int start)
{
    while (0 != source[start] &&
    TT_TOTAL_COUNT == lexer_match_keyword(source, start))
        ++start;
    return start;
}

unsigned int count_tokens(const char *source)
{
    token_type_t type = 0;
    unsigned int count = 0;
    unsigned int start = 0;

    while (0 != source[start]) {
        start = lexer_trim(source, start);
        type = lexer_match_keyword(source, start);
        if (TT_TOTAL_COUNT != type) {
            ++count;
            start += TOKENS_REPR[type].length;
        } else {
            ++count;
            start = trim_until_token(source, start);
        }
    }
    return count;
}

token_t *lexer(const char *source)
{
    unsigned int tokens_count = count_tokens(source);
    token_t *tokens = calloc(tokens_count + 1, sizeof(token_t));

    if (NULL == tokens)
        return NULL;
    return tokens;
}
