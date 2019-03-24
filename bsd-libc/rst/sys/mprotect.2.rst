--------------

MPROTECT(2) BSD System Calls Manual MPROTECT(2)

**NAME**

**mprotect** — control the protection of pages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**mprotect**\ (*void *addr*, *size_t len*, *int prot*);

**DESCRIPTION**

The **mprotect**\ () system call changes the specified pages to have
protection *prot*. Not all implementations will guarantee protection on
a page basis; the granularity of protection changes may be as large as
an entire region. A region is the virtual address space defined by the
start and end addresses of a *struct vm_map_entry*.

Currently these protection bits are known, which can be combined, OR’d
together:

PROT_NONE

No permissions at all.

PROT_READ

The pages can be read.

PROT_WRITE

The pages can be written.

PROT_EXEC

The pages can be executed.

**RETURN VALUES**

The **mprotect**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **mprotect**\ () system call will fail if:

[EINVAL]

The virtual address range specified by the *addr* and *len* arguments is
not valid.

[EACCES]

The calling process was not allowed to change the protection to the
value specified by the *prot* argument.

**SEE ALSO**

madvise(2), mincore(2), msync(2), munmap(2)

**HISTORY**

The **mprotect**\ () system call first appeared in 4.4BSD.

BSD August 3, 2016 BSD

--------------
