--------------

RPC_CLNT_AUTH(3) BSD Library Functions Manual RPC_CLNT_AUTH(3)

**NAME**

**auth_destroy**, **authnone_create**, **authsys_create**,
**authsys_create_default** — library routines for client side remote
procedure call authentication

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/rpc.h>**

*void*

**auth_destroy**\ (*AUTH *auth*);

*AUTH \**

**authnone_create**\ (*void*);

*AUTH \**

**authsys_create**\ (*const char *host*, *const uid_t uid*,
*const gid_t gid*, *const int len*, *const gid_t *aup_gids*);

*AUTH \**

**authsys_create_default**\ (*void*);

**DESCRIPTION**

These routines are part of the RPC library that allows C language
programs to make procedure calls on other machines across the network,
with desired authentication.

These routines are normally called after creating the *CLIENT* handle.
The *cl_auth* field of the *CLIENT* structure should be initialized by
the *AUTH* structure returned by some of the following routines. The
client’s authentication information is passed to the server when the RPC
call is made.

Only the NULL and the SYS style of authentication is discussed here.

**Routines
auth_destroy**\ ()

A function macro that destroys the authentication information associated
with *auth*. Destruction usually involves deallocation of private data
structures. The use of *auth* is undefined after calling
**auth_destroy**\ ().

**authnone_create**\ ()

Create and return an RPC authentication handle that passes nonusable
authentication information with each remote procedure call. This is the
default authentication used by RPC.

**authsys_create**\ ()

Create and return an RPC authentication handle that contains AUTH_SYS
authentication information. The *host* argument is the name of the
machine on which the information was created; *uid* is the user’s user
ID; *gid* is the user’s current group ID; *len* and *aup_gids* refer to
a counted array of groups to which the user belongs.

**authsys_create_default**\ ()

Call **authsys_create**\ () with the appropriate arguments.

**SEE ALSO**

rpc(3), rpc_clnt_calls(3), rpc_clnt_create(3)

BSD May 7, 1993 BSD

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

