--------------

MUNMAP(2) BSD System Calls Manual MUNMAP(2)

**NAME**

**munmap** — remove a mapping

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**munmap**\ (*void *addr*, *size_t len*);

**DESCRIPTION**

The **munmap**\ () system call deletes the mappings and guards for the
specified address range, and causes further references to addresses
within the range to generate invalid memory references.

**RETURN VALUES**

The **munmap**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **munmap**\ () system call will fail if:

[EINVAL]

The *addr* argument was not page aligned, the *len* argument was zero or
negative, or some part of the region being unmapped is outside the valid
address range for a process.

**SEE ALSO**

madvise(2), mincore(2), mmap(2), mprotect(2), msync(2), getpagesize(3)

**HISTORY**

The **munmap**\ () system call first appeared in 4.4BSD.

BSD June 22, 2017 BSD

--------------
