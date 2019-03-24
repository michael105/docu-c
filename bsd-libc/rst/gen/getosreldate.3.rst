--------------

GETOSRELDATE(3) BSD Library Functions Manual GETOSRELDATE(3)

**NAME**

**getosreldate** — get the value of \__FreeBSD_version

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getosreldate**\ (*void*);

**DESCRIPTION**

The **getosreldate**\ () function returns an integer showing the version
of the currently running FreeBSD kernel. Definitions of the values can
be found in *The Porter’s Handbook*:

**https://www.FreeBSD.org/doc/en/books/porters-handbook/**

**RETURN VALUES**

Upon successful completion, **getosreldate**\ () returns the value
requested; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

| **ENVIRONMENT**
| OSVERSION

If the environment variable OSVERSION is set, it will override the
**getosreldate**\ () return value.

**EXAMPLES**

An example can be found in */usr/share/examples/FreeBSD_version*.

**ERRORS**

The **getosreldate**\ () function may fail and set *errno* for any of
the errors specified for the library function sysctl(3).

**SEE ALSO** *
The Porter’s Handbook*

.

**HISTORY**

The **getosreldate**\ () function appeared in FreeBSD 2.0.

BSD June 13, 2018 BSD

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

