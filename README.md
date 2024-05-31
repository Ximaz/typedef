# Typedef

This project aims to convert a JSDoc type definition to an abstract object that
can be converted to another programming language. It may be a Python class, a
Javascript or a Typescript class, etc... based on plugins that community could
created for programming languages that I don't know.

# How to use

### Setup

```bash
# Clone the project locally :
git clone git@github.com:Ximaz/typedef

# Go inside the project's folder :
cd typedef

# Check that the project is ready-to-use by executing the tests.
# If it fails, for some reason, open an issue at this URL :
# https://github.com/Ximaz/typedef/issues
make tests_run

# Once all seems fine, you can build the project :
make
```

### Usage

Let's suppose I have such a definition inside a Javascript file :

```js
// User.js

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
```

Then you can use the `typedef` program as such :

```bash
./typedef User.js typings/
```

where `User.js` is refered to as the `jsdoc_src_path`, and the `typings/` as
the `types_folder`.

In this particular example, it will produce the following output :

```
user@localhost project % ls -1 typings
User.type # Contains both Food and User types
```

All types defined inside a file will only be accessible through that file. If
you want to separate those, you would have something like this :

```js
// Food.js

/**
 * @typedef {Object} Food
 * @property {String} name
 * @property {Number} price
 */
```

```js
// User.js

/** @typedef {import("./Food.js").Food} Food */

/**
 * @typedef {Object} User
 * @property {Number} id
 * @property {String} name
 * @property {Number | undefined} age (may be undefined for privacy reasons)
 * @property {"silver" | "gold" | "diamond"} plan
 * @property {Food[]} favorite_foods
 */
```

Therefore, the output would be :

```
user@localhost project % ls -1 typings
Food.type # Contains Food type
User.type # Contains User type
```

# Parser

The parser will only consider the following instructions.

### `@typedef`

The first parameter is the actual type that you would like to give to your type
name. It may be an `{Object}`, a `{Number[]}`, or even an import of another
custom type, from another file, as mentionned in the `# How to use` section :

```js
/** @typedef {Object} MyObject */
/** @typedef {Number[]} MyNumbers */
/** @typedef {import("...").Object} MyImportedObject */
```

### `@property`

This tag only concerns the `@typedef {Object}` statements, as it's the way to
declare your custom typed properties for your new object. Here is an example :

```js
/**
 * @typedef {Object} Student
 * @property {String} name
 * @property {Number} age
 * @property {String} email
 * @property {Number} grade
 */
```

You can declare a `@property` being optional in three different ways.

```js
/** @property {Type | undefined} prop */
/** @property {Type} [prop] */
/** @property {Type | undefined} [prop] */
```

all of them meaning that the `prop` property is optional, and it may not be
present inside the object. It's pretty common for inheritance-like `@typedef`s.
