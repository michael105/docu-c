--------------

ULIMIT(3) BSD Library Functions Manual ULIMIT(3)

**NAME**

**ulimit** — get and set process limits

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ulimit.h>**

*long*

**ulimit**\ (*int cmd*, *...*);

**DESCRIPTION**

The **ulimit**\ () function will get and set process limits. Currently
this is limited to the maximum file size. The *cmd* argument is one of
the following:

UL_GETFSIZE

will return the maximum file size in units of 512 blocks of the current
process.

UL_SETFSIZE

will attempt to set the maximum file size of the current process and its
children with the second argument expressed as a long.

**RETURN VALUES**

Upon successful completion, **ulimit**\ () returns the value requested;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **ulimit**\ () function will fail if:

[EINVAL]

The command specified was invalid.

[EPERM]

The limit specified to **ulimit**\ () would have raised the maximum
limit value, and the caller is not the super-user.

**SEE ALSO**

getrlimit(2)

**STANDARDS**

The **ulimit**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **ulimit**\ () function first appeared in FreeBSD 5.0.

**BUGS**

The **ulimit**\ () function provides limited precision for setting and
retrieving process limits. If there is a need for greater precision than
the type *long* provides, the getrlimit(2) and setrlimit(2) functions
should be considered.

BSD January 4, 2003 BSD

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

