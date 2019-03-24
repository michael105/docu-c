--------------

WCSTOMBS(3) BSD Library Functions Manual WCSTOMBS(3)

**NAME**

**wcstombs** — convert a wide-character string to a character string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*size_t*

**wcstombs**\ (*char * restrict mbstring*,
*const wchar_t * restrict wcstring*, *size_t nbytes*);

**DESCRIPTION**

The **wcstombs**\ () function converts a wide character string
*wcstring* into a multibyte character string, *mbstring*, beginning in
the initial conversion state. Up to *nbytes* bytes are stored in
*mbstring*. Partial multibyte characters at the end of the string are
not stored. The multibyte character string is null terminated if there
is room.

**RETURN VALUES**

The **wcstombs**\ () function returns the number of bytes converted (not
including any terminating null), if successful, otherwise it returns (

*size_t* )−1.

**ERRORS**

The **wcstombs**\ () function will fail if:

[EILSEQ]

An invalid wide character was encountered.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbstowcs(3), multibyte(3), wcsrtombs(3), wctomb(3)

**STANDARDS**

The **wcstombs**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD April 8, 2004 BSD

--------------
