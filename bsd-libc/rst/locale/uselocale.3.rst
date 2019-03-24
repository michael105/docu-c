--------------

USELOCALE(3) BSD Library Functions Manual USELOCALE(3)

**NAME**

**uselocale** — Sets a thread-local locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*locale_t*

**uselocale**\ (*locale_t locale*);

**DESCRIPTION**

Specifies the locale for this thread to use. Specifying
*LC_GLOBAL_LOCALE* disables the per-thread locale, while NULL returns
the current locale without setting a new one.

**RETURN VALUES**

Returns the previous locale, or LC_GLOBAL_LOCALE if this thread has no
locale associated with it.

**SEE ALSO**

duplocale(3), freelocale(3), localeconv(3), newlocale(3),
querylocale(3), xlocale(3)

**STANDARDS**

This function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

BSD September 17, 2011 BSD

--------------
