--------------

DUPLOCALE(3) BSD Library Functions Manual DUPLOCALE(3)

**NAME**

**duplocale** — duplicate an locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*locale_t*

**duplocale**\ (*locale_t locale*);

**DESCRIPTION**

Duplicates an existing *locale_t* returning a new *locale_t* that refers
to the same locale values but has an independent internal state. Various
functions, such as mblen(3) require a persistent state. These functions
formerly used static variables and calls to them from multiple threads
had undefined behavior. They now use fields in the *locale_t* associated
with the current thread by uselocale(3). These calls are therefore only
thread safe on threads with a unique per-thread locale. The locale
returned by this call must be freed with freelocale(3).

**SEE ALSO**

freelocale(3), localeconv(3), newlocale(3), querylocale(3),
uselocale(3), xlocale(3)

**STANDARDS**

This function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**BUGS**

Ideally, uselocale(3) should make a copy of the *locale_t* implicitly to
ensure thread safety, and a copy of the global locale should be
installed lazily on each thread. The FreeBSD implementation does not do
this, for compatibility with Darwin.

BSD September 17, 2011 BSD

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

