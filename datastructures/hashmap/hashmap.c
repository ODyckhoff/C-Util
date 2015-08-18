#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashmap.h"

/* START HASHMAP */

/* Preamble
 * ---------
 *
 * Whilst, in theory, it's probably simpler to have a dynamically resized
 *   array of list_t structs, the look-up time increases drastically
 *   as the data set grows large.
 *
 * For this reason, I have made a generic type hashmap solution,
 *   which works on key/value pairs. The key is a string, and the value
 *   is a void pointer, int, or char
*/

int main( int argc, char **argv ) {

    hashmap_t *hm = inithmap();
    freehmap( hm );

    return EXIT_SUCCESS;
}

hashmap_t *inithmap() {
    hashmap_t *hm = malloc( sizeof( hashmap_t ) );
    if( ! hm ) return NULL;

    hm->capacity = INITIAL_SIZE;
    hm->size = 0;

    hm->buckets = calloc( INITIAL_SIZE, sizeof( bucket_t * ) );
    if( ! hm->buckets ) {
        freehmap( hm );
        return NULL;
    }

    return hm;
}

void freehmap( hashmap_t *hm ) {
    int i;
    entry_t *cur;

    if( ! hm ) return;

    if( hm->size == 0 || hm->buckets == NULL ) {
        free( hm );
        return;
    }

    if( hm->buckets ) {
        for( i = 0; i < hm->capacity; i++ ) {
            if( hm->buckets[ i ].entries == NULL )
                continue;
            cur = &( hm->buckets[ i ].entries[0] );
            do {
                free( cur->key );
                free( cur->value );
            }
            while( ( cur = cur->next ) != NULL );
        }
        free( hm->buckets );
    }

    free( hm );

    return;
}

int puthmap( hashmap_t *hm, char *key, void *value ) {

    if( hm->size + 1 >= THRESHOLD( hm->capacity ) )
        rehash( hm );

    
}


