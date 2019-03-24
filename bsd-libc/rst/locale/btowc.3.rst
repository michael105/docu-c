--------------

BTOWC(3) BSD Library Functions Manual BTOWC(3)

**NAME**

**btowc**, **wctob** — convert between wide and single-byte characters

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*wint_t*

**btowc**\ (*int c*);

*int*

**wctob**\ (*wint_t c*);

**#include <wchar.h>
#include <xlocale.h>**

*wint_t*

**btowc_l**\ (*int c*, *locale_t loc*);

*int*

**wctob_l**\ (*wint_t c*, *locale_t loc*);

**DESCRIPTION**

The **btowc**\ () function converts a single-byte character into a
corresponding wide character. If the character is EOF or not valid in
the initial shift state, **btowc**\ () returns WEOF.

The **wctob**\ () function converts a wide character into a
corresponding single-byte character. If the wide character is WEOF or
not able to be represented as a single byte in the initial shift state,
**wctob**\ () returns EOF.

The \_l-suffixed versions take an explicit locale argument, while the
non-suffixed versions use the current global or per-thread locale.

**SEE ALSO**

mbrtowc(3), multibyte(3), wcrtomb(3)

**STANDARDS**

The **btowc**\ () and **wctob**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **btowc**\ () and **wctob**\ () functions first appeared in
FreeBSD 5.0.

BSD February 13, 2012 BSD

--------------
