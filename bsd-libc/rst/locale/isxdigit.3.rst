--------------

ISXDIGIT(3) BSD Library Functions Manual ISXDIGIT(3)

**NAME**

**isxdigit**, **ishexnumber** — hexadecimal-digit character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isxdigit**\ (*int c*);

*int*

**ishexnumber**\ (*int c*);

**DESCRIPTION**

The **isxdigit**\ () function tests for any hexadecimal-digit character.
Regardless of locale, this includes the following characters only:

+-----------------------------------+-----------------------------------+
|                                   | ‘‘0’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘1’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘2’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘3’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘4’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘5’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘6’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘7’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘8’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘9’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘A’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘B’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘C’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘D’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘E’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘F’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘a’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘b’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘c’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘d’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘e’’                             |
+-----------------------------------+-----------------------------------+
|                                   | ‘‘f’’                             |
+-----------------------------------+-----------------------------------+

The **ishexnumber**\ () function behaves similarly to **isxdigit**\ (),
but may recognize additional characters, depending on the current locale
setting.

The value of the argument must be representable as an *unsigned char* or
the value of EOF.

**RETURN VALUES**

The **isxdigit**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswxdigit**\ () function should be used instead.

**SEE ALSO**

ctype(3), iswxdigit(3), ascii(7)

**STANDARDS**

The **isxdigit**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’).

**HISTORY**

The **ishexnumber**\ () function appeared in 4.4BSD.

BSD July 17, 2005 BSD

--------------
