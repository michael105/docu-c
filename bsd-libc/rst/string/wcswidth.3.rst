--------------

WCSWIDTH(3) BSD Library Functions Manual WCSWIDTH(3)

**NAME**

**wcswidth** — number of column positions in wide-character string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**wcswidth**\ (*const wchar_t *pwcs*, *size_t n*);

**DESCRIPTION**

The **wcswidth**\ () function determines the number of column positions
required for the first *n* characters of *pwcs*, or until a null wide
character (L’\0’) is encountered.

**RETURN VALUES**

The **wcswidth**\ () function returns 0 if *pwcs* is an empty string
(L""), −1 if a non-printing wide character is encountered, otherwise it
returns the number of column positions occupied.

**SEE ALSO**

iswprint(3), wcwidth(3)

**STANDARDS**

The **wcswidth**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD August 20, 2002 BSD

--------------
