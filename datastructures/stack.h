#ifndef __UTIL_STACK_H
#define __UTIL_STACK_H

#define DEFAULT_SIZE 10

typedef void *element_t;

typedef struct stack_t {

    element_t *elements;
    int count;
    int max;

} stack_t;

stack_t *stack_init( );
int stack_unshift( stack_t *stack, element_t item );
element_t stack_shift( stack_t *stack );
int stack_isEmtpy( stack_t *stack );
int stack_isFull( stack_t *stack );

#endif /* __UTIL_QUEUE_H */

