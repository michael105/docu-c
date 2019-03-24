--------------

DIGITTOINT(3) BSD Library Functions Manual DIGITTOINT(3)

**NAME**

**digittoint** — convert a numeric character to its integer value

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**digittoint**\ (*int c*);

*int*

**digittoint_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **digittoint**\ () function converts a numeric character to its
corresponding integer value. The character can be any decimal digit or
hexadecimal digit. With hexadecimal characters, the case of the values
does not matter.

The **digittoint_l**\ () function takes an explicit locale argument,
whereas the **digittoint**\ () function use the current global or
per-thread locale.

**RETURN VALUES**

The **digittoint**\ () function always returns an integer from the range
of 0 to 15. If the given character was not a digit as defined by
isxdigit(3), the function will return 0.

**SEE ALSO**

ctype(3), isdigit(3), isxdigit(3), xlocale(3)

BSD April 6, 2001 BSD

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

