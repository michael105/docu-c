--------------

FHLINK(2) BSD System Calls Manual FHLINK(2)

**NAME**

**fhlink**, **fhlinkat** — make a hard file link

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**fhlink**\ (*fhandle_t *fhp*, *const char *to*);

*int*

**fhlinkat**\ (*fhandle_t *fhp*, *int tofd*, *const char *to*);

**DESCRIPTION**

The **fhlink**\ () system call atomically creates the specified
directory entry (hard link) *to* with the attributes of the underlying
object pointed at by *fhp*. If the link is successful: the link count of
the underlying object is incremented; *fhp* and *to* share equal access
and rights to the underlying object.

If *fhp* is removed, the file *to* is not deleted and the link count of
the underlying object is decremented.

The object pointed at by the *fhp* argument must exist for the hard link
to succeed and both *fhp* and *to* must be in the same file system. The
*fhp* argument may not be a directory.

The **fhlinkat**\ () system call is equivalent to *fhlink* except in the
case where *to* is a relative paths. In this case a relative path *to*
is interpreted relative to the directory associated with the file
descriptor *tofd* instead of the current working directory.

Values for *flag* are constructed by a bitwise-inclusive OR of flags
from the following list, defined in <*fcntl.h*>:

AT_SYMLINK_FOLLOW

If *fhp* names a symbolic link, a new link for the target of the
symbolic link is created.

AT_BENEATH

Only allow to link to a file which is beneath of the topping directory.
See the description of the O_BENEATH flag in the open(2) manual page.

If **fhlinkat**\ () is passed the special value AT_FDCWD in the *tofd*
parameter, the current working directory is used for the *to* argument.
If *tofd* has value AT_FDCWD, the behavior is identical to a call to
**link**\ (). Unless *flag* contains the AT_SYMLINK_FOLLOW flag, if
*fhp* names a symbolic link, a new link is created for the symbolic link
*fhp* and not its target.

**RETURN VALUES**

The **link**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **fhlink**\ () system call will fail and no link will be created if:

[ENOTDIR]

A component of *to* prefix is not a directory.

[ENAMETOOLONG]

A component of *to* exceeded 255 characters, or entire length of *to*
name exceeded 1023 characters.

[ENOENT]

A component of *to* prefix does not exist.

[EOPNOTSUPP]

The file system containing the file pointed at by *fhp* does not support
links.

[EMLINK]

The link count of the file pointed at by *fhp* would exceed 32767.

[EACCES]

A component of *to* prefix denies search permission.

[EACCES]

The requested link requires writing in a directory with a mode that
denies write permission.

[ELOOP]

Too many symbolic links were encountered in translating one of the
pathnames.

[ENOENT]

The file pointed at by *fhp* does not exist.

[EEXIST]

The link named by *to* does exist.

[EPERM]

The file pointed at by *fhp* is a directory.

[EPERM]

The file pointed at by *fhp* has its immutable or append-only flag set,
see the chflags(2) manual page for more information.

[EPERM]

The parent directory of the file named by *to* has its immutable flag
set.

[EXDEV]

The link named by *to* and the file pointed at by *fhp* are on different
file systems.

[ENOSPC]

The directory in which the entry for the new link is being placed cannot
be extended because there is no space left on the file system containing
the directory.

[EDQUOT]

The directory in which the entry for the new link is being placed cannot
be extended because the user’s quota of disk blocks on the file system
containing the directory has been exhausted.

[EIO]

An I/O error occurred while reading from or writing to the file system
to make the directory entry.

[EROFS]

The requested link requires writing in a directory on a read-only file
system.

[EFAULT]

One of the pathnames specified is outside the process’s allocated
address space.

[ESTALE]

The file handle *fhp* is no longer valid

In addition to the errors returned by the **fhlink**\ (), the
**fhlinkat**\ () system call may fail if:

[EBADF]

The *fhp* or *to* argument does not specify an absolute path and the
*tofd* argument, is not AT_FDCWD nor a valid file descriptor open for
searching.

[EINVAL]

The value of the *flag* argument is not valid.

[ENOTDIR]

The *fhp* or *to* argument is not an absolute path and *tofd* is not
AT_FDCWD nor a file descriptor associated with a directory.

**SEE ALSO**

fhstat(2), fhreadlink(2), fhopen(2),

BSD November 29, 2018 BSD

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

