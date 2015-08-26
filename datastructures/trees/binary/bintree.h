#ifndef __DATASTRUCTURES_TREE_BINARY_H
#define __DATASTRUCTURES_TREE_BINARY_H

typedef struct bintree_node_t {

    int value;
    struct bintree_node_t *left;
    struct bintree_node_t *right;

} bintree_node_t;

typedef struct bintree_t {

    int count;
    struct bintree_node_t *root;

} bintree_t;

bintree_t *bintree_init( );
bintree_node_t *bin_node_init( int value );
bintree_node_t *min_bin_node_get( bintree_node_t *root );

int bintree_add_node( bintree_t *bt, bintree_node_t *bn );
int bintree_del_node( bintree_t *bt, int value );
int bintree_isEmpty( bintree_t *bt );
void bintree_free( bintree_t *bt );
void bintree_node_free( bintree_node_t *bn );

#endif /* __DATASTRUCTURES_TREE_BINARY_H */

