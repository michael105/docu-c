--------------

WCSTOL(3) BSD Library Functions Manual WCSTOL(3)

**NAME**

**wcstol**, **wcstoul**, **wcstoll**, **wcstoull**, **wcstoimax**,
**wcstoumax** — convert a wide character string value to a *long*,
*unsigned long*, *long long*, *unsigned long long*, *intmax_t* or
*uintmax_t* integer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*long*

**wcstol**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

*unsigned long*

**wcstoul**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

*long long*

**wcstoll**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

*unsigned long long*

**wcstoull**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

**#include <inttypes.h>**

*intmax_t*

**wcstoimax**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

*uintmax_t*

**wcstoumax**\ (*const wchar_t * restrict nptr*,
*wchar_t ** restrict endptr*, *int base*);

**DESCRIPTION**

The **wcstol**\ (), **wcstoul**\ (), **wcstoll**\ (), **wcstoull**\ (),
**wcstoimax**\ () and **wcstoumax**\ () functions are wide-character
versions of the **strtol**\ (), **strtoul**\ (), **strtoll**\ (),
**strtoull**\ (), **strtoimax**\ () and **strtoumax**\ () functions,
respectively. Refer to their manual pages (for example strtol(3)) for
details.

**SEE ALSO**

strtol(3), strtoul(3)

**STANDARDS**

The **wcstol**\ (), **wcstoul**\ (), **wcstoll**\ (), **wcstoull**\ (),
**wcstoimax**\ () and **wcstoumax**\ () functions conform to ISO/IEC
9899:1999 (‘‘ISO C99’’).

BSD September 7, 2002 BSD

--------------
