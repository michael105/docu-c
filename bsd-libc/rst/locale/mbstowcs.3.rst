--------------

MBSTOWCS(3) BSD Library Functions Manual MBSTOWCS(3)

**NAME**

**mbstowcs** — convert a character string to a wide-character string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*size_t*

**mbstowcs**\ (*wchar_t * restrict wcstring*,
*const char * restrict mbstring*, *size_t nwchars*);

**DESCRIPTION**

The **mbstowcs**\ () function converts a multibyte character string
*mbstring* beginning in the initial conversion state into a wide
character string *wcstring*. No more than *nwchars* wide characters are
stored. A terminating null wide character is appended if there is room.

**RETURN VALUES**

The **mbstowcs**\ () function returns the number of wide characters
converted, not counting any terminating null wide character, or −1 if an
invalid multibyte character was encountered.

**ERRORS**

The **mbstowcs**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbsrtowcs(3), mbtowc(3), multibyte(3)

**STANDARDS**

The **mbstowcs**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD April 8, 2004 BSD

--------------
