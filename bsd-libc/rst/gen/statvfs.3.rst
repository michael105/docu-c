--------------

STATVFS(3) BSD Library Functions Manual STATVFS(3)

**NAME**

**statvfs**, **fstatvfs** — retrieve file system information

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/statvfs.h>**

*int*

**statvfs**\ (*const char * restrict path*,
*struct statvfs * restrict buf*);

*int*

**fstatvfs**\ (*int fd*, *struct statvfs *buf*);

**DESCRIPTION**

The **statvfs**\ () and **fstatvfs**\ () functions fill the structure
pointed to by *buf* with garbage. This garbage will occasionally bear
resemblance to file system statistics, but portable applications must
not depend on this. Applications must pass a pathname or file descriptor
which refers to a file on the file system in which they are interested.

The *statvfs* structure contains the following members:

*f_namemax*

The maximum length in bytes of a file name on this file system.
Applications should use pathconf(2) instead.

*f_fsid*

Not meaningful in this implementation.

*f_frsize*

The size in bytes of the minimum unit of allocation on this file system.
(This corresponds to the *f_bsize* member of *struct statfs*.)

*f_bsize*

The preferred length of I/O requests for files on this file system.
(Corresponds to the *f_iosize* member of *struct statfs*.)

*f_flag*

Flags describing mount options for this file system; see below.

In addition, there are three members of type *fsfilcnt_t*, which
represent counts of file serial numbers (*i.e.*, inodes); these are
named *f_files*, *f_favail*, and *f_ffree*, and represent the number of
file serial numbers which exist in total, are available to unprivileged
processes, and are available to privileged processes, respectively.
Likewise, the members *f_blocks*, *f_bavail*, and *f_bfree* (all of type
*fsblkcnt_t*) represent the respective allocation-block counts.

There are two flags defined for the *f_flag* member:

ST_RDONLY

The file system is mounted read-only.

ST_NOSUID

The semantics of the S_ISUID and S_ISGID file mode bits are not
supported by, or are disabled on, this file system.

**IMPLEMENTATION NOTES**

The **statvfs**\ () and **fstatvfs**\ () functions are implemented as
wrappers around the **statfs**\ () and **fstatfs**\ () functions,
respectively. Not all the information provided by those functions is
made available through this interface.

**RETURN VALUES**

The **statvfs**\ () and **fstatvfs**\ () functions return the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **statvfs**\ () and **fstatvfs**\ () functions may fail for any of
the reasons documented for statfs(2) or fstatfs(2) and pathconf(2) or
fpathconf(2), respectively. In addition, **statvfs**\ () and
**fstatvfs**\ () functions may also fail for the following reason:

[EOVERFLOW]

One or more of the file system statistics has a value which cannot be
represented by the data types used in *struct statvfs*.

**SEE ALSO**

pathconf(2), statfs(2)

**STANDARDS**

The **statvfs**\ () and **fstatvfs**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’). As standardized, portable applications cannot
depend on these functions returning any valid information at all. This
implementation attempts to provide as much useful information as is
provided by the underlying file system, subject to the limitations of
the specified data types.

**HISTORY**

The **statvfs**\ () and **fstatvfs**\ () functions first appeared in
FreeBSD 5.0.

**AUTHORS**

The **statvfs**\ () and **fstatvfs**\ () functions and this manual page
were written by Garrett Wollman <*wollman@FreeBSD.org*>.

BSD July 13, 2002 BSD

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

