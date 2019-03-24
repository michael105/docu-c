--------------

--------------

SCANF_L(3) BSD Library Functions Manual SCANF_L(3)

\**NAME*\*

\**scanf_l**, \**fscanf_l**, \**sscanf_l**, \**vfscanf_l**,
\**vscanf_l**, \**vsscanf_l*\* â input format conversion

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <xlocale.h>*\*

\*int\*

\**scanf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*...*);

\*int\*

\**fscanf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**sscanf_l** (*constÂ charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**vfscanf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\*int\*

\**vscanf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*va_listÂ ap*);

\*int\*

\**vsscanf_l** (*constÂ charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\**DESCRIPTION*\*

The above functions scan input according to a specified \*format\* in
the locale \*loc*. They behave in the same way as the versions without
the \_l suffix, but use the specific locale rather than the global or
per-thread locale. See the specific manual pages for more information.

\**SEE ALSO*\*

scanf(3), xlocale(3)

\**STANDARDS*\*

These functions do not conform to any specific standard so they should
be considered as non-portable local extensions.

\**HISTORY*\*

These functions first appeared in Darwin and were first implemented in
FreeBSDÂ 9.1.

BSD AprilÂ 8, 2012 BSD

--------------

--------------
