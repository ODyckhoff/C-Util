
/* stack.c */

/* BEGIN QUEUE
 * ===========
 * Stacks are a first in, last out (FILO) datastructure,
 *   so you must ensure that items only get added to and
 *   removed from the end of the stack. These functions
 *   are called "unshift" and "shift".
 *
 * Also provided are "isEmpty" and "isFull" functions, which
 *   make life easier when you can determine that there's no
 *   point trying to shift an item off an empty stack, or unshift
 *   an item into a full stack.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack_t *stack_init( int size ) {
    if( size == 0 )
       size = DEFAULT_SIZE;
    stack_t *s = malloc( sizeof( stack_t ) );
    
    if( s == NULL ) {
        fprintf( stderr, "malloc failed." );
        return NULL;
    }

    s->max = size;
    s->count = 0;
    s->elements = malloc( size * sizeof( element_t ) );

    return q;
}

int stack_unshift( stack_t *stack, element_t item ) {
    if( stack_isFull( stack ) )
        return 1;
    else {
        stack->elements[ count ] = item;
        stack->count++;
    }
    return 0;
}

element_t stack_shift( stack_t *stack ) {
    element_t item;
    if( stack_isEmpty( stack ) )
        return NULL;
    else {
        item = stack->elements[ count - 1 ];
        stack->elements[ count - 1 ] = NULL;
        stack->count--;
    }
    return item;
}

int stack_isEmtpy( stack_t *stack ) {
    return ( stack->count == 0 );
}

int stack_isFull( stack_t *stack ) {
    return ( stack->count == stack->max );
}
