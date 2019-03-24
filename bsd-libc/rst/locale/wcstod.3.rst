--------------

WCSTOD(3) BSD Library Functions Manual WCSTOD(3)

**NAME**

**wcstof**, **wcstod**, **wcstold** — convert string to *float*,
*double* or *long double*

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*float*

**wcstof**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*);

*long double*

**wcstold**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*);

*double*

**wcstod**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*);

**DESCRIPTION**

The **wcstof**\ (), **wcstod**\ () and **wcstold**\ () functions are the
wide-character versions of the **strtof**\ (), **strtod**\ () and
**strtold**\ () functions. Refer to strtod(3) for details.

**SEE ALSO**

strtod(3), wcstol(3)

**STANDARDS**

The **wcstof**\ (), **wcstod**\ () and **wcstold**\ () functions conform
to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD February 22, 2003 BSD

--------------
