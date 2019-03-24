--------------

ISBLANK(3) BSD Library Functions Manual ISBLANK(3)

**NAME**

**isblank** — space or tab character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isblank**\ (*int c*);

*int*

**isblank_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **isblank**\ () function tests for a space or tab character. For any
locale, this includes the following standard characters:

‘‘

\\t ’’ ‘‘ ’’

In the "C" locale, a successful **isblank**\ () test is limited to these
characters only. The value of the argument must be representable as an
*unsigned char* or the value of EOF.

The **isblank_l**\ () function takes an explicit locale argument,
whereas the **isblank**\ () function uses the current global or
per-thread locale.

**RETURN VALUES**

The **isblank**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswblank**\ () function should be used instead.

**SEE ALSO**

ctype(3), iswblank(3), xlocale(3), ascii(7)

**STANDARDS**

The **isblank**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’). The **isblank_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD July 17, 2005 BSD

--------------
