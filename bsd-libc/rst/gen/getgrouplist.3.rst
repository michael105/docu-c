--------------

GETGROUPLIST(3) BSD Library Functions Manual GETGROUPLIST(3)

**NAME**

**getgrouplist** — calculate group access list

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getgrouplist**\ (*const char *name*, *gid_t basegid*, *gid_t *groups*,
*int *ngroups*);

**DESCRIPTION**

The **getgrouplist**\ () function reads through the group file and
calculates the group access list for the user specified in *name*. The
*basegid* is automatically included in the groups list. Typically this
value is given as the group number from the password file.

The resulting group list is returned in the array pointed to by
*groups*. The caller specifies the size of the *groups* array in the
integer pointed to by *ngroups*; the actual number of groups found is
returned in *ngroups*.

**RETURN VALUES**

The **getgrouplist**\ () function returns 0 on success and −1 if the
size of the group list is too small to hold all the user’s groups. Here,
the group array will be filled with as many groups as will fit.

| **FILES**
| /etc/group

group membership list

**SEE ALSO**

setgroups(2), initgroups(3)

**HISTORY**

The **getgrouplist**\ () function first appeared in 4.4BSD.

BSD October 26, 2014 BSD

--------------
