--------------

CTYPE_L(3) BSD Library Functions Manual CTYPE_L(3)

**NAME**

**digittoint_l**, **isalnum_l**, **isalpha_l**, **isascii_l**,
**isblank_l**, **iscntrl_l**, **isdigit_l**, **isgraph_l**,
**ishexnumber_l**, **isideogram_l**, **islower_l**, **isnumber_l**,
**isphonogram_l**, **isprint_l**, **ispunct_l**, **isrune_l**,
**isspace_l**, **isspecial_l**, **isupper_l**, **isxdigit_l**,
**tolower_l**, **toupper_l** — character classification functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**digittoint_l**\ (*int c*, *locale_t loc*);

*int*

**isalnum_l**\ (*int c*, *locale_t loc*);

*int*

**isalpha_l**\ (*int c*, *locale_t loc*);

*int*

**isascii_l**\ (*int c*, *locale_t loc*);

*int*

**iscntrl_l**\ (*int c*, *locale_t loc*);

*int*

**isdigit_l**\ (*int c*, *locale_t loc*);

*int*

**isgraph_l**\ (*int c*, *locale_t loc*);

*int*

**ishexnumber_l**\ (*int c*, *locale_t loc*);

*int*

**isideogram_l**\ (*int c*, *locale_t loc*);

*int*

**islower_l**\ (*int c*, *locale_t loc*);

*int*

**isnumber_l**\ (*int c*, *locale_t loc*);

*int*

**isphonogram_l**\ (*int c*, *locale_t loc*);

*int*

**isspecial_l**\ (*int c*, *locale_t loc*);

*int*

**isprint_l**\ (*int c*, *locale_t loc*);

*int*

**ispunct_l**\ (*int c*, *locale_t loc*);

*int*

**isrune_l**\ (*int c*, *locale_t loc*);

*int*

**isspace_l**\ (*int c*, *locale_t loc*);

*int*

**isupper_l**\ (*int c*, *locale_t loc*);

*int*

**isxdigit_l**\ (*int c*, *locale_t loc*);

*int*

**tolower_l**\ (*int c*, *locale_t loc*);

*int*

**toupper_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The above functions perform character tests and conversions on the
integer *c* in the locale *loc*. They behave in the same way as the
versions without the \_l suffix, but use the specified locale rather
than the global or per-thread locale. <*ctype.h*>, or as true functions
in the C library. See the specific manual pages for more information.

**SEE ALSO**

digittoint(3), isalnum(3), isalpha(3), isascii(3), isblank(3),
iscntrl(3), isdigit(3), isgraph(3), isideogram(3), islower(3),
isphonogram(3), isprint(3), ispunct(3), isrune(3), isspace(3),
isspecial(3), isupper(3), isxdigit(3), tolower(3), toupper(3),
wctype(3), xlocale(3)

**STANDARDS**

These functions conform to IEEE Std 1003.1-2008 (‘‘POSIX.1’’), except
for **digittoint_l**\ (), **isascii_l**\ (), **ishexnumber_l**\ (),
**isideogram_l**\ (), **isnumber_l**\ (), **isphonogram_l**\ (),
**isrune_l**\ () and **isspecial_l**\ () which are FreeBSD extensions.

BSD March 6, 2012 BSD

--------------
