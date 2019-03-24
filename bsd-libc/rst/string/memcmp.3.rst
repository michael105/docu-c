--------------

MEMCMP(3) BSD Library Functions Manual MEMCMP(3)

**NAME**

**memcmp** — compare byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**memcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

**DESCRIPTION**

The **memcmp**\ () function compares byte string *b1* against byte
string *b2*. Both strings are assumed to be *len* bytes long.

**RETURN VALUES**

The **memcmp**\ () function returns zero if the two strings are
identical, otherwise returns the difference between the first two
differing bytes (treated as *unsigned char* values, so that ‘\200’ is
greater than ‘\0’, for example). Zero-length strings are always
identical.

**SEE ALSO**

bcmp(3), strcasecmp(3), strcmp(3), strcoll(3), strxfrm(3),
timingsafe_memcmp(3), wmemcmp(3)

**STANDARDS**

The **memcmp**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD August 15, 2016 BSD

--------------
