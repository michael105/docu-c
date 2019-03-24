--------------

GETBSIZE(3) BSD Library Functions Manual GETBSIZE(3)

**NAME**

**getbsize** — get preferred block size

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*char \**

**getbsize**\ (*int *headerlenp*, *long *blocksizep*);

**DESCRIPTION**

The **getbsize**\ () function returns a preferred block size for
reporting by system utilities df(1), du(1), ls(1) and systat(1), based
on the value of the BLOCKSIZE environment variable. BLOCKSIZE may be
specified directly in bytes, or in multiples of a kilobyte by specifying
a number followed by ‘‘K’’ or ‘‘k’’, in multiples of a megabyte by
specifying a number followed by ‘‘M’’ or ‘‘m’’ or in multiples of a
gigabyte by specifying a number followed by ‘‘G’’ or ‘‘g’’. Multiples
must be integers.

Valid values of BLOCKSIZE are 512 bytes to 1 gigabyte. Sizes less than
512 bytes are rounded up to 512 bytes, and sizes greater than 1 GB are
rounded down to 1 GB. In each case **getbsize**\ () produces a warning
message via warnx(3).

The **getbsize**\ () function returns a pointer to a null-terminated
string describing the block size, something like ‘‘1K-blocks’’. The
memory referenced by *headerlenp* is filled in with the length of the
string (not including the terminating null). The memory referenced by
*blocksizep* is filled in with block size, in bytes.

**SEE ALSO**

df(1), du(1), ls(1), systat(1), environ(7)

**HISTORY**

The **getbsize**\ () function first appeared in 4.4BSD.

BSD June 11, 2017 BSD

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

