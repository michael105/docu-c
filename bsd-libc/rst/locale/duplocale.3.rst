--------------

DUPLOCALE(3) BSD Library Functions Manual DUPLOCALE(3)

**NAME**

**duplocale** — duplicate an locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*locale_t*

**duplocale**\ (*locale_t locale*);

**DESCRIPTION**

Duplicates an existing *locale_t* returning a new *locale_t* that refers
to the same locale values but has an independent internal state. Various
functions, such as mblen(3) require a persistent state. These functions
formerly used static variables and calls to them from multiple threads
had undefined behavior. They now use fields in the *locale_t* associated
with the current thread by uselocale(3). These calls are therefore only
thread safe on threads with a unique per-thread locale. The locale
returned by this call must be freed with freelocale(3).

**SEE ALSO**

freelocale(3), localeconv(3), newlocale(3), querylocale(3),
uselocale(3), xlocale(3)

**STANDARDS**

This function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**BUGS**

Ideally, uselocale(3) should make a copy of the *locale_t* implicitly to
ensure thread safety, and a copy of the global locale should be
installed lazily on each thread. The FreeBSD implementation does not do
this, for compatibility with Darwin.

BSD September 17, 2011 BSD

--------------
