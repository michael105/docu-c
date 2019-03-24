--------------

HESIOD(3) BSD Library Functions Manual HESIOD(3)

**NAME**

**hesiod**, **hesiod_init**, **hesiod_resolve**, **hesiod_free_list**,
**hesiod_to_bind**, **hesiod_end** — Hesiod name server interface
library

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <hesiod.h>**

*int*

**hesiod_init**\ (*void **context*);

*char \*\**

**hesiod_resolve**\ (*void *context*, *const char *name*,
*const char *type*);

*void*

**hesiod_free_list**\ (*void *context*, *char **list*);

*char \**

**hesiod_to_bind**\ (*void *context*, *const char *name*,
*const char *type*);

*void*

**hesiod_end**\ (*void *context*);

**DESCRIPTION**

This family of functions allows you to perform lookups of Hesiod
information, which is stored as text records in the Domain Name Service.
To perform lookups, you must first initialize a *context*, an opaque
object which stores information used internally by the library between
calls. The **hesiod_init**\ () function initializes a context, storing a
pointer to the context in the location pointed to by the *context*
argument. The **hesiod_end**\ () function frees the resources used by a
context.

The **hesiod_resolve**\ () function is the primary interface to the
library. If successful, it returns a list of one or more strings giving
the records matching *name* and *type*. The last element of the list is
followed by a NULL pointer. It is the caller’s responsibility to call
**hesiod_free_list**\ () to free the resources used by the returned
list.

The **hesiod_to_bind**\ () function converts *name* and *type* into the
DNS name used by **hesiod_resolve**\ (). It is the caller’s
responsibility to free the returned string using **free**\ ().

**RETURN VALUES**

The **hesiod_init**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error. On failure, **hesiod_resolve**\ () and
**hesiod_to_bind**\ () return NULL and set the global variable *errno*
to indicate the error.

| **ENVIRONMENT**
| HES_DOMAIN

If the environment variable HES_DOMAIN is set, it will override the
domain in the Hesiod configuration file.

HESIOD_CONFIG

If the environment variable HESIOD_CONFIG is set, it specifies the
location of the Hesiod configuration file.

**ERRORS**

Hesiod calls may fail because of:

[ENOMEM]

Insufficient memory was available to carry out the requested operation.

[ENOEXEC]

The **hesiod_init**\ () function failed because the Hesiod configuration
file was invalid.

[ECONNREFUSED]

The **hesiod_resolve**\ () function failed because no name server could
be contacted to answer the query.

[EMSGSIZE]

The **hesiod_resolve**\ () or **hesiod_to_bind**\ () function failed
because the query or response was too big to fit into the packet
buffers.

[ENOENT]

The **hesiod_resolve**\ () function failed because the name server had
no text records matching *name* and *type*, or **hesiod_to_bind**\ ()
failed because the *name* argument had a domain extension which could
not be resolved with type ‘‘rhs−extension’’ in the local Hesiod domain.

**SEE ALSO**

hesiod.conf(5), named(8)

*Hesiod - Project Athena Technical Plan -- Name Service*

.

**AUTHORS**

| Steve Dyer, IBM/Project Athena
| Greg Hudson, MIT Team Athena

Copyright 1987, 1988, 1995, 1996 by the Massachusetts Institute of
Technology.

**BUGS**

The strings corresponding to the *errno* values set by the Hesiod
functions are not particularly indicative of what went wrong, especially
for ENOEXEC and ENOENT.

BSD November 30, 1996 BSD

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

