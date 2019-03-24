--------------

WCSCOLL(3) BSD Library Functions Manual WCSCOLL(3)

**NAME**

**wcscoll** — compare wide strings according to current collation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**wcscoll**\ (*const wchar_t *s1*, *const wchar_t *s2*);

**DESCRIPTION**

The **wcscoll**\ () function compares the null-terminated strings *s1*
and *s2* according to the current locale collation order. In the ‘‘C’’
locale, **wcscoll**\ () is equivalent to **wcscmp**\ ().

**RETURN VALUES**

The **wcscoll**\ () function returns an integer greater than, equal to,
or less than 0, if *s1* is greater than, equal to, or less than *s2*.

No return value is reserved to indicate errors; callers should set
*errno* to 0 before calling **wcscoll**\ (). If it is non-zero upon
return from **wcscoll**\ (), an error has occurred.

**ERRORS**

The **wcscoll**\ () function will fail if:

[EILSEQ]

An invalid wide character code was specified.

[ENOMEM]

Cannot allocate enough memory for temporary buffers.

**SEE ALSO**

setlocale(3), strcoll(3), wcscmp(3), wcsxfrm(3)

**STANDARDS**

The **wcscoll**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**BUGS**

The current implementation of **wcscoll**\ () only works in single-byte
LC_CTYPE locales, and falls back to using **wcscmp**\ () in locales with
extended character sets.

BSD October 4, 2002 BSD

--------------
