#ifndef __UTIL_STACK_H
#define __UTIL_STACK_H

#define DEFAULT_SIZE 10

typedef void *s_ele_t;

typedef struct stack_t {

    s_ele_t *elements;
    int count;
    int max;

} stack_t;

stack_t *stack_init( );
int stack_unshift( stack_t *stack, s_ele_t item );
s_ele_t stack_shift( stack_t *stack );
int stack_isEmtpy( stack_t *stack );
int stack_isFull( stack_t *stack );

#endif /* __UTIL_QUEUE_H */

