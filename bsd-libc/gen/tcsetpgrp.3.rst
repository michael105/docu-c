--------------

TCSETPGRP(3) BSD Library Functions Manual TCSETPGRP(3)

**NAME**

**tcsetpgrp** — set foreground process group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*int*

**tcsetpgrp**\ (*int fd*, *pid_t pgrp_id*);

**DESCRIPTION**

If the process has a controlling terminal, the **tcsetpgrp**\ ()
function sets the foreground process group ID associated with the
terminal device to *pgrp_id*. The terminal device associated with *fd*
must be the controlling terminal of the calling process and the
controlling terminal must be currently associated with the session of
the calling process. The value of *pgrp_id* must be the same as the
process group ID of a process in the same session as the calling
process.

**RETURN VALUES**

The **tcsetpgrp**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **tcsetpgrp**\ () function will fail if:

[EBADF]

The *fd* argument is not a valid file descriptor.

[EINVAL]

An invalid value of *pgrp_id* was specified.

[ENOTTY]

The calling process does not have a controlling terminal, or the file
represented by *fd* is not the controlling terminal, or the controlling
terminal is no longer associated with the session of the calling
process.

[EPERM]

The *pgrp_id* argument does not match the process group ID of a process
in the same session as the calling process.

**SEE ALSO**

setpgid(2), setsid(2), tcgetpgrp(3)

**STANDARDS**

The **tcsetpgrp**\ () function is expected to be compliant with the IEEE
Std 1003.1-1988 (‘‘POSIX.1’’) specification.

BSD June 4, 1993 BSD

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

