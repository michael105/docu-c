--------------

GETNETGRENT(3) BSD Library Functions Manual GETNETGRENT(3)

**NAME**

**getnetgrent**, **innetgr**, **setnetgrent**, **endnetgrent** —
netgroup database operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <netdb.h>**

*int*

**getnetgrent**\ (*char **host*, *char **user*, *char **domain*);

*int*

**getnetgrent_r**\ (*char **host*, *char **user*, *char **domain*,
*char *buf*, *size_t bufsize*);

*int*

**innetgr**\ (*const char *netgroup*, *const char *host*,
*const char *user*, *const char *domain*);

*void*

**setnetgrent**\ (*const char *netgroup*);

*void*

**endnetgrent**\ (*void*);

**DESCRIPTION**

These functions operate on the netgroup database file */etc/netgroup*
which is described in netgroup(5). The database defines a set of
netgroups, each made up of one or more triples:

(host, user, domain)

that defines a combination of host, user and domain. Any of the three
fields may be specified as ‘‘wildcards’’ that match any string.

The function **getnetgrent**\ () sets the three pointer arguments to the
strings of the next member of the current netgroup. If any of the string
pointers are NULL that field is considered a wildcard.

The functions **setnetgrent**\ () and **endnetgrent**\ () set the
current netgroup and terminate the current netgroup respectively. If
**setnetgrent**\ () is called with a different netgroup than the
previous call, an implicit **endnetgrent**\ () is implied. The
**setnetgrent**\ () function also sets the offset to the first member of
the netgroup.

The function **innetgr**\ () searches for a match of all fields within
the specified group. If any of the **host**, **user**, or **domain**
arguments are NULL those fields will match any string value in the
netgroup member.

**RETURN VALUES**

The function **getnetgrent**\ () returns 0 for ‘‘no more netgroup
members’’ and 1 otherwise. The function **innetgr**\ () returns 1 for a
successful match and 0 otherwise. The functions **setnetgrent**\ () and
**endnetgrent**\ () have no return value.

| **FILES**
| /etc/netgroup

netgroup database file

**COMPATIBILITY**

The netgroup members have three string fields to maintain compatibility
with other vendor implementations, however it is not obvious what use
the **domain** string has within BSD.

**SEE ALSO**

netgroup(5)

**BUGS**

The function **getnetgrent**\ () returns pointers to dynamically
allocated data areas that are freed when the function
**endnetgrent**\ () is called.

BSD June 5, 2016 BSD

--------------
