/*
** EPITECH PROJECT, 2024
** Typedef
** File description:
** parser.h
*/

#ifndef __PARSER_H_
    #define __PARSER_H_

/**
 * @brief A word about types themselves
 *
 * In JSDoc, it is possible to union many types, of different kind. Whether
 * literal strings, numbers, or native types. That being said, this would be
 * a perfectly valid property :
 *
 * `@property {1 | "string" | CustomType | Boolean | undefined} prop`
 *
 * It would be a pain for the developer to know what to expect as a result, but
 * we're not dicussing this.
 *
 * Either way, I think it's pretty reasonable to assume a maximum of
 * `MAX_TYPES_UNION` types union. So you can't have more than `MAX_TYPES_UNION`
 * "{... | ...}" for one property. If some GitHub issues are opened about this,
 * then the value might be increased, but for memory sake, this value seems ok
 * for now.
 *
 * This value may also be computed at lexing time, when we tokenize the jsdoc,
 * after the imports are resolved, in such way that we count all the
 * occurences of unique unions, getting a finite amount of both literals and
 * types, whether native or custom.
 *
 * For the sake of simplicity, we will stick to the `MAX_TYPES_UNION` approach.
 * Once we reach something usable and decent, we will port the second thought
 * to the project to make it more scalable.
 */

    #define MAX_TYPES_UNION 16

typedef enum e_type_kind {
    TK_LITERAL, // {"silver" | "gold" | "diamond"}, {0 | 1 | 10}
    TK_TYPE     // {Number}, {String}
} type_kind_t;

typedef struct s_type {
    type_kind_t kind;
    char *value;
} type_t;

/**
 * @brief Structure to represent a property.
 *
 * name: The property's name
 * value: The actual property's type : Object, String, Custom, undefined ?
 * optional: Represents whether or not the property is optional.
 *
 * There are two possible ways in order to set the optional attribute to 1 :
 * - The property is surrounded by square brackets (ex: `[property]`)
 * - The property's value ends by `| undefined`
 *
 * It's worth to note that the value might be an `import` result :
 * `@property {import("some/file/jsdoc_src.js").<type>}` property
 * In such case, the property's value will be the `<type>` if it's resolve was
 * successful by the pre-processor.
 *
 * The preprocessor will load the jsdoc_src entrypoint file, and retrieve all
 * the import to resolve. Thne, for each of them, the it will try to load them
 * into memory from top to bottom.
 *
 * If a resolve failed, the program throw and error and exit. Else, the
 * preprocessor will then concatenate all the loaded file into one single
 * contigus memory block. It will also erase all `import("some/jsdoc_src.js").`
 * occurences. That way, only the resolved type remains, and the parsing can
 * finally begin.
 *
 */

typedef struct s_property {
    char *name;
    type_t types[MAX_TYPES_UNION];
    int optional;
} property_t;

typedef struct s_typedef {
    char *name;
    property_t **properties;
} typedef_t;

#endif /* !__PARSER_H_ */
