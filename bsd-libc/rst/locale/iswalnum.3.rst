--------------

ISWALNUM(3) BSD Library Functions Manual ISWALNUM(3)

**NAME**

**iswalnum**, **iswalpha**, **iswascii**, **iswblank**, **iswcntrl**,
**iswdigit**, **iswgraph**, **iswhexnumber**, **iswideogram**,
**iswlower**, **iswnumber**, **iswphonogram**, **iswprint**,
**iswpunct**, **iswrune**, **iswspace**, **iswspecial**, **iswupper**,
**iswxdigit** — wide character classification utilities

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*int*

**iswalnum**\ (*wint_t wc*);

*int*

**iswalpha**\ (*wint_t wc*);

*int*

**iswascii**\ (*wint_t wc*);

*int*

**iswblank**\ (*wint_t wc*);

*int*

**iswcntrl**\ (*wint_t wc*);

*int*

**iswdigit**\ (*wint_t wc*);

*int*

**iswgraph**\ (*wint_t wc*);

*int*

**iswhexnumber**\ (*wint_t wc*);

*int*

**iswideogram**\ (*wint_t wc*);

*int*

**iswlower**\ (*wint_t wc*);

*int*

**iswnumber**\ (*wint_t wc*);

*int*

**iswphonogram**\ (*wint_t wc*);

*int*

**iswprint**\ (*wint_t wc*);

*int*

**iswpunct**\ (*wint_t wc*);

*int*

**iswrune**\ (*wint_t wc*);

*int*

**iswspace**\ (*wint_t wc*);

*int*

**iswspecial**\ (*wint_t wc*);

*int*

**iswupper**\ (*wint_t wc*);

*int*

**iswxdigit**\ (*wint_t wc*);

**DESCRIPTION**

The above functions are character classification utility functions, for
use with wide characters (*wchar_t* or *wint_t*). See the description
for the similarly-named single byte classification functions (like
isalnum(3)), for details.

**RETURN VALUES**

The functions return zero if the character tests false and return
non-zero if the character tests true.

**SEE ALSO**

isalnum(3), isalpha(3), isascii(3), isblank(3), iscntrl(3), isdigit(3),
isgraph(3), ishexnumber(3), isideogram(3), islower(3), isnumber(3),
isphonogram(3), isprint(3), ispunct(3), isrune(3), isspace(3),
isspecial(3), isupper(3), isxdigit(3), wctype(3)

**STANDARDS**

These functions conform to IEEE Std 1003.1-2001 (‘‘POSIX.1’’), except
**iswascii**\ (), **iswhexnumber**\ (), **iswideogram**\ (),
**iswnumber**\ (), **iswphonogram**\ (), **iswrune**\ () and
**iswspecial**\ (), which are FreeBSD extensions.

**CAVEATS**

The result of these functions is undefined unless the argument is WEOF
or a valid *wchar_t* value for the current locale.

BSD October 3, 2002 BSD

--------------
