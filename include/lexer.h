/*
** EPITECH PROJECT, 2024
** Typdef
** File description:
** lexer.h
*/

#ifndef __LEXER_H_
    #define __LEXER_H_

typedef enum e_token_type {
    TT_TYPEDEF,
    TT_PROPERTY,
    TT_LCBRACE,
    TT_IMPORT,
    TT_LPARENT,
    TT_RPARENT,
    TT_PERIOD,
    TT_TYPE,
    TT_LSBRACE,
    TT_RSBRACE,
    TT_UNION,
    TT_NUMBER,
    TT_BOOLEAN,
    TT_LITERAL,
    TT_RCBRACE,
    TT_IDENTIFIER,
    TT_TOTAL_COUNT
} token_type_t;

typedef struct s_token {
    token_type_t type;
    char *value;
} token_t;

typedef struct s_token_repr {
    token_type_t type;
    const char *repr;
    unsigned int length;
} token_repr_t;


__attribute__((unused)) static const token_repr_t TOKENS_REPR[TT_TOTAL_COUNT] =
{
    { TT_TYPEDEF, "@typedef", 8 },
    { TT_PROPERTY, "@property", 9 },
    { TT_LCBRACE, "{", 1 },
    { TT_IMPORT, "import", 6 },
    { TT_LPARENT, "(", 1 },
    { TT_RPARENT, ")", 1 },
    { TT_PERIOD, ".", 1 },
    { TT_TYPE, NULL, 0 },
    { TT_LSBRACE, "[", 1 },
    { TT_RSBRACE, "]", 1 },
    { TT_UNION, "|", 1 },
    { TT_NUMBER, NULL, 0 },
    { TT_BOOLEAN, NULL, 0 },
    { TT_LITERAL, NULL, 0 },
    { TT_RCBRACE, "}", 1 },
    { TT_IDENTIFIER, NULL, 0 }
};

token_type_t lexer_match_keyword(const char *source, unsigned int start);

unsigned int lexer_trim(const char *source, unsigned int start);

unsigned int trim_until_token(const char *source, unsigned int start);

unsigned int count_tokens(const char *source);

token_t *lexer(const char *source);

#endif /* !__LEXER_H_ */
