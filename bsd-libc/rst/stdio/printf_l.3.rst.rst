--------------

--------------

PRINTF_L(3) BSD Library Functions Manual PRINTF_L(3)

\**NAME*\*

\**printf_l**, \**asprintf_l**, \**fprintf_l**, \**snprintf_l**,
\**sprintf_l**, \**vasprintf_l**, \**vfprintf_l**, \**vprintf_l**,
\**vsnprintf_l**, \**vsprintf_l*\* â formatted output conversion

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <xlocale.h>*\*

\*int\*

\**printf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*...*);

\*int\*

\**asprintf_l** (*charÂ **ret*, \*locale_tÂ loc*,
\*constÂ charÂ *Â format*, \*...*);

\*int\*

\**fprintf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**snprintf_l** (*charÂ *Â restrictÂ str*, \*size_tÂ size*,
\*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**sprintf_l** (*charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**vasprintf_l** (*charÂ **ret*, \*locale_tÂ loc*,
\*constÂ charÂ *format*, \*va_listÂ ap*);

\*int\*

\**vfprintf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\*int\*

\**vprintf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*va_listÂ ap*);

\*int\*

\**vsnprintf_l** (*charÂ *Â restrictÂ str*, \*size_tÂ size*,
\*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\*int\*

\**vsprintf_l** (*charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\**DESCRIPTION*\*

The above functions are used to convert formatted output in the locale
\*loc*. They behave in the same way as the versions without the \_l
suffix, but use the specified locale rather than the global or
per-thread locale. See the specific manual pages for more information.

\**SEE ALSO*\*

printf(3), xlocale(3)

\**STANDARDS*\*

These functions do not conform to any specific standard so they should
be considered as non-portable local extensions.

\**HISTORY*\*

These functions first appeared in Darwin and were first implemented in
FreeBSDÂ 9.1.

BSD AprilÂ 7, 2012 BSD

--------------

--------------
