--------------

DIGITTOINT(3) BSD Library Functions Manual DIGITTOINT(3)

**NAME**

**digittoint** — convert a numeric character to its integer value

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**digittoint**\ (*int c*);

*int*

**digittoint_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **digittoint**\ () function converts a numeric character to its
corresponding integer value. The character can be any decimal digit or
hexadecimal digit. With hexadecimal characters, the case of the values
does not matter.

The **digittoint_l**\ () function takes an explicit locale argument,
whereas the **digittoint**\ () function use the current global or
per-thread locale.

**RETURN VALUES**

The **digittoint**\ () function always returns an integer from the range
of 0 to 15. If the given character was not a digit as defined by
isxdigit(3), the function will return 0.

**SEE ALSO**

ctype(3), isdigit(3), isxdigit(3), xlocale(3)

BSD April 6, 2001 BSD

--------------
