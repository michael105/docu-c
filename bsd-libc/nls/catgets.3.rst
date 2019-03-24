--------------

CATGETS(3) BSD Library Functions Manual CATGETS(3)

**NAME**

**catgets** — retrieve string from message catalog

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nl_types.h>**

*char \**

**catgets**\ (*nl_catd catd*, *int set_id*, *int msg_id*,
*const char *s*);

**DESCRIPTION**

The **catgets**\ () function attempts to retrieve message *msg_id* of
set *set_id* from the message catalog referenced by the descriptor
*catd*. The argument *s* points to a default message which is returned
if the function is unable to retrieve the specified message.

**RETURN VALUES**

If the specified message was retrieved successfully, **catgets**\ ()
returns a pointer to an internal buffer containing the message string;
otherwise it returns *s*.

| **ERRORS**
| [EBADF]

The *catd* argument is not a valid message catalog descriptor.

[EBADMSG]

The message identified by *set_id* and *msg_id* is not in the message
catalog.

**SEE ALSO**

gencat(1), catclose(3), catopen(3)

**STANDARDS**

The **catgets**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD February 12, 2005 BSD

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

