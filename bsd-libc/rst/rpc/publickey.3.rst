--------------

PUBLICKEY(3) BSD Library Functions Manual PUBLICKEY(3)

**NAME**

**publickey**, **getpublickey**, **getsecretkey** — get public or secret
key

**LIBRARY**

RPC Service Library (librpcsvc, −lrpcsvc)

**SYNOPSIS**

**#include <rpc/rpc.h>
#include <rpc/key_prot.h>**

*int*

**getpublickey**\ (*const char netname[MAXNETNAMELEN+1]*,
*char publickey[HEXKEYBYTES+1]*);

*int*

**getsecretkey**\ (*char netname[MAXNETNAMELEN+1]*,
*char secretkey[HEXKEYBYTES+1]*, *char *passwd*);

**DESCRIPTION**

These routines are used to get public and secret keys from the YP
database. The **getsecretkey**\ () function has an extra argument,
*passwd*, which is used to decrypt the encrypted secret key stored in
the database. Both routines return 1 if they are successful in finding
the key, 0 otherwise. The keys are returned as NUL−terminated,
hexadecimal strings. If the password supplied to **getsecretkey**\ ()
fails to decrypt the secret key, the routine will return 1 but the
*secretkey* argument will be a NUL string (‘‘’’).

**SEE ALSO**

publickey(5)

*RPC Programmer’s Manual* in */usr/share/doc/psd/23.rpc*.

BSD October 6, 1987 BSD

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

