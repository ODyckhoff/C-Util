#ifndef __UTIL_QUEUE_H
#define __UTIL_QUEUE_H

#define DEFAULT_SIZE 10

typedef void *element_t;

typedef struct queue_t {

    q_ele_t *elements;
    int count;
    int max;
    int head;

} queue_t;

queue_t *queue_init( );
int queue_push( queue_t *queue, q_ele_t item );
q_ele_t queue_pop( queue_t *queue );
int queue_isEmtpy( queue_t *queue );
int queue_isFull( queue_t *queue );

#endif /* __UTIL_QUEUE_H */

