--------------

STRTOFFLAGS(3) BSD Library Functions Manual STRTOFFLAGS(3)

**NAME**

**fflagstostr**, **strtofflags** — convert between file flag bits and
their string names

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**fflagstostr**\ (*u_long flags*);

*int*

**strtofflags**\ (*char **stringp*, *u_long *setp*, *u_long *clrp*);

**DESCRIPTION**

The **fflagstostr**\ () function returns a comma separated string of the
file flags represented by *flags*. If no flags are set a zero length
string is returned.

If memory cannot be allocated for the return value, **fflagstostr**\ ()
returns NULL.

The value returned from **fflagstostr**\ () is obtained from
**malloc**\ () and should be returned to the system with **free**\ ()
when the program is done with it.

The **strtofflags**\ () function takes a string of file flags, as
described in chflags(1), parses it, and returns the ’set’ flags and
’clear’ flags such as would be given as arguments to chflags(2). On
success **strtofflags**\ () returns 0, otherwise it returns non-zero and
*stringp* is left pointing to the offending token.

**ERRORS**

The **fflagstostr**\ () function may fail and set errno for any of the
errors specified for the library routine malloc(3).

**SEE ALSO**

chflags(1), chflags(2), malloc(3)

**HISTORY**

The **fflagstostr**\ () and **strtofflags**\ () functions first appeared
in FreeBSD 4.0.

BSD January 1, 2000 BSD

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

