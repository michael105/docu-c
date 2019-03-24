--------------

AT_QUICK_EXIT(3) BSD Library Functions Manual AT_QUICK_EXIT(3)

**NAME**

**at_quick_exit** — registers a cleanup function to run on quick exit

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**at_quick_exit**\ (*void (*func)(void)*);

**DESCRIPTION**

The **at_quick_exit**\ () function registers a cleanup function to be
called when the program exits as a result of calling quick_exit(3). The
cleanup functions are called in the reverse order and will not be called
if the program exits by calling exit(3), \_Exit(3), or abort(3).

**RETURN VALUES**

The **at_quick_exit**\ () function returns the value 0 if successful and
a non-zero value on failure.

**SEE ALSO**

exit(3), quick_exit(3)

**STANDARDS**

The **at_quick_exit**\ () function conforms to ISO/IEC 9899:2011
(‘‘ISO C11’’).

BSD December 7, 2011 BSD

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

