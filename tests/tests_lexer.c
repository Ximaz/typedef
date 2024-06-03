/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** tests_lexer.c
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "lexer.h"

const char *JSDOC_INLINE = "/** @typedef {Object} Food @property {String} name @property {Number} price @typedef {Object} User @property {Number} id @property {String} name @property {Number | undefined} age (may be undefined for privacy reasons) @property {\"silver\" | \"gold\" | \"diamond\"} plan @property {Food[]} favorite_foods */";


TestSuite(lexer, .description = "Unit tests for lexer sub functions");

Test(lexer_match_keyword, test_impl)
{
    const char *jsdoc_inline = "@typedef";

    cr_assert(eq(int, TT_TYPEDEF, lexer_match_keyword(jsdoc_inline, 0)));
    cr_assert(eq(int, TT_TOTAL_COUNT, lexer_match_keyword(jsdoc_inline, 1)));
    cr_assert(eq(int, TT_TOTAL_COUNT, lexer_match_keyword(jsdoc_inline, 8)));
}

Test(lexer_trim, test_impl)
{
    const char *jsdoc_inline = "/**         @typedef  */    /*   @property */";

    cr_assert(eq(int, 12, lexer_trim(jsdoc_inline, 0)));
    cr_assert(eq(int, 12, lexer_trim(jsdoc_inline, 12)));
    cr_assert(eq(int, 13, lexer_trim(jsdoc_inline, 13)));
    cr_assert(eq(int, 14, lexer_trim(jsdoc_inline, 14)));
    cr_assert(eq(int, 33, lexer_trim(jsdoc_inline, 20)));
    cr_assert(eq(int, 45, lexer_trim(jsdoc_inline, 43)));
}

Test(trim_until_token, test_impl)
{
    const char *jsdoc_inline = " @typedef {import().Object}";

    cr_assert(eq(int, 1, trim_until_token(jsdoc_inline, 0)));
    cr_assert(eq(int, 10, trim_until_token(jsdoc_inline, 2)));
    cr_assert(eq(int, 11, trim_until_token(jsdoc_inline, 11)));
    cr_assert(eq(int, 26, trim_until_token(jsdoc_inline, 20)));
}


Test(count_tokens, test_impl)
{
    //                          0123456789ABCDEF0123456789ABCDEF0123456789
    const char *jsdoc_inline = "/** @typedef {import().Object} MyObject */";

    cr_assert(eq(int, 9, count_tokens(jsdoc_inline)));
}
