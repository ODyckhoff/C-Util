/* bintree.c */

#include <stdlib.h>
#include <stdio.h>

bintree_t *bintree_init( ) {
    bintree_t *bt;

    if( ( bt = malloc( sizeof( bintree_t ) ) ) == NULL ) {
        fprintf( stderr, "Unable to allocate memory.\n" );
        return NULL;
    }

    bt->count = 0;
    bt->root = NULL;

    return bt;
}

bintree_node_t *bin_node_init( int value ) {
    bintree_node_t *bn;

    if( ( bn = malloc( sizeof( bintree_node_t ) ) ) == NULL ) {
        fprintf( stderr, "Unable to allocate memory.\n" );
        return NULL;
    }

    bn->value = value;
    bn->left = bn->right = NULL;

    return bn;
}

bintree_node_t *min_bin_node_get( bintree_node_t *root ) {

    bintree_node_t *bn = root;

    do {
        bn = bn->left;
    }
    while( bn->left != NULL );

    return bn;
}

int bintree_add_node( bintree_t *bt, int value ) {
    if( bt == NULL ) {
        bt = bintree_init( );
    }

    bintree_insert( bt->root, value );
}

int bintree_insert( bintree_node_t *root, int value ) {
    bintree_node_t *bn;

    if( root == NULL ) {
        if( ( bn = malloc( sizeof( bintree_node_t ) ) ) == NULL ) {
            printf( stderr, "Unable to allocate memory.\n" );
            return 1;
        }

        bn->value = value;
        bn->left = NULL;
        bn->right = NULL;
        return 0;
    }
    else if( value < bn->value ) {
        bintree_insert( root->left );
    }
    else if( value > bn->value ) {
        bintree_insert( root->right );
    }
}

int bintree_del_node( bintree_t *bt, int value ) {
    if( bt == NULL ) return 1;

    bintree_delete( bt->root, value );
}

int bintree_delete( bintree_node_t *root, bintree_node_t *parent, int value ) {
    bintree_node_t *child;

    if( root == NULL ) return 1;

    if( root->value > value ) {
        bintree_delete( root->left, root, value );
    }
    else if( root->value < value ) {
        bintree_delete( root->right, root, value );
    }
    else {
        if( root->left == NULL && root->right == NULL ) {
            /* Easiest case, no children. Just delete. */
            bintree_node_free( root );
        }
        if(
            root->left  == NULL && root->right != NULL ||
            root->right == NULL && root->left  != NULL
        ) {
            /* Next easiest, one child. reparent child to 
                 parent of current node. 
            */
            
            child = ( root->left == NULL && root->right != NULL
                ?
                    root->right
                :
                    root->left
            );
            
            if( parent->value < value )
                parent->right = child;
            else
                parent->left = child;
            bintree_node_free( root );
        }
    }
    return 0;
}

int bintree_isEmpty( bintree_t *bt ) {

}

void bintree_free( bintree_t *bt ) {

}

void bintree_node_free( bintree_node_t *bn ) {

}

