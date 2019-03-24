--------------

ISRUNE(3) BSD Library Functions Manual ISRUNE(3)

**NAME**

**isrune** — valid character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isrune**\ (*int c*);

**DESCRIPTION**

The **isrune**\ () function tests for any character that is valid in the
current character set. In the ASCII character set, this is equivalent to
**isascii**\ ().

**RETURN VALUES**

The **isrune**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**SEE ALSO**

ctype(3), isascii(3), iswrune(3), ascii(7)

**HISTORY**

The **isrune**\ () function appeared in 4.4BSD.

BSD March 30, 2004 BSD

--------------
