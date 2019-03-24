--------------

ACL_GET_BRAND_NP(3) BSD Library Functions Manual ACL_GET_BRAND_NP(3)

**NAME**

**acl_get_brand_np** — retrieve the ACL brand from an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_brand_np**\ (*acl_t acl*, *int *brand_p*);

**DESCRIPTION**

The **acl_get_brand_np**\ () function is a non-portable call that
returns the ACL brand for the ACL *acl*. Upon successful completion, the
location referred to by the argument *brand_p* will be set to the ACL
brand of the ACL *acl*.

Branding is an internal mechanism intended to prevent mixing POSIX.1e
and NFSv4 entries by mistake. It’s also used by the libc to determine
how to print out the ACL. The first call to function that is specific
for one particular brand - POSIX.1e or NFSv4 - "brands" the ACL. After
that, calling function specific to another brand will result in error.

**RETURN VALUES**

The **acl_get_brand_np**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_get_brand_np**\ () function fails if:

[EINVAL]

Argument *acl* does not point to a valid ACL.

**SEE ALSO**

acl(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_brand_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_get_brand_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD June 25, 2009 BSD

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

