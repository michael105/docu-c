--------------

GETDOMAINNAME(3) BSD Library Functions Manual GETDOMAINNAME(3)

**NAME**

**getdomainname**, **setdomainname** — get/set the NIS domain name of
current host

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getdomainname**\ (*char *name*, *int namelen*);

*int*

**setdomainname**\ (*const char *name*, *int namelen*);

**DESCRIPTION**

The **getdomainname**\ () function returns the standard NIS domain name
for the current host, as previously set by **setdomainname**\ (). The
*namelen* argument specifies the size of the *name* array. The returned
name is null-terminated unless insufficient space is provided.

The **setdomainname**\ () function sets the NIS domain name of the host
machine to be *name*, which has length *namelen*. This call is
restricted to the super-user and is normally used only when the system
is bootstrapped.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following errors may be returned by these calls:

[EFAULT]

The *name* or *namelen* argument gave an invalid address.

[EPERM]

The caller tried to set the hostname and was not the super-user.

**SEE ALSO**

gethostid(3), gethostname(3), sysctl(3)

**HISTORY**

The **getdomainname**\ () function appeared in 4.2BSD.

**BUGS**

Domain names are limited to MAXHOSTNAMELEN (from <*sys/param.h*>)
characters, currently 256.

BSD May 6, 1994 BSD

--------------
