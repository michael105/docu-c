--------------

WCTYPE(3) BSD Library Functions Manual WCTYPE(3)

**NAME**

**iswctype**, **wctype** — wide character class functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*int*

**iswctype**\ (*wint_t wc*, *wctype_t charclass*);

*wctype_t*

**wctype**\ (*const char *property*);

**DESCRIPTION**

The **wctype**\ () function returns a value of type *wctype_t* which
represents the requested wide character class and may be used as the
second argument for calls to **iswctype**\ ().

The following character class names are recognised:

+-----------------+-----------------+-----------------+-----------------+
|                 | alnum           | cntrl           | ideogram        |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | print           |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | space           |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | xdigit          |
+-----------------+-----------------+-----------------+-----------------+
|                 | alpha           | digit           | lower           |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | punct           |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | special         |
+-----------------+-----------------+-----------------+-----------------+
|                 | blank           | graph           | phonogram       |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | rune            |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 |                 | upper           |
+-----------------+-----------------+-----------------+-----------------+

The **iswctype**\ () function checks whether the wide character *wc* is
in the character class *charclass*.

**RETURN VALUES**

The **iswctype**\ () function returns non-zero if and only if *wc* has
the property described by *charclass*, or *charclass* is zero.

The **wctype**\ () function returns 0 if *property* is invalid,
otherwise it returns a value of type *wctype_t* that can be used in
subsequent calls to **iswctype**\ ().

**EXAMPLES**

Reimplement iswalpha(3) in terms of **iswctype**\ () and **wctype**\ ():

| int
| myiswalpha(wint_t wc)
| {

+-----------------------+-----------------------+-----------------------+
|                       | return (iswctype(wc,  |                       |
|                       | wctype("alpha")));    |                       |
+-----------------------+-----------------------+-----------------------+

}

**SEE ALSO**

ctype(3), nextwctype(3)

**STANDARDS**

The **iswctype**\ () and **wctype**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’). The ‘‘ideogram’’, ‘‘phonogram’’, ‘‘special’’,
and ‘‘rune’’ character classes are extensions.

**HISTORY**

The **iswctype**\ () and **wctype**\ () functions first appeared in
FreeBSD 5.0.

BSD March 27, 2004 BSD

--------------
