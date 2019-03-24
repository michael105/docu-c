--------------

GETPROGNAME(3) BSD Library Functions Manual GETPROGNAME(3)

**NAME**

**getprogname**, **setprogname** — get or set the program name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*const char \**

**getprogname**\ (*void*);

*void*

**setprogname**\ (*const char *progname*);

**DESCRIPTION**

The **getprogname**\ () and **setprogname**\ () functions manipulate the
name of the current program. They are used by error-reporting routines
to produce consistent output.

The **getprogname**\ () function returns the name of the program. If the
name has not been set yet, it will return NULL.

The **setprogname**\ () function sets the name of the program to be the
last component of the *progname* argument. Since a pointer to the given
string is kept as the program name, it should not be modified for the
rest of the program’s lifetime.

In FreeBSD, the name of the program is set by the start-up code that is
run before **main**\ (); thus, running **setprogname**\ () is not
necessary. Programs that desire maximum portability should still call
it; on another operating system, these functions may be implemented in a
portability library. Calling **setprogname**\ () allows the
aforementioned library to learn the program name without modifications
to the start-up code.

**SEE ALSO**

err(3), setproctitle(3)

**HISTORY**

These functions first appeared in NetBSD 1.6, and made their way into
FreeBSD 4.4.

BSD May 1, 2001 BSD

--------------
