--------------

IF_NAMETOINDEX(3) BSD Library Functions Manual IF_NAMETOINDEX(3)

**NAME**

**if_nametoindex**, **if_indextoname**, **if_nameindex**,
**if_freenameindex** — provide mappings between interface names and
indexes

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>**

*unsigned int*

**if_nametoindex**\ (*const char *ifname*);

*char \**

**if_indextoname**\ (*unsigned int ifindex*, *char *ifname*);

*struct if_nameindex \**

**if_nameindex**\ (*void*);

*void*

**if_freenameindex**\ (*struct if_nameindex *ptr*);

**DESCRIPTION**

The **if_nametoindex**\ () function maps the interface name specified in
*ifname* to its corresponding index. If the specified interface does not
exist, it returns 0.

The **if_indextoname**\ () function maps the interface index specified
in *ifindex* to it corresponding name, which is copied into the buffer
pointed to by *ifname*, which must be of at least IFNAMSIZ bytes. This
pointer is also the return value of the function. If there is no
interface corresponding to the specified index, NULL is returned.

The **if_nameindex**\ () function returns an array of *if_nameindex*
structures, one structure per interface, as defined in the include file
<*net/if.h*>. The *if_nameindex* structure contains at least the
following entries:

| unsigned int if_index; /\* 1, 2, ... \*/
| char \*if_name; /\* null terminated name: "le0", ... \*/

The end of the array of structures is indicated by a structure with an
*if_index* of 0 and an *if_name* of NULL. A NULL pointer is returned
upon an error.

The **if_freenameindex**\ () function frees the dynamic memory that was
allocated by **if_nameindex**\ ().

**RETURN VALUES**

Upon successful completion, **if_nametoindex**\ () returns the index
number of the interface. If the interface is not found, a value of 0 is
returned and *errno* is set to ENXIO. A value of 0 is also returned if
an error occurs while retrieving the list of interfaces via
getifaddrs(3).

Upon successful completion, **if_indextoname**\ () returns *ifname*. If
the interface is not found, a NULL pointer is returned and *errno* is
set to ENXIO. A NULL pointer is also returned if an error occurs while
retrieving the list of interfaces via getifaddrs(3).

The **if_nameindex**\ () returns a NULL pointer if an error occurs while
retrieving the list of interfaces via getifaddrs(3), or if sufficient
memory cannot be allocated.

**SEE ALSO**

getifaddrs(3), networking(4)

**STANDARDS**

The **if_nametoindex**\ (), **if_indextoname**\ (),
**if_nameindex**\ (), and **if_freenameindex**\ () functions conform to
*RFC 2553*.

**HISTORY**

The implementation first appeared in BSDi BSD/OS.

BSD November 23, 2005 BSD

--------------
