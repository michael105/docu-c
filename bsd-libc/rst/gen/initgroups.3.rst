--------------

INITGROUPS(3) BSD Library Functions Manual INITGROUPS(3)

**NAME**

**initgroups** — initialize group access list

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**initgroups**\ (*const char *name*, *gid_t basegid*);

**DESCRIPTION**

The **initgroups**\ () function uses the getgrouplist(3) function to
calculate the group access list for the user specified in *name*. This
group list is then setup for the current process using setgroups(2). The
*basegid* is automatically included in the groups list. Typically this
value is given as the group number from the password file.

**RETURN VALUES**

The **initgroups**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **initgroups**\ () function may fail and set *errno* for any of the
errors specified for the library function setgroups(2). It may also
return:

[ENOMEM]

The **initgroups**\ () function was unable to allocate temporary
storage.

**SEE ALSO**

setgroups(2), getgrouplist(3)

**HISTORY**

The **initgroups**\ () function appeared in 4.2BSD.

BSD October 26, 2014 BSD

--------------
