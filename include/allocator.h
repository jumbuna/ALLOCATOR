#ifndef __ALLOCATOR__H
#define __ALLOCATOR__H
#define __ALLOCATOR__BLOCKENTRIES 256

struct Allocator {
    void **currentblock;
    unsigned long const entrysize;
    // void **block;
    void **freelist;
    unsigned const long used;
};

/** 
 * Create a new allocator that provides memory chunks
 * of given size
 */
struct Allocator *allocatorcreate(unsigned long);
/**
 * Free All memory currently being held by the given 
 * allocator
 */
void allocatordestroy(struct Allocator *);
/***
 * Get a memory chunk from the allocator
 */
void *allocatormalloc(struct Allocator *);
/**
 * Same as calloc, zeroing the memory chunk
 */
void *allocatorcalloc(struct Allocator *);
/**
 * Recycle a memory chunk
 */
void allocatorfree(struct Allocator *, void *);

#endif // __ALLOCATOR__H