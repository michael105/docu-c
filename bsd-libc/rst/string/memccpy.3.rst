--------------

MEMCCPY(3) BSD Library Functions Manual MEMCCPY(3)

**NAME**

**memccpy** — copy string until character found

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memccpy**\ (*void *dst*, *const void *src*, *int c*, *size_t len*);

**DESCRIPTION**

The **memccpy**\ () function copies bytes from string *src* to string
*dst*. If the character *c* (as converted to an *unsigned char*) occurs
in the string *src*, the copy stops and a pointer to the byte after the
copy of *c* in the string *dst* is returned. Otherwise, *len* bytes are
copied, and a NULL pointer is returned.

**SEE ALSO**

bcopy(3), memcpy(3), memmove(3), strcpy(3)

**HISTORY**

The **memccpy**\ () function first appeared in 4.4BSD.

BSD June 9, 1993 BSD

--------------
