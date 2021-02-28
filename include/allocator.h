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

struct Allocator *allocatorcreate(unsigned long);
void allocatordestroy(struct Allocator *);
void *allocatormalloc(struct Allocator *);
void *allocatorcalloc(struct Allocator *);
void allocatorfree(struct Allocator *, void *);

#endif // __ALLOCATOR__H