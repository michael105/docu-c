--------------

ACL_DELETE(3) BSD Library Functions Manual ACL_DELETE(3)

**NAME**

**acl_delete_def_file**, **acl_delete_def_link_np**,
**acl_delete_fd_np**, **acl_delete_file_np**, **acl_delete_link_np** —
delete an ACL from a file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_delete_def_file**\ (*const char *path_p*);

*int*

**acl_delete_def_link_np**\ (*const char *path_p*);

*int*

**acl_delete_fd_np**\ (*int filedes*, *acl_type_t type*);

*int*

**acl_delete_file_np**\ (*const char *path_p*, *acl_type_t type*);

*int*

**acl_delete_link_np**\ (*const char *path_p*, *acl_type_t type*);

**DESCRIPTION**

The **acl_delete_def_file**\ (), **acl_delete_def_link_np**\ (),
**acl_delete_fd_np**\ (), **acl_delete_file_np**\ (), and
**acl_delete_link_np**\ () each allow the deletion of an ACL from a
file. The **acl_delete_def_file**\ () function is a POSIX.1e call that
deletes the default ACL from a file (normally a directory) by name; the
remainder of the calls are non-portable extensions that permit the
deletion of arbitrary ACL types from a file/directory either by path
name or file descriptor. The **\_file**\ () variations follow a symlink
if it occurs in the last segment of the path name; the **\_link**\ ()
variations operate on the symlink itself.

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

If any of the following conditions occur, these functions shall return
-1 and set *errno* to the corresponding value:

[EACCES]

Search permission is denied for a component of the path prefix, or the
object exists and the process does not have appropriate access rights.

[EBADF]

The *fd* argument is not a valid file descriptor.

[EINVAL]

The ACL type passed is invalid for this file object.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named object does not exist, or the *path_p* argument points to an
empty string.

[ENOMEM]

Insufficient memory available to fulfill request.

[ENOTDIR]

A component of the path prefix is not a directory.

Argument *path_p* must be a directory, and is not.

[EOPNOTSUPP]

The file system does not support ACL deletion.

[EPERM]

The process does not have appropriate privilege to perform the operation
to delete an ACL.

[EROFS]

The file system is read-only.

**SEE ALSO**

acl(3), acl_get(3), acl_set(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0, and development
continues.

**AUTHORS**

Robert N M Watson

BSD December 29, 2002 BSD

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

