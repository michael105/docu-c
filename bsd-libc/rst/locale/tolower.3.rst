--------------

TOLOWER(3) BSD Library Functions Manual TOLOWER(3)

**NAME**

**tolower** — upper case to lower case letter conversion

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**tolower**\ (*int c*);

**DESCRIPTION**

The **tolower**\ () function converts an upper-case letter to the
corresponding lower-case letter. The argument must be representable as
an *unsigned char* or the value of EOF.

**RETURN VALUES**

If the argument is an upper-case letter, the **tolower**\ () function
returns the corresponding lower-case letter if there is one; otherwise,
the argument is returned unchanged.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**towlower**\ () function should be used instead.

**SEE ALSO**

ctype(3), islower(3), towlower(3)

**STANDARDS**

The **tolower**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’).

BSD July 25, 2010 BSD

--------------
