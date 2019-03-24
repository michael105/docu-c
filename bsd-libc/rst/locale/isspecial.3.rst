--------------

ISSPECIAL(3) BSD Library Functions Manual ISSPECIAL(3)

**NAME**

**isspecial** — special character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isspecial**\ (*int c*);

**DESCRIPTION**

The **isspecial**\ () function tests for a special character.

**RETURN VALUES**

The **isspecial**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**SEE ALSO**

ctype(3), iswspecial(3)

**HISTORY**

The **isspecial**\ () function appeared in 4.4BSD.

BSD March 30, 2004 BSD

--------------
