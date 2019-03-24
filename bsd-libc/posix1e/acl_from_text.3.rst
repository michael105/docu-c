--------------

ACL_FROM_TEXT(3) BSD Library Functions Manual ACL_FROM_TEXT(3)

**NAME**

**acl_from_text** — create an ACL from text

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*acl_t*

**acl_from_text**\ (*const char *buf_p*);

**DESCRIPTION**

The **acl_from_text**\ () function converts the text form of an ACL
referred to by *buf_p* into the internal working structure for ACLs,
appropriate for applying to files or manipulating.

This function may cause memory to be allocated. The caller should free
any releasable memory, when the new ACL is no longer required, by
calling acl_free(3) with the *(void \*)acl_t* as an argument.

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

Upon successful completion, the function shall return a pointer to the
internal representation of the ACL in working storage. Otherwise, a
value of *(acl_t)NULL* shall be returned, and *errno* shall be set to
indicate the error.

**ERRORS**

If any of the following conditions occur, the **acl_from_text**\ ()
function shall return a value of *(acl_t)NULL* and set *errno* to the
corresponding value:

[EINVAL]

Argument *buf_p* cannot be translated into an ACL.

[ENOMEM]

The ACL working storage requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_free(3), acl_get(3), acl_to_text(3), posix1e(3)

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

**BUGS**

The **acl_from_text**\ () and **acl_to_text**\ () functions rely on the
getpwent(3) library calls to manage username and uid mapping, as well as
the getgrent(3) library calls to manage groupname and gid mapping. These
calls are not thread safe, and so transitively, neither are
**acl_from_text**\ () and **acl_to_text**\ (). These functions may also
interfere with stateful calls associated with the **getpwent**\ () and
**getgrent**\ () calls.

BSD January 28, 2000 BSD

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

