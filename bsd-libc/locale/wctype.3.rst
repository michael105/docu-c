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

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

