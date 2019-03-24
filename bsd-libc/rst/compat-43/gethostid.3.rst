--------------

GETHOSTID(3) BSD Library Functions Manual GETHOSTID(3)

**NAME**

**gethostid**, **sethostid** — get/set unique identifier of current host

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*long*

**gethostid**\ (*void*);

*void*

**sethostid**\ (*long hostid*);

**DESCRIPTION**

The **sethostid**\ () function establishes a 32-bit identifier for the
current processor that is intended to be unique among all UNIX systems
in existence. This is normally a DARPA Internet address for the local
machine. This call is allowed only to the super-user and is normally
performed at boot time.

The **gethostid**\ () function returns the 32-bit identifier for the
current processor.

This function has been deprecated. The hostid should be set or retrieved
by use of sysctl(3).

**SEE ALSO**

gethostname(3), sysctl(3), sysctl(8)

**HISTORY**

The **gethostid**\ () and **sethostid**\ () syscalls appeared in 4.2BSD
and were dropped in 4.4BSD.

**BUGS**

32 bits for the identifier is too small.

BSD June 2, 1993 BSD

--------------
