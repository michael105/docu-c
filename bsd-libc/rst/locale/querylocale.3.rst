--------------

QUERYLOCALE(3) BSD Library Functions Manual QUERYLOCALE(3)

**NAME**

**querylocale** — Look up the locale name for a specified category

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*const char \**

**querylocale**\ (*int mask*, *locale_t locale*);

**DESCRIPTION**

Returns the name of the locale for the category specified by *mask*.
This possible values for the mask are the same as those in newlocale(3).
If more than one bit in the mask is set, the returned value is
undefined.

**SEE ALSO**

duplocale(3), freelocale(3), localeconv(3), newlocale(3), uselocale(3),
xlocale(3)

BSD May 3, 2013 BSD

--------------
