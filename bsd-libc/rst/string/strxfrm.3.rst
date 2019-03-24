--------------

STRXFRM(3) BSD Library Functions Manual STRXFRM(3)

**NAME**

**strxfrm** — transform a string under locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*size_t*

**strxfrm**\ (*char * restrict dst*, *const char * restrict src*,
*size_t n*);

*size_t*

**strxfrm_l**\ (*char * restrict dst*, *const char *restrict src*,
*size_t n*, *locale_t loc*);

**DESCRIPTION**

The **strxfrm**\ () function transforms a null-terminated string pointed
to by *src* according to the current locale collation if any, then
copies the transformed string into *dst*. Not more than *n* characters
are copied into *dst*, including the terminating null character added.
If *n* is set to 0 (it helps to determine an actual size needed for
transformation), *dst* is permitted to be a NULL pointer.

Comparing two strings using **strcmp**\ () after **strxfrm**\ () is
equal to comparing two original strings with **strcoll**\ ().

**strxfrm_l**\ () does the same, however takes an explicit locale rather
than the global locale.

**RETURN VALUES**

Upon successful completion, **strxfrm**\ () and **strxfrm_l**\ () return
the length of the transformed string not including the terminating null
character. If this value is *n* or more, the contents of *dst* are
indeterminate.

**SEE ALSO**

setlocale(3), strcmp(3), strcoll(3), wcsxfrm(3)

**STANDARDS**

The **strxfrm**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **strxfrm_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD June 4, 1993 BSD

--------------
