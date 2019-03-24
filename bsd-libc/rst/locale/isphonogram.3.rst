--------------

ISPHONOGRAM(3) BSD Library Functions Manual ISPHONOGRAM(3)

**NAME**

**isphonogram** — phonographic character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isphonogram**\ (*int c*);

**DESCRIPTION**

The **isphonogram**\ () function tests for a phonographic character.

**RETURN VALUES**

The **isphonogram**\ () function returns zero if the character tests
false and returns non-zero if the character tests true.

**SEE ALSO**

ctype(3), isideogram(3), iswphonogram(3)

**HISTORY**

The **isphonogram**\ () function appeared in 4.4BSD.

BSD March 30, 2004 BSD

--------------
