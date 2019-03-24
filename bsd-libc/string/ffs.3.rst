--------------

FFS(3) BSD Library Functions Manual FFS(3)

**NAME**

**ffs**, **ffsl**, **ffsll**, **fls**, **flsl**, **flsll** — find first
or last bit set in a bit string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*int*

**ffs**\ (*int value*);

*int*

**ffsl**\ (*long value*);

*int*

**ffsll**\ (*long long value*);

*int*

**fls**\ (*int value*);

*int*

**flsl**\ (*long value*);

*int*

**flsll**\ (*long long value*);

**DESCRIPTION**

The **ffs**\ (), **ffsl**\ () and **ffsll**\ () functions find the first
(least significant) bit set in *value* and return the index of that bit.

The **fls**\ (), **flsl**\ () and **flsll**\ () functions find the last
(most significant) bit set in *value* and return the index of that bit.

Bits are numbered starting at 1, the least significant bit. A return
value of zero from any of these functions means that the argument was
zero.

**SEE ALSO**

bitstring(3), bitset(9)

**HISTORY**

The **ffs**\ () function appeared in 4.3BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

The **ffsl**\ (), **fls**\ () and **flsl**\ () functions appeared in
FreeBSD 5.3. The **ffsll**\ () and **flsll**\ () functions appeared in
FreeBSD 7.1.

BSD October 17, 2015 BSD

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

