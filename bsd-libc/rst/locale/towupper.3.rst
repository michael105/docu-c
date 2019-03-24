--------------

TOWUPPER(3) BSD Library Functions Manual TOWUPPER(3)

**NAME**

**towupper** — lower case to upper case letter conversion (wide
character version)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*wint_t*

**towupper**\ (*wint_t wc*);

**DESCRIPTION**

The **towupper**\ () function converts a lower-case letter to the
corresponding upper-case letter.

**RETURN VALUES**

If the argument is a lower-case letter, the **towupper**\ () function
returns the corresponding upper-case letter if there is one; otherwise
the argument is returned unchanged.

**SEE ALSO**

iswupper(3), toupper(3), towlower(3), wctrans(3)

**STANDARDS**

The **towupper**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD October 3, 2002 BSD

--------------
