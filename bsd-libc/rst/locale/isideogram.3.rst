--------------

ISIDEOGRAM(3) BSD Library Functions Manual ISIDEOGRAM(3)

**NAME**

**isideogram** — ideographic character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isideogram**\ (*int c*);

**DESCRIPTION**

The **isideogram**\ () function tests for an ideographic character.

**RETURN VALUES**

The **isideogram**\ () function returns zero if the character tests
false and returns non-zero if the character tests true.

**SEE ALSO**

ctype(3), isphonogram(3), iswideogram(3)

**HISTORY**

The **isideogram**\ () function appeared in 4.4BSD.

BSD March 30, 2004 BSD

--------------
