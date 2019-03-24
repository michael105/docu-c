--------------

SCANF_L(3) BSD Library Functions Manual SCANF_L(3)

**NAME**

**scanf_l**, **fscanf_l**, **sscanf_l**, **vfscanf_l**, **vscanf_l**,
**vsscanf_l** — input format conversion

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <xlocale.h>**

*int*

**scanf_l**\ (*locale_t loc*, *const char * restrict format*, *...*);

*int*

**fscanf_l**\ (*FILE * restrict stream*, *locale_t loc*,
*const char * restrict format*, *...*);

*int*

**sscanf_l**\ (*const char * restrict str*, *locale_t loc*,
*const char * restrict format*, *...*);

*int*

**vfscanf_l**\ (*FILE * restrict stream*, *locale_t loc*,
*const char * restrict format*, *va_list ap*);

*int*

**vscanf_l**\ (*locale_t loc*, *const char * restrict format*,
*va_list ap*);

*int*

**vsscanf_l**\ (*const char * restrict str*, *locale_t loc*,
*const char * restrict format*, *va_list ap*);

**DESCRIPTION**

The above functions scan input according to a specified *format* in the
locale *loc*. They behave in the same way as the versions without the
\_l suffix, but use the specific locale rather than the global or
per-thread locale. See the specific manual pages for more information.

**SEE ALSO**

scanf(3), xlocale(3)

**STANDARDS**

These functions do not conform to any specific standard so they should
be considered as non-portable local extensions.

**HISTORY**

These functions first appeared in Darwin and were first implemented in
FreeBSD 9.1.

BSD April 8, 2012 BSD

--------------
