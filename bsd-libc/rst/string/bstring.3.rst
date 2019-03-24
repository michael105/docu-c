--------------

BSTRING(3) BSD Library Functions Manual BSTRING(3)

**NAME**

**bcmp**, **bcopy**, **bzero**, **memccpy**, **memchr**, **memcmp**,
**memcpy**, **memmove**, **memset** — byte string operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**bcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

*void*

**bcopy**\ (*const void *src*, *void *dst*, *size_t len*);

*void*

**bzero**\ (*void *b*, *size_t len*);

*void \**

**memchr**\ (*const void *b*, *int c*, *size_t len*);

*int*

**memcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

*void \**

**memccpy**\ (*void *dst*, *const void *src*, *int c*, *size_t len*);

*void \**

**memcpy**\ (*void *dst*, *const void *src*, *size_t len*);

*void \**

**memmove**\ (*void *dst*, *const void *src*, *size_t len*);

*void \**

**memset**\ (*void *b*, *int c*, *size_t len*);

**DESCRIPTION**

These functions operate on variable length strings of bytes. They do not
check for terminating null bytes as the routines listed in string(3) do.

See the specific manual pages for more information.

**SEE ALSO**

bcmp(3), bcopy(3), bzero(3), memccpy(3), memchr(3), memcmp(3),
memcpy(3), memmove(3), memset(3)

**STANDARDS**

The functions **memchr**\ (), **memcmp**\ (), **memcpy**\ (),
**memmove**\ (), and **memset**\ () conform to ISO/IEC 9899:1990
(‘‘ISO C90’’).

**HISTORY**

The functions **bzero**\ () and **memccpy**\ () appeared in 4.3BSD; the
functions **bcmp**\ (), **bcopy**\ (), appeared in 4.2BSD.

BSD June 4, 1993 BSD

--------------
