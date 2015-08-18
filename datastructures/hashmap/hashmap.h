#ifndef __HASHMAP_H
#define __HASHMAP_H

#include <math.h>
#define __ROUND(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

#define INITIAL_SIZE 1024
#define THRESHOLD(x) (__ROUND(0.8*x))

#define E_NOKEY = 1 /* The specified key cannot be found. */
#define E_FULL  = 2 /* The hashmap is full. */
#define E_NUNIQ  = 3 /* The key already exists. Not unique */

typedef struct hashmap_t {
    int capacity;
    int size;
    struct bucket_t *buckets;
} hashmap_t;

typedef struct bucket_t {
    int numentries;
    struct entry_t *entries;
} bucket_t;

typedef struct entry_t {
    char *key;
    void *value;
    struct entry_t *next;
} entry_t;

struct hashmap_t *inithmap();
void freehmap( struct hashmap_t *hm );
int rehash( struct hashmap_t *hm );
int puthmap( struct hashmap_t *hm, char *key, void *value );
void *gethmap( struct hashmap_t *hm, char *key );

#endif /* __HASHMAP_H */
