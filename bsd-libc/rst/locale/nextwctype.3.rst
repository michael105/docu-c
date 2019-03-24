--------------

NEXTWCTYPE(3) BSD Library Functions Manual NEXTWCTYPE(3)

**NAME**

**nextwctype** — iterate through character classes

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*wint_t*

**nextwctype**\ (*wint_t ch*, *wctype_t wct*);

**DESCRIPTION**

The **nextwctype**\ () function determines the next character after *ch*
that is a member of character class *wct*. If *ch* is −1, the search
begins at the first member of *wct*.

**RETURN VALUES**

The **nextwctype**\ () function returns the next character, or −1 if
there are no more.

**COMPATIBILITY**

This function is a non-standard FreeBSD extension and should not be used
where the standard **iswctype**\ () function would suffice.

**SEE ALSO**

wctype(3)

**HISTORY**

The **nextwctype**\ () function appeared in FreeBSD 5.4.

BSD July 21, 2005 BSD

--------------
