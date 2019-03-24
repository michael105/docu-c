--------------

MEMORY(3) BSD Library Functions Manual MEMORY(3)

**NAME**

**malloc**, **free**, **realloc**, **calloc**, **alloca**, **mmap** —
general memory allocation operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**malloc**\ (*size_t size*);

*void*

**free**\ (*void *ptr*);

*void \**

**realloc**\ (*void *ptr*, *size_t size*);

*void \**

**calloc**\ (*size_t nelem*, *size_t elsize*);

*void \**

**alloca**\ (*size_t size*);

**#include <sys/types.h>
#include <sys/mman.h>**

*void \**

**mmap**\ (*void * addr*, *size_t len*, *int prot*, *int flags*,
*int fd*, *off_t offset*);

**DESCRIPTION**

These functions allocate and free memory for the calling process. They
are described in the individual manual pages.

**SEE ALSO**

mmap(2), alloca(3), calloc(3), free(3), malloc(3), realloc(3)

**STANDARDS**

These functions, with the exception of **alloca**\ () and **mmap**\ ()
conform to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD June 4, 1993 BSD

--------------
