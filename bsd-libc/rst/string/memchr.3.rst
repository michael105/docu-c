--------------

MEMCHR(3) BSD Library Functions Manual MEMCHR(3)

**NAME**

**memchr** — locate byte in byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memchr**\ (*const void *b*, *int c*, *size_t len*);

*void \**

**memrchr**\ (*const void *b*, *int c*, *size_t len*);

**DESCRIPTION**

The **memchr**\ () function locates the first occurrence of *c*
(converted to an *unsigned char*) in string *b*.

The **memrchr**\ () function behaves like **memchr**\ (), except that it
locates the last occurrence of *c* in string *b*.

**RETURN VALUES**

The **memchr**\ () and **memrchr**\ () functions return a pointer to the
byte located, or NULL if no such byte exists within *len* bytes.

**SEE ALSO**

memmem(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3),
strspn(3), strstr(3), strtok(3), wmemchr(3)

**STANDARDS**

The **memchr**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

The **memrchr**\ () function is a GNU extension and conforms to no
standard.

**HISTORY**

The **memrchr**\ () function first appeared in GNU libc 2.1.91, this
implementation first appeared in FreeBSD 6.4, coming from OpenBSD 4.3.

BSD April 9, 2008 BSD

--------------
