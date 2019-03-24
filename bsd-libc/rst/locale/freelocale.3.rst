--------------

FREELOCALE(3) BSD Library Functions Manual FREELOCALE(3)

**NAME**

**freelocale** — Frees a locale created with duplocale(3) or
newlocale(3)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*void*

**freelocale**\ (*locale_t locale*);

**DESCRIPTION**

Frees a *locale_t*. This relinquishes any resources held exclusively by
this locale. Note that locales share reference-counted components, so a
call to this function is not guaranteed to free all of the components.

**SEE ALSO**

duplocale(3), localeconv(3), newlocale(3), querylocale(3), uselocale(3),
xlocale(3)

**STANDARDS**

This function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

BSD July 26, 2016 BSD

--------------
