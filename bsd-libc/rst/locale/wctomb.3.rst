--------------

WCTOMB(3) BSD Library Functions Manual WCTOMB(3)

**NAME**

**wctomb** — convert a wide-character code to a character

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**wctomb**\ (*char *mbchar*, *wchar_t wchar*);

**DESCRIPTION**

The **wctomb**\ () function converts a wide character *wchar* into a
multibyte character and stores the result in *mbchar*. The object
pointed to by *mbchar* must be large enough to accommodate the multibyte
character, which may be up to MB_LEN_MAX bytes.

A call with a null *mbchar* pointer returns nonzero if the current
locale requires shift states, zero otherwise; if shift states are
required, the shift state is reset to the initial state.

**RETURN VALUES**

If *mbchar* is NULL, the **wctomb**\ () function returns nonzero if
shift states are supported, zero otherwise. If *mbchar* is valid,
**wctomb**\ () returns the number of bytes processed in *mbchar*, or −1
if no multibyte character could be recognized or converted. In this
case, **wctomb**\ ()’s internal conversion state is undefined.

**ERRORS**

The **wctomb**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The internal conversion state is invalid.

**SEE ALSO**

mbtowc(3), wcrtomb(3), wcstombs(3), wctob(3)

**STANDARDS**

The **wctomb**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 8, 2004 BSD

--------------
