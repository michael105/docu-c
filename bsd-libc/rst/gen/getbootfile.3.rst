--------------

GETBOOTFILE(3) BSD Library Functions Manual GETBOOTFILE(3)

**NAME**

**getbootfile** — get kernel boot file name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <paths.h>**

*const char \**

**getbootfile**\ (*void*);

**DESCRIPTION**

The **getbootfile**\ () function retrieves the full pathname of the file
from which the current kernel was loaded, and returns a static pointer
to the name. A read/write interface to this information is available via
the sysctl(3) MIB variable ‘‘kern.bootfile’’.

**RETURN VALUES**

If the call succeeds a string giving the pathname is returned. If it
fails, a null pointer is returned and an error code is placed in the
global location *errno*.

**SEE ALSO**

sysctl(3)

**HISTORY**

The **getbootfile**\ () function appeared in FreeBSD 2.0.

**BUGS**

If the boot blocks have not been modified to pass this information into
the kernel at boot time, the static string ‘‘\ */boot/kernel/kernel*\ ’’
is returned instead of the real boot file.

BSD September 23, 1994 BSD

--------------
