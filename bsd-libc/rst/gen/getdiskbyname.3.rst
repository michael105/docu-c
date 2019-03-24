--------------

GETDISKBYNAME(3) BSD Library Functions Manual GETDISKBYNAME(3)

**NAME**

**getdiskbyname** — get generic disk description by its name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/disklabel.h>**

*struct disklabel \**

**getdiskbyname**\ (*const char *name*);

**DESCRIPTION**

The **getdiskbyname**\ () function takes a disk name (e.g. ‘rm03’) and
returns a prototype disk label describing its geometry information and
the standard disk partition tables. All information is obtained from the
disktab(5) file.

**SEE ALSO**

disktab(5), disklabel(8)

**HISTORY**

The **getdiskbyname**\ () function appeared in 4.3BSD.

BSD June 4, 1993 BSD

--------------
