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
