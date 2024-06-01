/**
 * @typedef {Object} Food
 * @property {String} name
 * @property {Number} price
 *
 * @typedef {Object} User
 * @property {Number} id
 * @property {String} name
 * @property {Number | undefined} age (may be undefined for privacy reasons)
 * @property {"silver" | "gold" | "diamond"} plan
 * @property {Food[]} favorite_foods
 */

// This should not be considered by the lexer :

console.log("Hello, World !");

/**
 * @typedef {Object} Test
 *
 * @property {String} myString
 *
 *
 *
 * as many line as I need in here
 * @property {Number} myNumber
 *
 * until I hit another
 * @typedef {Object} Test2
 * @property {String | undefined} myOptString
 * @property {Number} [myOptNumber]
 */
