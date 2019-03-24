--------------

TOASCII(3) BSD Library Functions Manual TOASCII(3)

**NAME**

**toascii** — convert a byte to 7-bit ASCII

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**toascii**\ (*int c*);

**DESCRIPTION**

The **toascii**\ () function strips all but the low 7 bits from a
letter, including parity or other marker bits.

**RETURN VALUES**

The **toascii**\ () function always returns a valid ASCII character.

**SEE ALSO**

digittoint(3), isalnum(3), isalpha(3), isascii(3), iscntrl(3),
isdigit(3), isgraph(3), islower(3), isprint(3), ispunct(3), isspace(3),
isupper(3), isxdigit(3), stdio(3), tolower(3), toupper(3), ascii(7)

BSD June 4, 1993 BSD

--------------
