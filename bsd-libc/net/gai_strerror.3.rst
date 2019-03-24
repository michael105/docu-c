--------------

GAI_STRERROR(3) BSD Library Functions Manual GAI_STRERROR(3)

**NAME**

**gai_strerror** — get error message string from EAI_xxx error code

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>**

*const char \**

**gai_strerror**\ (*int ecode*);

**DESCRIPTION**

The **gai_strerror**\ () function returns an error message string
corresponding to the error code returned by getaddrinfo(3) or
getnameinfo(3).

The following error codes and their meaning are defined in <*netdb.h*>:

EAI_AGAIN

Name could not be resolved at this time

EAI_BADFLAGS

flags parameter had an invalid value

EAI_BADHINTS

invalid value for *hints*

EAI_FAIL

Non-recoverable failure in name resolution

EAI_FAMILY

Address family was not recognized

EAI_MEMORY

Memory allocation failure

EAI_NONAME

Name does not resolve

EAI_OVERFLOW

argument buffer overflow

EAI_PROTOCOL

Resolved protocol is unknown

EAI_SERVICE

Service was not recognized for socket type

EAI_SOCKTYPE

Intended socket type was not recognized

EAI_SYSTEM

System error returned in *errno*

**RETURN VALUES**

The **gai_strerror**\ () function returns a pointer to the error message
string corresponding to *ecode*. If *ecode* is out of range, an
implementation-specific error message string is returned.

**SEE ALSO**

getaddrinfo(3), getnameinfo(3)

| **STANDARDS**
| RFC 3493

Basic Socket Interface Extensions for IPv6

BSD December 23, 2018 BSD

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

