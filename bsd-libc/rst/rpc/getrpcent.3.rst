--------------

GETRPCENT(3) BSD Library Functions Manual GETRPCENT(3)

**NAME**

**getrpcent**, **getrpcbyname**, **getrpcbynumber**, **endrpcent**,
**setrpcent** — get RPC entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/rpc.h>**

*struct rpcent \**

**getrpcent**\ (*void*);

*struct rpcent \**

**getrpcbyname**\ (*const char *name*);

*struct rpcent \**

**getrpcbynumber**\ (*int number*);

*void*

**setrpcent**\ (*int stayopen*);

*void*

**endrpcent**\ (*void*);

**DESCRIPTION**

The **getrpcent**\ (), **getrpcbyname**\ (), and **getrpcbynumber**\ ()
functions each return a pointer to an object with the following
structure containing the broken-out fields of a line in the rpc program
number data base, */etc/rpc*:

struct rpcent {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*r_name; |           | /\* name  |           |
|           |           |           |           | of server |           |
|           |           |           |           | for this  |           |
|           |           |           |           | rpc       |           |
|           |           |           |           | program   |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \**r_alia |           | /\* alias |           |
|           |           | ses;      |           | list \*/  |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | long      | r_number; |           | /\* rpc   |           |
|           |           |           |           | program   |           |
|           |           |           |           | number    |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

The members of this structure are:

*r_name*

The name of the server for this rpc program.

*r_aliases*

A zero terminated list of alternate names for the rpc program.

*r_number*

The rpc program number for this service.

The **getrpcent**\ () function reads the next line of the file, opening
the file if necessary.

The **setrpcent**\ () function opens and rewinds the file. If the
*stayopen* flag is non-zero, the net data base will not be closed after
each call to **getrpcent**\ () (either directly, or indirectly through
one of the other ‘‘getrpc’’ calls).

The **endrpcent**\ () function closes the file.

The **getrpcbyname**\ () and **getrpcbynumber**\ () functions
sequentially search from the beginning of the file until a matching rpc
program name or program number is found, or until end-of-file is
encountered.

| **FILES**
| /etc/rpc **
  DIAGNOSTICS**

A NULL pointer is returned on EOF or error.

**SEE ALSO**

rpc(5), rpcinfo(8), ypserv(8)

**BUGS**

All information is contained in a static area so it must be copied if it
is to be saved.

BSD February 26, 2016 BSD

--------------
