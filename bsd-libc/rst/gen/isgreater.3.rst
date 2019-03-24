--------------

ISGREATER(3) BSD Library Functions Manual ISGREATER(3)

**NAME**

**isgreater**, **isgreaterequal**, **isless**, **islessequal**,
**islessgreater**, **isunordered** — compare two floating-point numbers

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <math.h>**

*int*

**isgreater**\ (*real-floating x*, *real-floating y*);

*int*

**isgreaterequal**\ (*real-floating x*, *real-floating y*);

*int*

**isless**\ (*real-floating x*, *real-floating y*);

*int*

**islessequal**\ (*real-floating x*, *real-floating y*);

*int*

**islessgreater**\ (*real-floating x*, *real-floating y*);

*int*

**isunordered**\ (*real-floating x*, *real-floating y*);

**DESCRIPTION**

Each of the macros **isgreater**\ (), **isgreaterequal**\ (),
**isless**\ (), **islessequal**\ (), and **islessgreater**\ () take
arguments *x* and *y* and return a non-zero value if and only if its
nominal relation on *x* and *y* is true. These macros always return zero
if either argument is not a number (NaN), but unlike the corresponding C
operators, they never raise a floating point exception.

The **isunordered**\ () macro takes arguments *x* and *y* and returns
non-zero if and only if any of *x* or *y* are NaNs. For any pair of
floating-point values, one of the relationships (less, greater, equal,
unordered) holds.

**SEE ALSO**

fpclassify(3), math(3), signbit(3)

**STANDARDS**

The **isgreater**\ (), **isgreaterequal**\ (), **isless**\ (),
**islessequal**\ (), **islessgreater**\ (), and **isunordered**\ ()
macros conform to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The relational macros described above first appeared in FreeBSD 5.1.

BSD February 12, 2003 BSD

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

