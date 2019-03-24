--------------

ACL_CALC_MASK(3) BSD Library Functions Manual ACL_CALC_MASK(3)

**NAME**

**acl_calc_mask** — calculate and set ACL mask permissions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_calc_mask**\ (*acl_t *acl_p*);

**DESCRIPTION**

The **acl_calc_mask**\ () function is a POSIX.1e call that calculates
and set the permissions associated with the ACL_MASK ACL entry of the
ACL referred to by *acl_p*.

The value of new permissions are the union of the permissions granted by
the ACL_GROUP, ACL_GROUP_OBJ, ACL_USER tag types which match processes
in the file group class contained in the ACL referred to by *acl_p*.

If the ACL referred to by *acl_p* already contains an ACL_MASK entry,
its permissions shall be overwritten; if it does not contain an ACL_MASK
entry, one shall be added.

**RETURN VALUES**

The **acl_calc_mask**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_calc_mask**\ () function fails if:

[EINVAL]

Argument *acl_p* does not point to a pointer to a valid ACL.

**SEE ALSO**

acl(3), acl_get_entry(3), acl_valid(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_calc_mask**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_calc_mask**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

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

