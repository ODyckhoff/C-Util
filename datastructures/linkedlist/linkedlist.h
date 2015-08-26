#ifndef __DATASTRUCTURES_LINKEDLIST_H
#define __DATASTRUCTURES_LINKEDLIST_H

/* Type declarations. */
typedef int ll_ele_t;
/*     |___|
         |
 Substitute with your type.
*/

typedef struct ll_node_t {

    ll_ele_t element;
    struct ll_node_t *next;

} ll_node_t;

typedef struct linkedlist_t {

    struct ll_node_t *head;
    int count;

} linkedlist_t;

/* Function Prototypes */
linkedlist_t *ll_init( );
ll_node_t *ll_node_init( ll_ele_t element );
int del_ll_index( linkedlist_t *ll, ll_ele_t element );
int add_ll_index( linkedlist_t *ll, ll_ele_t item, (*sort_hndlr)() );
void ll_free( linkedlist_t *ll );
void ll_node_free( linkedlist_t *ll, ll_ele_t element );
int ll_sort( ll_ele_t *a, ll_ele_t *b );
int ll_isEmpty( linked_list_t *ll );

#endif /* __DATASTRUCTURES_LINKEDLIST_H */
