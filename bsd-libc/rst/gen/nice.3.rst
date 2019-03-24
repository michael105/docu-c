--------------

NICE(3) BSD Library Functions Manual NICE(3)

**NAME**

**nice** — set program scheduling priority

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**nice**\ (*int incr*);

**DESCRIPTION**

**This interface is obsoleted by** setpriority(\ **2**)\ **.**

The **nice**\ () function adds *incr* to the scheduling priority of the
process. The priority is a value in the range -20 to 20. The default
priority is 0; lower priorities cause more favorable scheduling. Only
the super-user may lower priorities.

Children inherit the priority of their parent processes via fork(2).

**RETURN VALUES**

Upon successful completion, **nice**\ () returns 0, and *errno* is
unchanged. Otherwise, −1 is returned, the process’ nice value is not
changed, and *errno* is set to indicate the error.

**ERRORS**

The **nice**\ () function will fail if:

[EPERM]

The *incr* argument is negative and the caller does not have appropriate
privileges.

**SEE ALSO**

nice(1), fork(2), setpriority(2), renice(8)

**STANDARDS**

The **nice**\ () function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’)
except for the return value. This implementation returns 0 upon
successful completion but the standard requires returning the new nice
value, which could be −1.

**HISTORY**

A **nice**\ () syscall appeared in Version 6 AT&T UNIX.

BSD February 28, 2015 BSD

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

