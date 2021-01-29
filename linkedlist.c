/*
 *  Hello! This code was written by Noah Kuhn.
 *
 *  When writing this demo for a linked list, I'm assuming the viewer has basically no knowledge
 *  of C, but has some experience with Java. I should also note, this demo is for understanding,
 *  not efficiency.
 *
 *  This file (linkedlist.c) is the C file for the linked list demo. It has the functionalities
 *  outlined with comments, but the actual functions have been gutted. These outlines serve to give
 *  you a chance to work with important C concepts. There is also a reference solution file that
 *  you can use to compare against your own code.
 *
 *  In this file, I have some comments that are related to each other; the one that appears later
 *  in the code will say (see comment [X]), which you can find by ctrl+f (or whatever search
 *  feature is available to you) and searching for the comment name in brackets, e.g. "[X]". This
 *  is mostly because a lot of the functions mirror others, and I didn't want to be redundant with
 *  the comments.
 *
 */

/* Here are some fairly standard libraries - not all are used here, but it'll be helpful if
   you're familiar with them! */
#include <stdlib.h>     /* standard library */
#include <stdio.h>      /* standard input/output library */
#include <string.h>     /* standard string library */

#include "list.h"       /* we also need to include our header file! this includes stdbool for us */

#define DEBUG_MODE 1    /* we will use #define to declare this constant ahead of time */

/* I declare this function up here so you can use it in other functions that are defined above
   demo_log's definition. Remember: C reads from top to bottom - if you were to call demo_log in
   a list function without declaring it above the list function, C would have no clue what you
   meant, and it would be mad at you. */
void demo_log(const char *);

/* list_new(): no parameters, return a pointer to a new list or NULL if space can't be allocated */
list_t *list_new(){
    /* TODO: allocate the space for a new list */
    
    /* error check */
    if( /* your list variable name here */ == NULL){
      return NULL;
    }
    /* TODO: set all of its fields and update return value */
    
    return NULL;
}

/* list_free(): list * parameter, no return value; free all space used by this list */
void list_free(list_t *l){
    /* error check */
    if(l == NULL){
        return;
    }
    /* TODO: Free the whole structure and any members it has */

}

/* list_push(): value, value type, and list * parameters, no return value; add the value to the
   front of the list */
void list_push(value_t v, value_type_t t, list_t *l){
    /* error check */
    if(l == NULL){
        return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL){
        return;
    }
    
    /* TODO: plug in the right type and value */
    switch(t){
        case VAL_CHAR:

            break;
        case VAL_INT:

            break;
        case VAL_BOOL:
        
            break;
        case VAL_STR:
            /* we want a *copy* of this string, or else modifying the original modifies this
               value */

            break;
        default:
            /* major issue! free and return early */
            free(new_node);
            return;
    }
    new_node->type = t;

    /* TODO: link at the front of the list */
    
    l->size++;
}

/* list_append(): value, value type, and list * parameters, no return value; add the value to the
   end of the list */
void list_append(value_t v, value_type_t t, list_t *l){
    /* error check */    
    if(l == NULL){
      return;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL){
      return;
    }

    /* plug in the right type and value */
    switch(t){
        case VAL_CHAR:
            new_node->val.cval = v.cval;
            break;
        case VAL_INT:
            new_node->val.ival = v.ival;
            break;
        case VAL_BOOL:
            new_node->val.bval = v.bval;
            break;
        case VAL_STR:
            /* we want a *copy* of this string, or else modifying the original modifies this
               value */
            new_node->val.sval = malloc(strlen(v.sval) + 1);
            if(new_node->val.sval == NULL){
                /* major issue! free and return early */
                free(new_node);
                return;
            }
            strcpy(new_node->val.sval, v.sval); /* usage: strcpy(char *dest, const char *src) */
            break;
        default:
            /* something went wrong; free and return early */
            free(new_node);
            return;
    }
    new_node->type = t;

    /* TODO: link at the back of the list */

    l->size++;
}

/* list_pop(): list * parameter, return the value from the front of the list and remove it */
value_t list_pop(list_t *l){
    value_t ret_val;
    ret_val.sval = NULL;
    /* error check */
    if(l == NULL){
        return ret_val;
    }

    /* get the return value */
    value_type_t val_type = l->header->next->type;
    switch(val_type){
        case VAL_CHAR:

            break;
        case VAL_INT:

            break;
        case VAL_BOOL:

            break;
        case VAL_STR:
            /* [B] The original code I had here returned the actual address of the string rather
               than copying it. I've changed it because we added a part below that frees the string
               during our discussion section. We need a copy since we're freeing the string -
               if you free a pointer and return it, it points to unallocated memory. */
            
            break;
        default:
            /* something went wrong; return ret_val, which at this point should still be NULL */
            return ret_val;
    }

    /* TODO: free and unlink front node */
    /* In addition: free this node's string value when applicable */
    
    l->size--;

    return ret_val;
}

/* list_remove_last(): list * parameter, return the value from the end of the list and remove it */
value_t list_remove_last(list_t *l){
    value_t ret_val;
    ret_val.sval = NULL;
    /* error check */
    if(l == NULL){
        return ret_val;
    }

    /* get the return value */
    value_type_t val_type = l->header->prev->type;
    switch(val_type){
        case VAL_CHAR:
            ret_val.cval = l->header->prev->val.cval;
            break;
        case VAL_INT:
            ret_val.ival = l->header->prev->val.ival;
            break;
        case VAL_BOOL:
            ret_val.bval = l->header->prev->val.bval;
            break;
        case VAL_STR:
            /* (see comment [B]) */
            ret_val.sval = malloc(strlen(l->header->next->val.sval) + 1);
            if(ret_val.sval == NULL){
                /* major issue, return early (NULL) */
                return ret_val;
            }
            strcpy(ret_val.sval, l->header->next->val.sval); /* strcpy as used above */
            break;
        default:
            /* something went wrong; return ret_val, which at this point should still be NULL */
            return ret_val;
    }

    /* TODO: free and unlink last node */
    /* In addition: free this node's string value when applicable */

    l->size--;

    return ret_val;
}

/* list_size(): list * parameter, return its size */
int list_size(list_t *l){
    if(l == NULL){
        return 0;
    }
    return l->size;
}

/* list_get(): int and list * parameters, returns the value at the given index */
value_t list_get(int index, list_t *l){
    /* error check (!l is another way of saying l == NULL) */
    if( !l || index >= l->size){
        value_t null_val;
        null_val.sval = NULL;
        return null_val;
    }
    /* TODO: cycle through the linked list until we arrive at the index */
    return null_val;
}

/* list_get_type(): int and list * parameters, returns the value type at the given index */
value_type_t list_get_type(int index, list_t *l){
    /* error check */
    if( !l || index >= l->size){
        return VAL_NONE;
    }
    int i = 0;
    node_t *curr_node = l->header->next;
    while(i < index){
        curr_node = curr_node->next;
        i++;
    }
    return curr_node->type;
}

/* list_print(): list * parameter, no return value; print the given list */
void list_print(list_t *l){
    if(DEBUG_MODE){
        if(!l){
            return;
        }
        printf("[");
        node_t *curr_node = l->header->next;
        while(curr_node != l->header){
            switch(curr_node->type){
                case VAL_CHAR:
                    printf(" (char) %c ", curr_node->val.cval);
                    break;
                case VAL_INT:
                    printf(" (int) %d ", curr_node->val.ival);
                    break;
                case VAL_BOOL:
                    printf(" (bool) %d ", curr_node->val.bval);
                    break;
                case VAL_STR:
                    printf(" (char *) %s ", curr_node->val.sval);
                    break;
                default:
                    /* if we have any errors, we may as well see 'em in hex */
                    printf(" (ERROR) %llx ", ((long long int) curr_node->val.sval));
            }
            if(curr_node->next != l->header){
                printf("|");
            }
            curr_node = curr_node->next;
        }
        printf("]\n");
    }
}

/* demo_log(): for printing what's happening if DEBUG_MODE is on */
void demo_log(const char *s){
    if(DEBUG_MODE){
        printf("%s", s);
    }
}

/* this is similar to Java main: this is the actual function that executes */
/* for our purposes, main will just execute a few tests */
int main() {
    printf("Starting linked list demo tests...\n");

    /* here are some dummy values we can use in our lists */
    value_t val1, val2, val3, val4;
    val1.ival = 429;
    val2.cval = 'A';
    val3.bval = true;
    val4.sval = "cs429"; /* C strings are pointers to arrays of chars ending in null terminator */
                         /* note: the null terminator is escape character '/0' */

    list_t *list = list_new();

    if(list != NULL){
        /* here are a few basic tests */

        demo_log(">> Testing list_size(), list_append(), list_push(), list_remove_last(), ");
        demo_log("and list_pop()...\n");

        list_print(list);

        if(list_size(list) != 0){
            demo_log("!!! list_size() FAILED !!!\n");
        }

        demo_log(">> appending...\n");
        list_append(val1, VAL_INT, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val2, VAL_CHAR, list);
        list_print(list);

        demo_log(">> appending...\n");
        list_append(val3, VAL_BOOL, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val4, VAL_STR, list);
        list_print(list);

        if(list_size(list) != 4){
            demo_log("!!! list_size() FAILED !!!\n");
        }

        demo_log(">> removing last...\n");
        if(list_remove_last(list).bval != val3.bval){
            demo_log("!!! list_remove_last() FAILED !!!\n");
        }
        list_print(list);

        demo_log(">> popping...\n");
        if(strcmp(list_pop(list).sval, val4.sval) != 0){
            /* strcmp is a string comparison library function. It works similar to Java's
               compareTo: 0 if they're the same, negative if the first is 'less' than the second,
               and positive if the first is 'more' than the second. */
            demo_log("!!! list_pop() FAILED !!!\n");
        }
        list_print(list);
        
        demo_log(">> popping...\n");
        if(list_pop(list).cval != val2.cval){
            demo_log("!!! list_pop() FAILED !!!\n");
        }
        list_print(list);

        demo_log(">> removing last...\n");
        if(list_remove_last(list).ival != val1.ival){
            demo_log("!!! list_remove_last() FAILED !!!\n");
        }
        list_print(list);

        if(list_size(list) != 0){
            demo_log("!!! list_size() FAILED !!!\n");
        }

        demo_log(">> pushing...\n");
        list_push(val3, VAL_BOOL, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val2, VAL_CHAR, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val1, VAL_INT, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val2, VAL_CHAR, list);
        list_print(list);

        demo_log(">> pushing...\n");
        list_push(val3, VAL_BOOL, list);
        list_print(list);

        if(list_size(list) != 5){
            demo_log("!!! list_size() FAILED !!!\n");
        }

        demo_log(">> Testing list_get(), list_get_type()...\n");
        list_print(list);

        demo_log(">> getting value of index 1...\n");
        if(list_get(1, list).cval != val2.cval){
            demo_log("!!! list_get() FAILED !!!\n");
        }

        demo_log(">> getting type of index 1...\n");
        if(list_get_type(1, list) != VAL_CHAR){
            demo_log("!!! list_get_type() FAILED !!!\n");
        }
        
        demo_log(">> getting value of index 2...\n");
        if(list_get(2, list).ival != val1.ival){
            demo_log("!!! list_get() FAILED !!!\n");
        }

        demo_log(">> getting type of index 2...\n");
        if(list_get_type(2, list) != VAL_INT){
            demo_log("!!! list_get_type() FAILED !!!\n");
        }

        list_free(list);
        list = NULL; /* it's a good idea to NULL out your freed pointers so you don't accidentally
                        access unallocated memory */

    }else{
        printf("!!! list_new() FAILED !!!\n");
    }
    
    printf("Complete!\n");
    return 0; /* returning 0 from main usually means everything went smoothly! */
}

