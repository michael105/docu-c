--------------

ISSPACE(3) BSD Library Functions Manual ISSPACE(3)

**NAME**

**isspace** — white-space character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isspace**\ (*int c*);

*int*

**isspace_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **isspace**\ () function tests for white-space characters. For any
locale, this includes the following standard characters:

+-----------------------+-----------------------+-----------------------+
|                       | ‘‘\t’’                | ‘‘\n’’                |
+-----------------------+-----------------------+-----------------------+
|                       |                       | ‘‘\v’’                |
+-----------------------+-----------------------+-----------------------+
|                       |                       | ‘‘\f’’                |
+-----------------------+-----------------------+-----------------------+
|                       |                       | ‘‘\r’’                |
+-----------------------+-----------------------+-----------------------+
|                       |                       | ‘‘ ’’                 |
+-----------------------+-----------------------+-----------------------+

In the "C" locale, **isspace**\ () returns non-zero for these characters
only. The value of the argument must be representable as an *unsigned
char* or the value of EOF.

The **isspace_l**\ () function takes an explicit locale argument,
whereas the **isspace**\ () function uses the current global or
per-thread locale.

**RETURN VALUES**

The **isspace**\ () and **isspace_l**\ () functions return zero if the
character tests false and return non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswspace**\ () function should be used instead.

**SEE ALSO**

ctype(3), iswspace(3), multibyte(3), ascii(7)

**STANDARDS**

The **isspace**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **isspace_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD July 30, 2012 BSD

--------------
