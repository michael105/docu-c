--------------

EXTATTR(3) BSD Library Functions Manual EXTATTR(3)

**NAME**

**extattr_namespace_to_string**, **extattr_string_to_namespace** —
convert an extended attribute namespace identifier to a string and vice
versa

**LIBRARY**

System Utilities Library (libutil, −lutil)

**SYNOPSIS**

**#include <sys/extattr.h>
#include <libutil.h>**

*int*

**extattr_namespace_to_string**\ (*int attrnamespace*, *char **string*);

*int*

**extattr_string_to_namespace**\ (*const char *string*,
*int *attrnamespace*);

**DESCRIPTION**

The **extattr_namespace_to_string**\ () function converts a VFS extended
attribute identifier to a human-readable string; the
**extattr_string_to_namespace**\ () function undoes the aforementioned
operation, and converts a human-readable string representing a namespace
to a namespace identifier. Although a file system may implement
arbitrary namespaces, these functions only support the
EXTATTR_NAMESPACE_USER (‘‘user’’) and EXTATTR_NAMESPACE_SYSTEM
(‘‘system’’) namespaces, which are defined in extattr(9).

These functions are meant to be used in error reporting and other
interactive tasks. For example, instead of printing the integer
identifying an extended attribute in an error message, a program might
use **extattr_namespace_to_string**\ () to obtain a human-readable
representation. Likewise, instead of requiring a user to enter the
integer representing a namespace, an interactive program might ask for a
name and use **extattr_string_to_namespace**\ () to get the desired
identifier.

**RETURN VALUES**

If any of the calls are unsuccessful, the value −1 is returned and the
global variable *errno* is set to indicate the error.

| **ERRORS**
| [EINVAL]

The requested namespace could not be identified.

**SEE ALSO**

extattr(2), getextattr(8), setextattr(8), extattr(9)

**HISTORY**

Extended attribute support was developed as part of the TrustedBSD
Project, and introduced in FreeBSD 5.0. It was developed to support
security extensions requiring additional labels to be associated with
each file or directory.

BSD June 24, 2001 BSD

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

