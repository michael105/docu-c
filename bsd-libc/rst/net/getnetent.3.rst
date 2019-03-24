--------------

GETNETENT(3) BSD Library Functions Manual GETNETENT(3)

**NAME**

**getnetent**, **getnetbyaddr**, **getnetbyname**, **setnetent**,
**endnetent** — get network entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <netdb.h>**

*struct netent \**

**getnetent**\ (*void*);

*struct netent \**

**getnetbyname**\ (*const char *name*);

*struct netent \**

**getnetbyaddr**\ (*uint32_t net*, *int type*);

*void*

**setnetent**\ (*int stayopen*);

*void*

**endnetent**\ (*void*);

**DESCRIPTION**

The **getnetent**\ (), **getnetbyname**\ (), and **getnetbyaddr**\ ()
functions each return a pointer to an object with the following
structure describing an internet network. This structure contains either
the information obtained from the nameserver, named(8), broken-out
fields of a line in the network data base */etc/networks*, or entries
supplied by the yp(8) system. The order of the lookups is controlled by
the ‘networks’ entry in nsswitch.conf(5).

struct netent {

+---------+---------+---------+---------+---------+---------+---------+
|         | char    |         | \*n_nam |         | /\*     |         |
|         |         |         | e;      |         | officia |         |
|         |         |         |         |         | l       |         |
|         |         |         |         |         | name of |         |
|         |         |         |         |         | net \*/ |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | char    |         | \**n_al |         | /\*     |         |
|         |         |         | iases;  |         | alias   |         |
|         |         |         |         |         | list    |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | n_addrt |         | /\* net |         |
|         |         |         | ype;    |         | number  |         |
|         |         |         |         |         | type    |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         | n_net;  |         | /\* net |         |
|         | t       |         |         |         | number  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+

};

The members of this structure are:

*n_name*

The official name of the network.

*n_aliases*

A zero terminated list of alternate names for the network.

*n_addrtype*

The type of the network number returned; currently only AF_INET.

*n_net*

The network number. Network numbers are returned in machine byte order.

The **getnetent**\ () function reads the next line of the file, opening
the file if necessary.

The **setnetent**\ () function opens and rewinds the file. If the
*stayopen* flag is non-zero, the net data base will not be closed after
each call to **getnetbyname**\ () or **getnetbyaddr**\ ().

The **endnetent**\ () function closes the file.

The **getnetbyname**\ () function and **getnetbyaddr**\ () sequentially
search from the beginning of the file until a matching net name or net
address and type is found, or until EOF is encountered. The *type*
argument must be AF_INET. Network numbers are supplied in host order.

| **FILES**
| /etc/networks
| /etc/nsswitch.conf
| /etc/resolv.conf **
  DIAGNOSTICS**

Null pointer returned on EOF or error.

**SEE ALSO**

networks(5)

*RFC 1101*

**HISTORY**

The **getnetent**\ (), **getnetbyaddr**\ (), **getnetbyname**\ (),
**setnetent**\ (), and **endnetent**\ () functions appeared in 4.2BSD.

**BUGS**

The data space used by these functions is thread-specific; if future use
requires the data, it should be copied before any subsequent calls to
these functions overwrite it. Only Internet network numbers are
currently understood. Expecting network numbers to fit in no more than
32 bits is probably naive.

BSD June 4, 1993 BSD

--------------
