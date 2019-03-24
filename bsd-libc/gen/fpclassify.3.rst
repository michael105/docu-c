--------------

FPCLASSIFY(3) BSD Library Functions Manual FPCLASSIFY(3)

**NAME**

**fpclassify**, **isfinite**, **isinf**, **isnan**, **isnormal** —
classify a floating-point number

**LIBRARY**

Math Library (libm, −lm)

**SYNOPSIS**

**#include <math.h>**

*int*

**fpclassify**\ (*real-floating x*);

*int*

**isfinite**\ (*real-floating x*);

*int*

**isinf**\ (*real-floating x*);

*int*

**isnan**\ (*real-floating x*);

*int*

**isnormal**\ (*real-floating x*);

**DESCRIPTION**

The **fpclassify**\ () macro takes an argument of *x* and returns one of
the following manifest constants.

FP_INFINITE

Indicates that *x* is an infinite number.

FP_NAN

Indicates that *x* is not a number (NaN).

FP_NORMAL

Indicates that *x* is a normalized number.

FP_SUBNORMAL

Indicates that *x* is a denormalized number.

FP_ZERO

Indicates that *x* is zero (0 or −0).

The **isfinite**\ () macro returns a non-zero value if and only if its
argument has a finite (zero, subnormal, or normal) value. The
**isinf**\ (), **isnan**\ (), and **isnormal**\ () macros return
non-zero if and only if *x* is an infinity, NaN, or a non-zero
normalized number, respectively.

The symbol **isnanf**\ () is provided as an alias to **isnan**\ () for
compatibility, and its use is deprecated. Similarly, **finite**\ () and
**finitef**\ () are deprecated versions of **isfinite**\ ().

**SEE ALSO**

isgreater(3), math(3), signbit(3)

**STANDARDS**

The **fpclassify**\ (), **isfinite**\ (), **isinf**\ (), **isnan**\ (),
and **isnormal**\ () macros conform to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The **fpclassify**\ (), **isfinite**\ (), **isinf**\ (), **isnan**\ (),
and **isnormal**\ () macros were added in FreeBSD 5.1. 3BSD introduced
**isinf**\ () and **isnan**\ () functions, which accepted *double*
arguments; these have been superseded by the macros described above.

BSD January 26, 2005 BSD

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

