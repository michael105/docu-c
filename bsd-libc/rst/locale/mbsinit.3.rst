--------------

MBSINIT(3) BSD Library Functions Manual MBSINIT(3)

**NAME**

**mbsinit** — determine conversion object status

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**mbsinit**\ (*const mbstate_t *ps*);

**DESCRIPTION**

The **mbsinit**\ () function determines whether the *mbstate_t* object
pointed to by *ps* describes an initial conversion state.

**RETURN VALUES**

The **mbsinit**\ () function returns non-zero if *ps* is NULL or
describes an initial conversion state, otherwise it returns zero.

**SEE ALSO**

mbrlen(3), mbrtowc(3), mbsrtowcs(3), multibyte(3), wcrtomb(3),
wcsrtombs(3)

**STANDARDS**

The **mbsinit**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD April 8, 2004 BSD

--------------
