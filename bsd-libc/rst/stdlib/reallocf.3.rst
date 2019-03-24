--------------

MALLOC(3) BSD Library Functions Manual MALLOC(3)

**NAME**

**reallocf** — memory reallocation function

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**reallocf**\ (*void *ptr*, *size_t size*);

**DESCRIPTION**

The **reallocf**\ () function is identical to the **realloc**\ ()
function, except that it will free the passed pointer when the requested
memory cannot be allocated. This is a FreeBSD specific API designed to
ease the problems with traditional coding styles for **realloc**\ ()
causing memory leaks in libraries.

**RETURN VALUES**

The **reallocf**\ () function returns a pointer, possibly identical to
*ptr*, to the allocated memory if successful; otherwise a NULL pointer
is returned, and *errno* is set to ENOMEM if the error was the result of
an allocation failure. The **reallocf**\ () function deletes the
original buffer when an error occurs.

**SEE ALSO**

realloc(3)

**HISTORY**

The **reallocf**\ () function first appeared in FreeBSD 3.0.

BSD January 31, 2010 BSD

--------------
