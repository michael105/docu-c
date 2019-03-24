--------------

PRINTF_L(3) BSD Library Functions Manual PRINTF_L(3)

**NAME**

**printf_l**, **asprintf_l**, **fprintf_l**, **snprintf_l**,
**sprintf_l**, **vasprintf_l**, **vfprintf_l**, **vprintf_l**,
**vsnprintf_l**, **vsprintf_l** — formatted output conversion

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <xlocale.h>**

*int*

**printf_l**\ (*locale_t loc*, *const char * restrict format*, *...*);

*int*

**asprintf_l**\ (*char **ret*, *locale_t loc*, *const char * format*,
*...*);

*int*

**fprintf_l**\ (*FILE * restrict stream*, *locale_t loc*,
*const char * restrict format*, *...*);

*int*

**snprintf_l**\ (*char * restrict str*, *size_t size*, *locale_t loc*,
*const char * restrict format*, *...*);

*int*

**sprintf_l**\ (*char * restrict str*, *locale_t loc*,
*const char * restrict format*, *...*);

*int*

**vasprintf_l**\ (*char **ret*, *locale_t loc*, *const char *format*,
*va_list ap*);

*int*

**vfprintf_l**\ (*FILE * restrict stream*, *locale_t loc*,
*const char * restrict format*, *va_list ap*);

*int*

**vprintf_l**\ (*locale_t loc*, *const char * restrict format*,
*va_list ap*);

*int*

**vsnprintf_l**\ (*char * restrict str*, *size_t size*, *locale_t loc*,
*const char * restrict format*, *va_list ap*);

*int*

**vsprintf_l**\ (*char * restrict str*, *locale_t loc*,
*const char * restrict format*, *va_list ap*);

**DESCRIPTION**

The above functions are used to convert formatted output in the locale
*loc*. They behave in the same way as the versions without the \_l
suffix, but use the specified locale rather than the global or
per-thread locale. See the specific manual pages for more information.

**SEE ALSO**

printf(3), xlocale(3)

**STANDARDS**

These functions do not conform to any specific standard so they should
be considered as non-portable local extensions.

**HISTORY**

These functions first appeared in Darwin and were first implemented in
FreeBSD 9.1.

BSD April 7, 2012 BSD

--------------
