--------------

WCSFTIME(3) BSD Library Functions Manual WCSFTIME(3)

**NAME**

**wcsftime** — convert date and time to a wide-character string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**wcsftime**\ (*wchar_t * restrict wcs*, *size_t maxsize*,
*const wchar_t * restrict format*,
*const struct tm * restrict timeptr*);

**DESCRIPTION**

The **wcsftime**\ () function is equivalent to the **strftime**\ ()
function except for the types of its arguments. Refer to strftime(3) for
a detailed description.

**COMPATIBILITY**

Some early implementations of **wcsftime**\ () had a *format* argument
with type *const char \** instead of *const wchar_t \**.

**SEE ALSO**

strftime(3)

**STANDARDS**

The **wcsftime**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD September 8, 2002 BSD

--------------
