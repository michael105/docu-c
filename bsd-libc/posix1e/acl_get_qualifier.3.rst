--------------

ACL_GET_QUALIFIER(3) BSD Library Functions Manual ACL_GET_QUALIFIER(3)

**NAME**

**acl_get_qualifier** — retrieve the qualifier from an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*void \**

**acl_get_qualifier**\ (*acl_entry_t entry_d*);

**DESCRIPTION**

The **acl_get_qualifier**\ () function is a POSIX.1e call that retrieves
the qualifier of the tag for the ACL entry indicated by the argument
*entry_d* into working storage and returns a pointer to that storage.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_USER, then the value returned by **acl_get_qualifier**\ () will
be a pointer to type *uid_t*.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_GROUP, then the value returned by **acl_get_qualifier**\ () will
be a pointer to type *gid_t*.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_UNDEFINED_TAG, ACL_USER_OBJ, ACL_GROUP_OBJ, ACL_OTHER, ACL_MASK,
or an implementation-defined value for which a qualifier is not
supported, then **acl_get_qualifier**\ () will return a value of (*void
\**)NULL and the function will fail.

This function may cause memory to be allocated. The caller should free
any releasable memory, when the new qualifier is no longer required, by
calling **acl_free**\ () with *void \** as the argument.

**RETURN VALUES**

The **acl_get_qualifier**\ () function returns a pointer to the
allocated storage if successful; otherwise a NULL pointer is returned
and the global variable *errno* is set to indicate the error.

**ERRORS**

The **acl_get_qualifier**\ () fails if:

[EINVAL]

Argument *entry_d* does not point to a valid descriptor for an ACL
entry. The value of the tag type in the ACL entry referenced by argument
*entry_d* is not ACL_USER or ACL_GROUP.

[ENOMEM]

The value to be returned requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_create_entry(3), acl_free(3), acl_get_entry(3),
acl_get_tag_type(3), acl_set_qualifier(3), acl_set_tag_type(3),
posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_qualifier**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_qualifier**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 13, 2001 BSD

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

