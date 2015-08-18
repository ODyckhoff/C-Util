#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

linkedlist_t *ll_init( ) {
    linkedlist_t *ll = malloc( sizeof( linkedlist_t ) );

    if( ll == NULL ) {
        fprintf( stderr, "Unable to allocate memory.\n" );
        return NULL;
    }

    ll->count = 0;
    ll->head = NULL;

    return ll;
}

ll_node_t *ll_node_init( ll_ele_t element ) {
    ll_node_t *ln = malloc( sizeof( ll_node_t ) );

    if( ln == NULL ) {
        fprintf( stderr, "Unable to allocate memory.\n" );
        return NULL;
    }

    ln->element = element;
    return ln;
}

void ll_node_free( ll_node_t *ln ) {
    free( ln );
}

int del_ll_index( linkedlist_t *ll, ll_ele_t element ) {
    ll_node_t *cur;
    ll_node_t *last;

    if( isEmpty( ll ) ) return 1;

    cur = ll->head;
    do {
        if( element == cur->element ) {
            last->next = cur->next;
            ll_node_free( cur );
            ll->count--;
            break;
        }
        last = cur;
    }
    while( ( cur = cur->next ) != NULL );
    
    if( cur != NULL && cur->next == NULL )
        return 2;
    else
        return 0;
}

int add_ll_index( linkedlist_t *ll, ll_ele_t item, (*sort_hndlr)() ) {
    ll_node_t *cur;
    ll_node_t *last;
    ll_node_t *ins;
    int pos;

    if( item == NULL ) return 1;
    ins = ll_node_init( item );

    if( sort_hndlr == NULL ) sort_hndlr = ll_sort;

    if( isEmpty( ll ) ) { 
        ll->head = ins;
        return 0;
    }

    cur = ll->head;
    last = NULL;
    do {
        pos = sort_hndlr( cur->element, item );
        if( pos == 1 ) {
            continue;    
        }
        else if( pos == 0 ) {
            ins->next = cur->next;
            cur->next = ins;
        }
        else if( pos == -1 ) {
            ins->next = cur;
            if( cur == head )
                head = ins;
            else
                last->next = ins;
            break;
        }
        else {
            fprintf( stderr, "Error, element types are not comparable.\n" );
            return 2;
        }
    } while( ( cur = cur->next ) != NULL );
    ll->count++;

    if( cur->next == NULL && cur->element != item ) return 3;
    
    return 0;
}

void ll_node_free( ll_node_t *ln ) {
    free( ln );
}


void ll_free( linkedlist_t *ll ) {
    ll_node_t *cur;
    ll_node_t *tmp;
    cur = ll->head;

    if( ! isEmpty( ll ) ) {
        while( ( tmp = cur->next ) != null ) {
            free( cur );
            cur = tmp;
        }
        free( ll->head );
    }
    free( ll );
}

int ll_sort( ll_ele_t *a, ll_ele_t *b ) {
    if( a < b )  return -1;
    if( a == b ) return 0;
    if( a > b ) return 1;
}

int isEmpty( linkedlist_t *ll ) {
    return ( ll->head == NULL );
}
