--------------

TIMINGSAFE_BCMP(3) BSD Library Functions Manual TIMINGSAFE_BCMP(3)

**NAME**

**timingsafe_bcmp**, **timingsafe_memcmp** — timing-safe byte sequence
comparisons

**SYNOPSIS**

**#include <string.h>**

*int*

**timingsafe_bcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

*int*

**timingsafe_memcmp**\ (*const void *b1*, *const void *b2*,
*size_t len*);

**DESCRIPTION**

The **timingsafe_bcmp**\ () and **timingsafe_memcmp**\ () functions
lexicographically compare the first *len* bytes (each interpreted as an
*unsigned char*) pointed to by *b1* and *b2*.

Additionally, their running times are independent of the byte sequences
compared, making them safe to use for comparing secret values such as
cryptographic MACs. In contrast, bcmp(3) and memcmp(3) may short-circuit
after finding the first differing byte.

**RETURN VALUES**

The **timingsafe_bcmp**\ () function returns 0 or not zero if the byte
sequence pointed to by *b1* compares equal to or not equal to
(respectively) the byte sequence pointed to by *b2*.

The **timingsafe_memcmp**\ () function returns a negative value, 0, or
positive value if the byte sequence pointed to by *b1* compares less
than, equal to, or greater than (respectively) the byte sequence pointed
to by *b2*.

**SEE ALSO**

bcmp(3), memcmp(3)

**STANDARDS**

The **timingsafe_bcmp**\ () and **timingsafe_memcmp**\ () functions are
FreeBSD extensions.

**HISTORY**

The **timingsafe_bcmp**\ () function first appeared in OpenBSD 4.9.

The **timingsafe_memcmp**\ () function first appeared in OpenBSD 5.6.

Both functions first appeared in FreeBSD 12.0.

BSD August 15, 2016 BSD

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

