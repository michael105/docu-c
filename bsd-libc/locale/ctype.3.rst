--------------

CTYPE(3) BSD Library Functions Manual CTYPE(3)

**NAME**

**digittoint**, **isalnum**, **isalpha**, **isascii**, **isblank**,
**iscntrl**, **isdigit**, **isgraph**, **ishexnumber**, **isideogram**,
**islower**, **isnumber**, **isphonogram**, **isprint**, **ispunct**,
**isrune**, **isspace**, **isspecial**, **isupper**, **isxdigit**,
**toascii**, **tolower**, **toupper** — character classification
functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**digittoint**\ (*int c*);

*int*

**isalnum**\ (*int c*);

*int*

**isalpha**\ (*int c*);

*int*

**isascii**\ (*int c*);

*int*

**iscntrl**\ (*int c*);

*int*

**isdigit**\ (*int c*);

*int*

**isgraph**\ (*int c*);

*int*

**ishexnumber**\ (*int c*);

*int*

**isideogram**\ (*int c*);

*int*

**islower**\ (*int c*);

*int*

**isnumber**\ (*int c*);

*int*

**isphonogram**\ (*int c*);

*int*

**isspecial**\ (*int c*);

*int*

**isprint**\ (*int c*);

*int*

**ispunct**\ (*int c*);

*int*

**isrune**\ (*int c*);

*int*

**isspace**\ (*int c*);

*int*

**isupper**\ (*int c*);

*int*

**isxdigit**\ (*int c*);

*int*

**toascii**\ (*int c*);

*int*

**tolower**\ (*int c*);

*int*

**toupper**\ (*int c*);

**DESCRIPTION**

The above functions perform character tests and conversions on the
integer *c*. They are available as macros, defined in the include file
<*ctype.h*>, or as true functions in the C library. See the specific
manual pages for more information.

**SEE ALSO**

digittoint(3), isalnum(3), isalpha(3), isascii(3), isblank(3),
iscntrl(3), isdigit(3), isgraph(3), isideogram(3), islower(3),
isphonogram(3), isprint(3), ispunct(3), isrune(3), isspace(3),
isspecial(3), isupper(3), isxdigit(3), toascii(3), tolower(3),
toupper(3), wctype(3), ascii(7)

**STANDARDS**

These functions, except for **digittoint**\ (), **isascii**\ (),
**ishexnumber**\ (), **isideogram**\ (), **isnumber**\ (),
**isphonogram**\ (), **isrune**\ (), **isspecial**\ () and
**toascii**\ (), conform to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD March 30, 2004 BSD

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

