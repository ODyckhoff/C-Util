/* queue.c */

/* BEGIN QUEUE
 * ===========
 * Queues are a first in, first out (FIFO) datastructure,
 *   so you must ensure that items only get added to the end
 *   and removed only from the front of the queue. These
 *   functions are called "push" and "pop".
 *
 * When an item is popped from the front of a queue, typically
 *   a lot of code will shuffle all the elements forwards to
 *   the front of the array. Computationally, however, this is
 *   quite an expensive operation, so we simply keep track of
 *   where the front of the queue is, and how many spaces in
 *   the queue have been filled up. A small amount of
 *   arithmetic is used to automatically wrap the index round
 *   to the start of the array in memory, so that you don't
 *   have to check that the index is in-bounds.
 *
 * Also provided are "isEmpty" and "isFull" functions, which
 *   make life easier when you can determine that there's no
 *   point trying to pop an item off an empty queue, or push
 *   an item into a full queue.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t *queue_init( int size ) {
    if( size == 0 )
       size = DEFAULT_SIZE;
    queue_t *q = malloc( sizeof( queue_t ) );
    
    if( q == NULL ) {
        fprintf( stderr, "malloc failed." );
        return NULL;
    }

    q->max = size;
    q->head = 0;
    q->count = 0;
    q->elements = malloc( size * sizeof( element_t ) );

    return q;
}

int queue_push( queue_t *queue, element_t item ) {
    if( queue_isFull( queue ) )
        return 1;
    else {
        queue->elements[ ( queue->head + queue->count ) % queue->max ] = item;
        queue->count++;
    }
    return 0;
}

element_t queue_pop( queue_t *queue ) {
    element_t item;
    if( queue_isEmpty( queue ) )
        return NULL;
    else {
        item = queue->elements[ queue->head ];
        queue->elements[ queue->head ] = NULL;
        queue->head = ( queue->head + 1 ) % queue->max;
        queue->count--;
    }
    return item;
}

int queue_isEmtpy( queue_t *queue ) {
    return ( queue->count == 0 );
}

int queue_isFull( queue_t *queue ) {
    return ( queue->count == queue->max );
}
