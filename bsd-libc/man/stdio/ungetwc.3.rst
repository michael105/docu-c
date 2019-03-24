--------------

UNGETWC(3) BSD Library Functions Manual UNGETWC(3)

**NAME**

**ungetwc** — un-get wide character from input stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*wint_t*

**ungetwc**\ (*wint_t wc*, *FILE *stream*);

**DESCRIPTION**

The **ungetwc**\ () function pushes the wide character *wc* (converted
to an *wchar_t*) back onto the input stream pointed to by *stream*. The
pushed-backed wide characters will be returned by subsequent reads on
the stream (in reverse order). A successful intervening call, using the
same stream, to one of the file positioning functions fseek(3),
fsetpos(3), or rewind(3) will discard the pushed back wide characters.

One wide character of push-back is guaranteed, but as long as there is
sufficient memory, an effectively infinite amount of pushback is
allowed.

If a character is successfully pushed-back, the end-of-file indicator
for the stream is cleared.

**RETURN VALUES**

The **ungetwc**\ () function returns the wide character pushed-back
after the conversion, or WEOF if the operation fails. If the value of
the argument *c* character equals WEOF, the operation will fail and the
stream will remain unchanged.

**SEE ALSO**

fseek(3), getwc(3)

**STANDARDS**

The **ungetwc**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD March 3, 2004 BSD

--------------
