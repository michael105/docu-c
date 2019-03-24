--------------

ICONV_CANONICALIZE(3) BSD Library Functions Manual ICONV_CANONICALIZE(3)

**NAME**

**iconv_canonicalize** — resolving character encoding names to canonical
form

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*const char \**

**iconv_canonicalize**\ (*const char *name*);

**DESCRIPTION**

The **iconv_canonicalize**\ () function resolves the character encoding
name specified by the *name* argument to its canonical form.

**RETURN VALUES**

Upon successful completion **iconv_canonicalize**\ (), returns the
canonical name of the given encoding. If the specified name is already a
canonical name, the same value is returned. If the specified name is not
an existing character encoding name, NULL is returned.

**SEE ALSO**

iconv(3)

**STANDARDS**

The **iconv_canonicalize** function is a non-standard extension, which
appeared in the GNU implementation and was adopted in FreeBSD 9.0 for
compatibility’s sake.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

BSD October 20, 2009 BSD

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

