--------------

--------------

FPUTWS(3) BSD Library Functions Manual FPUTWS(3)

\**NAME*\*

\**fputws*\* â output a line of wide characters to a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <wchar.h>*\*

\*int\*

\**fputws** (*constÂ wchar_tÂ *Â restrictÂ ws*,
\*FILEÂ *Â restrictÂ fp*);

\**DESCRIPTION*\*

The \**fputws** () function writes the wide character string pointed to
by \*ws\* to the stream pointed to by \*fp*.

\**RETURN VALUES*\*

The \**fputws** () function returns 0 on success and â1 on error.

\**ERRORS*\*

The \**fputws** () function will fail if:

[EBADF]

The \*fp\* argument supplied is not a writable stream.

The \**fputws** () function may also fail and set \*errno\* for any of
the errors specified for the routine write(2).

\**SEE ALSO*\*

ferror(3), fputs(3), putwc(3), stdio(3)

\**STANDARDS*\*

The \**fputws** () function conforms to IEEE Std 1003.1-2001
(ââPOSIX.1ââ).

BSD AugustÂ 6, 2002 BSD

--------------

--------------
