--------------

TOUPPER(3) BSD Library Functions Manual TOUPPER(3)

**NAME**

**toupper** — lower case to upper case letter conversion

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**toupper**\ (*int c*);

**DESCRIPTION**

The **toupper**\ () function converts a lower-case letter to the
corresponding upper-case letter. The argument must be representable as
an *unsigned char* or the value of EOF.

**RETURN VALUES**

If the argument is a lower-case letter, the **toupper**\ () function
returns the corresponding upper-case letter if there is one; otherwise,
the argument is returned unchanged.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**towupper**\ () function should be used instead.

**SEE ALSO**

ctype(3), isupper(3), towupper(3)

**STANDARDS**

The **toupper**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’).

BSD July 25, 2010 BSD

--------------
