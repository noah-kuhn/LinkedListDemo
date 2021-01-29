/*
 *  Hello! This code was written by Noah Kuhn.
 *
 *  When writing this demo for a linked list, I'm assuming the viewer has basically no knowledge
 *  of C, but has some experience with Java. I should also note, this demo is for understanding,
 *  not efficiency.
 *
 *  This file (list.h) is a header file for the linked list demo.
 *  Contents:
 *      - value_t union (line 21)
 *      - value_type_t enum (line 30)
 *      - node_t struct (line 39)
 *      - list_t struct (line 49)
 *      - function prototypes for lists (line 56)
 *
 */

/* This line includes the standard boolean library - C doesn't have booleans as a primitive, so we
   have to bring them in with a standard header file */
#include <stdbool.h> 

/* DEFINITION OF VALUE_T UNION */
/* Our linked list will contain four types of values: chars, ints, bools, or strings */
typedef union{
    char cval;
    int ival;
    bool bval;
    char *sval; /* in C, strings are represented by pointers to characters */
} value_t; /* it's fairly standard to end a type name with '_t' to denote that it is a custom type */

/* DEFINITION OF VALUE_TYPE_T ENUM */
/* Enums are just like in Java: sets of integers with names */
typedef enum{
    VAL_CHAR,
    VAL_INT,
    VAL_BOOL,
    VAL_STR,
    VAL_NONE = -1
} value_type_t; /* our nodes will contain these so they know their value's type */

/* DEFINITION OF NODE_T STRUCT */
/* Our list nodes will need to contain their values and point to their previous and next nodes */
typedef struct NODE{
    /* we have to use the type 'struct NODE' (declared on line 30) since we haven't defined node_t yet */
    struct NODE *prev;
    value_t val;
    value_type_t type;
    struct NODE *next;
} node_t; /* don't worry, node_t * is still a valid type for prev and next now that it's defined */

/* DEFINITION OF LIST_T STRUCT */
/* Our lists our doubly-linked and have a reference to the header node and an int size */
typedef struct{
    node_t *header;
    int size;
} list_t;

/* FUNCTION PROTOTYPES FOR LISTS */

/* list_new(): no parameters, return a pointer to a new list or NULL if space can't be allocated */
list_t *list_new();

/* list_free(): list * parameter, no return value; free all space used by this list */
void list_free(list_t *);

/* list_push(): value, value type, and list * parameters, no return value; add the value to the front of the list */
void list_push(value_t, value_type_t, list_t *);

/* list_append(): value, value type, and list * parameters, no return value; add the value to the end of the list */
void list_append(value_t, value_type_t, list_t *);

/* list_pop(): list * parameter, return the value from the front of the list and remove it */
value_t list_pop(list_t *);

/* list_remove_last(): list * parameter, return the value from the end of the list and remove it */
value_t list_remove_last(list_t *);

/* list_size(): list * parameter, return its size */
int list_size(list_t *);

/* list_get(): int and list * parameters, returns the value at the given index */
value_t list_get(int, list_t *);

/* list_get_type(): int and list * parameters, returns the value type at the given index */
value_type_t list_get_type(int, list_t *);

/* list_print(): list * parameter, no return value; print the given list */
void list_print(list_t *);