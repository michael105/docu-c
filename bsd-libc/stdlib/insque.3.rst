--------------

INSQUE(3) BSD Library Functions Manual INSQUE(3)

**NAME**

**insque**, **remque** — doubly-linked list management

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <search.h>**

*void*

**insque**\ (*void *element1*, *void *pred*);

*void*

**remque**\ (*void *element*);

**DESCRIPTION**

The **insque**\ () and **remque**\ () functions encapsulate the
ever-repeating task of doing insertion and removal operations on doubly
linked lists. The functions expect their arguments to point to a
structure whose first and second members are pointers to the next and
previous element, respectively. The **insque**\ () function also allows
the *pred* argument to be a NULL pointer for the initialization of a new
list’s head element.

**STANDARDS**

The **insque**\ () and **remque**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **insque**\ () and **remque**\ () functions appeared in 4.2BSD. In
FreeBSD 5.0, they reappeared conforming to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD October 10, 2002 BSD

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

