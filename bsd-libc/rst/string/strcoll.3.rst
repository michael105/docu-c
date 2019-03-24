--------------

STRCOLL(3) BSD Library Functions Manual STRCOLL(3)

**NAME**

**strcoll** — compare strings according to current collation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**strcoll**\ (*const char *s1*, *const char *s2*);

*int*

**strcoll_l**\ (*const char *s1*, *const char *s2*, *locale_t loc*);

**DESCRIPTION**

The **strcoll**\ () function lexicographically compares the
null-terminated strings *s1* and *s2* according to the current locale
collation and returns an integer greater than, equal to, or less than 0,
depending on whether *s1* is greater than, equal to, or less than *s2*.
If information about the current locale collation is not available, the
value of **strcmp**\ (*s1*, *s2*) is returned. The **strcoll_l**\ ()
function uses an explicit locale argument rather than the system locale.

**SEE ALSO**

setlocale(3), strcmp(3), strxfrm(3), wcscoll(3)

**STANDARDS**

The **strcoll**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **strcoll_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD June 4, 1993 BSD

--------------
