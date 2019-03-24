--------------

MBLEN(3) BSD Library Functions Manual MBLEN(3)

**NAME**

**mblen** — get number of bytes in a character

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**mblen**\ (*const char *mbchar*, *size_t nbytes*);

**DESCRIPTION**

The **mblen**\ () function computes the length in bytes of a multibyte
character *mbchar* according to the current conversion state. Up to
*nbytes* bytes are examined.

A call with a null *mbchar* pointer returns nonzero if the current
locale requires shift states, zero otherwise; if shift states are
required, the shift state is reset to the initial state.

**RETURN VALUES**

If *mbchar* is NULL, the **mblen**\ () function returns nonzero if shift
states are supported, zero otherwise.

Otherwise, if *mbchar* is not a null pointer, **mblen**\ () either
returns 0 if *mbchar* represents the null wide character, or returns the
number of bytes processed in *mbchar*, or returns −1 if no multibyte
character could be recognized or converted. In this case,
**mblen**\ ()’s internal conversion state is undefined.

**ERRORS**

The **mblen**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The internal conversion state is not valid.

**SEE ALSO**

mbrlen(3), mbtowc(3), multibyte(3)

**STANDARDS**

The **mblen**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 11, 2004 BSD

--------------
