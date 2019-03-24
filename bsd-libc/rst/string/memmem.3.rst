--------------

MEMMEM(3) BSD Library Functions Manual MEMMEM(3)

**NAME**

**memmem** — locate a byte substring in a byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memmem**\ (*const void *big*, *size_t big_len*, *const void *little*,
*size_t little_len*);

**DESCRIPTION**

The **memmem**\ () function locates the first occurrence of the byte
string *little* in the byte string *big*.

**RETURN VALUES**

If *little_len* is zero *big* is returned (that is, an empty little is
deemed to match at the beginning of big); if *little* occurs nowhere in
*big*, NULL is returned; otherwise a pointer to the first character of
the first occurrence of *little* is returned.

**SEE ALSO**

memchr(3), strchr(3), strstr(3)

**CONFORMING TO**

**memmem**\ () is a GNU extension.

**HISTORY**

The **memmem**\ () function first appeared in FreeBSD 6.0. It was
replaced with an optimized O(n) implementation from the musl libc
project in FreeBSD 12.0. Pascal Gloor <*pascal.gloor@spale.com*>
provided this man page along with the previous implementation.

**BUGS**

This function was broken in Linux libc up to and including version 5.0.9
and in GNU libc prior to version 2.1. Prior to FreeBSD 11.0 **memmem**
returned NULL when *little_len* equals 0.

BSD March 17, 2017 BSD

--------------
