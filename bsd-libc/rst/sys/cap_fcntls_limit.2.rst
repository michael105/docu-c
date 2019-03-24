--------------

CAP_FCNTLS_LIMIT(2) BSD System Calls Manual CAP_FCNTLS_LIMIT(2)

**NAME**

**cap_fcntls_limit**, **cap_fcntls_get** — manage allowed fcntl commands

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>**

*int*

**cap_fcntls_limit**\ (*int fd*, *uint32_t fcntlrights*);

*int*

**cap_fcntls_get**\ (*int fd*, *uint32_t *fcntlrightsp*);

**DESCRIPTION**

If a file descriptor is granted the CAP_FCNTL capability right, the list
of allowed fcntl(2) commands can be selectively reduced (but never
expanded) with the **cap_fcntls_limit**\ () system call.

A bitmask of allowed fcntls commands for a given file descriptor can be
obtained with the **cap_fcntls_get**\ () system call.

**FLAGS**

The following flags may be specified in the *fcntlrights* argument or
returned in the *fcntlrightsp* argument:

CAP_FCNTL_GETFL

Permit F_GETFL command.

CAP_FCNTL_SETFL

Permit F_SETFL command.

CAP_FCNTL_GETOWN

Permit F_GETOWN command.

CAP_FCNTL_SETOWN

Permit F_SETOWN command.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

**cap_fcntls_limit**\ () succeeds unless:

[EBADF]

The *fd* argument is not a valid descriptor.

[EINVAL]

An invalid flag has been passed in *fcntlrights*.

[ENOTCAPABLE]

*fcntlrights* would expand the list of allowed fcntl(2) commands.

**cap_fcntls_get**\ () succeeds unless:

[EBADF]

The *fd* argument is not a valid descriptor.

[EFAULT]

The *fcntlrightsp* argument points at an invalid address.

**SEE ALSO**

cap_ioctls_limit(2), cap_rights_limit(2), fcntl(2)

**HISTORY**

Support for capabilities and capabilities mode was developed as part of
the TrustedBSD Project.

**AUTHORS**

This function was created by Pawel Jakub Dawidek <*pawel@dawidek.net*>
under sponsorship of the FreeBSD Foundation.

BSD March 27, 2014 BSD

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

