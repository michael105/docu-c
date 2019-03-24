--------------

RPC_SVC_ERR(3) BSD Library Functions Manual RPC_SVC_ERR(3)

**NAME**

**rpc_svc_err**, **svcerr_auth**, **svcerr_decode**, **svcerr_noproc**,
**svcerr_noprog**, **svcerr_progvers**, **svcerr_systemerr**,
**svcerr_weakauth** — library routines for server side remote procedure
call errors

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/rpc.h>**

*void*

**svcerr_auth**\ (*SVCXPRT *xprt*, *enum auth_stat why*);

*void*

**svcerr_decode**\ (*SVCXPRT *xprt*);

*void*

**svcerr_noproc**\ (*SVCXPRT *xprt*);

*void*

**svcerr_noprog**\ (*SVCXPRT *xprt*);

*void*

**svcerr_progvers**\ (*SVCXPRT *xprt*, *rpcvers_t low_vers*,
*rpcvers_t high_vers*);

*void*

**svcerr_systemerr**\ (*SVCXPRT *xprt*);

*void*

**svcerr_weakauth**\ (*SVCXPRT *xprt*);

**DESCRIPTION**

These routines are part of the RPC library which allows C language
programs to make procedure calls on other machines across the network.

These routines can be called by the server side dispatch function if
there is any error in the transaction with the client.

**Routines**

See rpc(3) for the definition of the *SVCXPRT* data structure.

**svcerr_auth**\ ()

Called by a service dispatch routine that refuses to perform a remote
procedure call due to an authentication error.

**svcerr_decode**\ ()

Called by a service dispatch routine that cannot successfully decode the
remote arguments (see **svc_getargs**\ () in rpc_svc_reg(3)).

**svcerr_noproc**\ ()

Called by a service dispatch routine that does not implement the
procedure number that the caller requests.

**svcerr_noprog**\ ()

Called when the desired program is not registered with the RPC package.
Service implementors usually do not need this routine.

**svcerr_progvers**\ ()

Called when the desired version of a program is not registered with the
RPC package. The *low_vers* argument is the lowest version number, and
*high_vers* is the highest version number. Service implementors usually
do not need this routine.

**svcerr_systemerr**\ ()

Called by a service dispatch routine when it detects a system error not
covered by any particular protocol. For example, if a service can no
longer allocate storage, it may call this routine.

**svcerr_weakauth**\ ()

Called by a service dispatch routine that refuses to perform a remote
procedure call due to insufficient (but correct) authentication
arguments. The routine calls **svcerr_auth**\ (*xprt*, *AUTH_TOOWEAK*).

**SEE ALSO**

rpc(3), rpc_svc_calls(3), rpc_svc_create(3), rpc_svc_reg(3)

BSD May 3, 1993 BSD

--------------
