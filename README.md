# ALLOCATOR

## DESCRIPTION
A general purpose allocator to reduce system calls during frequent memory allocation and deallocation.

## INSTALLING
>The only way to get the library is by building from source described in the next section.

## BUILDING
What you need:
- CMAKE >= v3.19
- clang/gcc/msvc
- Clone of this repo

```bash
$ cd /path/to/repo/clone
$ cmake -B build
$ cmake --build build
# optional
$ cmake --build build --target install
```
## EXAMPLES
```c
    struct person {
        int age;
        double height; /* in meters */
        char name[20];
    };
    /* The internal structure of the allocator is of no use outside the allocator itself so the implicit cast to void * will suffice */
    void *alloc = allocatorcreate(sizeof(struct person));
    struct person *new = allocatormalloc(alloc);
    /** from string.h */
    strcpy(new->name, "jumbuna");
    new->age = 50;
    new->height = 2;
    allocatorfree(alloc, new);
    void *new2 = allocatormalloc(alloc);
    /** new2 == new */
    allocatordestroy(alloc);
```

## CONTRIBUTIONS
All contributions are welcome. Send me a pull request anytime.