--------------

MBTOWC(3) BSD Library Functions Manual MBTOWC(3)

**NAME**

**mbtowc** — convert a character to a wide-character code

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**mbtowc**\ (*wchar_t * restrict wcharp*,
*const char * restrict mbchar*, *size_t nbytes*);

**DESCRIPTION**

The **mbtowc**\ () function converts a multibyte character *mbchar* into
a wide character according to the current conversion state, and stores
the result in the object pointed to by *wcharp*. Up to *nbytes* bytes
are examined.

A call with a null *mbchar* pointer returns nonzero if the current
encoding requires shift states, zero otherwise; if shift states are
required, the shift state is reset to the initial state.

**RETURN VALUES**

If *mbchar* is NULL, the **mbtowc**\ () function returns nonzero if
shift states are supported, zero otherwise.

Otherwise, if *mbchar* is not a null pointer, **mbtowc**\ () either
returns 0 if *mbchar* represents the null wide character, or returns the
number of bytes processed in *mbchar*, or returns −1 if no multibyte
character could be recognized or converted. In this case,
**mbtowc**\ ()’s internal conversion state is undefined.

**ERRORS**

The **mbtowc**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The internal conversion state is invalid.

**SEE ALSO**

btowc(3), mblen(3), mbrtowc(3), mbstowcs(3), multibyte(3), wctomb(3)

**STANDARDS**

The **mbtowc**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 11, 2004 BSD

--------------
