--------------

ACCT(2) BSD System Calls Manual ACCT(2)

**NAME**

**acct** — enable or disable process accounting

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**acct**\ (*const char *file*);

**DESCRIPTION**

The **acct**\ () system call enables or disables the collection of
system accounting records. If the argument *file* is a null pointer,
accounting is disabled. If *file* is an *existing* pathname
(null-terminated), record collection is enabled and for every process
initiated which terminates under normal conditions an accounting record
is appended to *file*. Abnormal conditions of termination are reboots or
other fatal system problems. Records for processes which never terminate
cannot be produced by **acct**\ ().

For more information on the record structure used by **acct**\ (), see
<*sys/acct.h*> and acct(5).

This call is permitted only to the super-user.

**NOTES**

Accounting is automatically disabled when the file system the accounting
file resides on runs out of space; it is enabled when space once again
becomes available. The values controlling this behaviour can be modified
using the following sysctl(8) variables:

*kern.acct_chkfreq*

Specifies the frequency (in seconds) with which free disk space should
be checked.

*kern.acct_resume*

The percentage of free disk space above which process accounting will
resume.

*kern.acct_suspend*

The percentage of free disk space below which process accounting will
suspend.

**RETURN VALUES**

On error -1 is returned. The file must exist and the call may be
exercised only by the super-user.

**ERRORS**

The **acct**\ () system call will fail if one of the following is true:

[EPERM]

The caller is not the super-user.

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named file does not exist.

[EACCES]

Search permission is denied for a component of the path prefix, or the
path name is not a regular file.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EROFS]

The named file resides on a read-only file system.

[EFAULT]

The *file* argument points outside the process’s allocated address
space.

[EIO]

An I/O error occurred while reading from or writing to the file system.

**SEE ALSO**

acct(5), accton(8), sa(8)

**HISTORY**

The **acct**\ () function appeared in Version 7 AT&T UNIX.

BSD April 17, 2004 BSD

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

