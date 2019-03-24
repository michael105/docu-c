--------------

GETRPCPORT(3) BSD Library Functions Manual GETRPCPORT(3)

**NAME**

**getrpcport** — get RPC port number

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

*int*

**getrpcport**\ (*char *host*, *int prognum*, *int versnum*,
*int proto*);

**DESCRIPTION**

The **getrpcport**\ () function returns the port number for version
*versnum* of the RPC program *prognum* running on *host* and using
protocol *proto*. It returns 0 if it cannot contact the portmapper, or
if *prognum* is not registered. If *prognum* is registered but not with
version *versnum*, it will still return a port number (for some version
of the program) indicating that the program is indeed registered. The
version mismatch will be detected upon the first call to the service.

BSD October 6, 1987 BSD

--------------
