#ifndef __UTIL_QUEUE_H
#define __UTIL_QUEUE_H

#define DEFAULT_SIZE 10

typedef void *element_t;

typedef struct queue_t {

    element_t *elements;
    int count;
    int max;
    int head;

} queue_t;

queue_t *queue_init( );
int queue_push( queue_t *queue, element_t item );
element_t queue_pop( queue_t *queue );
int queue_isEmtpy( queue_t *queue );
int queue_isFull( queue_t *queue );

#endif /* __UTIL_QUEUE_H */

