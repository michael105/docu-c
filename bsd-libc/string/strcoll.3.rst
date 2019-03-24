--------------

STRCOLL(3) BSD Library Functions Manual STRCOLL(3)

**NAME**

**strcoll** — compare strings according to current collation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**strcoll**\ (*const char *s1*, *const char *s2*);

*int*

**strcoll_l**\ (*const char *s1*, *const char *s2*, *locale_t loc*);

**DESCRIPTION**

The **strcoll**\ () function lexicographically compares the
null-terminated strings *s1* and *s2* according to the current locale
collation and returns an integer greater than, equal to, or less than 0,
depending on whether *s1* is greater than, equal to, or less than *s2*.
If information about the current locale collation is not available, the
value of **strcmp**\ (*s1*, *s2*) is returned. The **strcoll_l**\ ()
function uses an explicit locale argument rather than the system locale.

**SEE ALSO**

setlocale(3), strcmp(3), strxfrm(3), wcscoll(3)

**STANDARDS**

The **strcoll**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **strcoll_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD June 4, 1993 BSD

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

