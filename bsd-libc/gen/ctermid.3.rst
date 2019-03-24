--------------

CTERMID(3) BSD Library Functions Manual CTERMID(3)

**NAME**

**ctermid** — generate terminal pathname

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*char \**

**ctermid**\ (*char *buf*);

*char \**

**ctermid_r**\ (*char *buf*);

**DESCRIPTION**

The **ctermid**\ () function generates a string, that, when used as a
pathname, refers to the current controlling terminal of the calling
process.

If *buf* is the NULL pointer, a pointer to a static area is returned.
Otherwise, the pathname is copied into the memory referenced by *buf*.
The argument *buf* is assumed to be at least L_ctermid (as defined in
the include file <*stdio.h*>) bytes long.

The **ctermid_r**\ () function provides the same functionality as
**ctermid**\ () except that if *buf* is a NULL pointer, NULL is
returned.

If no suitable lookup of the controlling terminal name can be performed,
this implementation returns ‘/dev/tty’.

**RETURN VALUES**

Upon successful completion, a non-NULL pointer is returned. Otherwise, a
NULL pointer is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The current implementation detects no error conditions.

**SEE ALSO**

ttyname(3)

**STANDARDS**

The **ctermid**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**BUGS**

By default the **ctermid**\ () function writes all information to an
internal static object. Subsequent calls to **ctermid**\ () will modify
the same object.

BSD October 1, 2011 BSD

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

