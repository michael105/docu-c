--------------

RPC_XDR(3) BSD Library Functions Manual RPC_XDR(3)

**NAME**

**xdr_accepted_reply**, **xdr_authsys_parms**, **xdr_callhdr**,
**xdr_callmsg**, **xdr_opaque_auth**, **xdr_rejected_reply**,
**xdr_replymsg** — XDR library routines for remote procedure calls

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/rpc.h>**

*bool_t*

**xdr_accepted_reply**\ (*XDR *xdrs*, *struct accepted_reply *ar*);

*bool_t*

**xdr_authsys_parms**\ (*XDR *xdrs*, *struct authsys_parms *aupp*);

*bool_t*

**xdr_callhdr**\ (*XDR *xdrs*, *struct rpc_msg *chdr*);

*bool_t*

**xdr_callmsg**\ (*XDR *xdrs*, *struct rpc_msg *cmsg*);

*bool_t*

**xdr_opaque_auth**\ (*XDR *xdrs*, *struct opaque_auth *ap*);

*bool_t*

**xdr_rejected_reply**\ (*XDR *xdrs*, *struct rejected_reply *rr*);

*bool_t*

**xdr_replymsg**\ (*XDR *xdrs*, *struct rpc_msg *rmsg*);

**DESCRIPTION**

These routines are used for describing the RPC messages in XDR language.
They should normally be used by those who do not want to use the RPC
package directly. These routines return TRUE if they succeed, FALSE
otherwise.

**Routines**

See rpc(3) for the definition of the *XDR* data structure.

**xdr_accepted_reply**\ ()

Used to translate between RPC reply messages and their external
representation. It includes the status of the RPC call in the XDR
language format. In the case of success, it also includes the call
results.

**xdr_authsys_parms**\ ()

Used for describing UNIX operating system credentials. It includes
machine-name, uid, gid list, etc.

**xdr_callhdr**\ ()

Used for describing RPC call header messages. It encodes the static part
of the call message header in the XDR language format. It includes
information such as transaction ID, RPC version number, program and
version number.

**xdr_callmsg**\ ()

Used for describing RPC call messages. This includes all the RPC call
information such as transaction ID, RPC version number, program number,
version number, authentication information, etc. This is normally used
by servers to determine information about the client RPC call.

**xdr_opaque_auth**\ ()

Used for describing RPC opaque authentication information messages.

**xdr_rejected_reply**\ ()

Used for describing RPC reply messages. It encodes the rejected RPC
message in the XDR language format. The message could be rejected either
because of version number mis-match or because of authentication errors.

**xdr_replymsg**\ ()

Used for describing RPC reply messages. It translates between the RPC
reply message and its external representation. This reply could be
either an acceptance, rejection or NULL.

**SEE ALSO**

rpc(3), xdr(3)

BSD May 3, 1993 BSD

--------------
