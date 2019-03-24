--------------

TOWLOWER(3) BSD Library Functions Manual TOWLOWER(3)

**NAME**

**towlower** — upper case to lower case letter conversion (wide
character version)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*wint_t*

**towlower**\ (*wint_t wc*);

**DESCRIPTION**

The **towlower**\ () function converts an upper-case letter to the
corresponding lower-case letter.

**RETURN VALUES**

If the argument is an upper-case letter, the **towlower**\ () function
returns the corresponding lower-case letter if there is one; otherwise
the argument is returned unchanged.

**SEE ALSO**

iswlower(3), tolower(3), towupper(3), wctrans(3)

**STANDARDS**

The **towlower**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD October 3, 2002 BSD

--------------
