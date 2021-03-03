#include "../include/allocator.h"
#include <stdlib.h>
#include <string.h>

typedef struct Allocator ALLOCATOR;

ALLOCATOR *allocatorcreate(size_t sz) {
    ALLOCATOR *new = calloc(1, sizeof(ALLOCATOR));
    ((size_t *) new)[1] = sz >= sizeof(void *) ? sz : sizeof(void *);
    ((size_t *) new)[3] = __ALLOCATOR__BLOCKENTRIES;
    return new;
}

void allocatordestroy(ALLOCATOR *p) {
    while(p->currentblock) {
        size_t **temp = (size_t **) *p->currentblock;
        free(p->currentblock);
        p->currentblock = (void **)temp;
    }
    free(p);
}

void *allocatormalloc(ALLOCATOR *a) {
    if(a->used >= __ALLOCATOR__BLOCKENTRIES) {
        size_t **newblock = (size_t** ) malloc(a->entrysize*__ALLOCATOR__BLOCKENTRIES + sizeof(size_t));
        if(!newblock) {
            return NULL;
        }
        newblock[0] = (void*) a->currentblock;
        a->currentblock = (void **)newblock;
        ((size_t*) a)[3] = 0;
    }
    if(a->freelist) {
        void **temp = a->freelist;
        a->freelist = (void **) *temp;
        return (void*) temp;
    }
    ((size_t *) a)[3]++;
    return &((void *)(&a->currentblock[1]))[(a->used-1)*a->entrysize];
}

void *allocatorcalloc(ALLOCATOR *a) {
    void *new = allocatormalloc(a);
    memset(new, 0, a->entrysize);
    return new;
}

void allocatorfree(ALLOCATOR *a, void *p) {
    size_t **new = (size_t **) p;
    *new = (size_t *) a->freelist;
    a->freelist = (void **) new;
}