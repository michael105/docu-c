--------------

FTOK(3) BSD Library Functions Manual FTOK(3)

**NAME**

**ftok** — create IPC identifier from path name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>**

*key_t*

**ftok**\ (*const char *path*, *int id*);

**DESCRIPTION**

The **ftok**\ () function attempts to create a unique key suitable for
use with the msgget(2), semget(2) and shmget(2) functions given the
*path* of an existing file and a user-selectable *id*.

The specified *path* must specify an existing file that is accessible to
the calling process or the call will fail. Also, note that links to
files will return the same key, given the same *id*.

**RETURN VALUES**

The **ftok**\ () function will return -1 if *path* does not exist or if
it cannot be accessed by the calling process.

**SEE ALSO**

msgget(2), semget(2), shmget(2)

**HISTORY**

The **ftok**\ () function originates with System V and is typically used
by programs that use the System V IPC routines.

**AUTHORS**

Thorsten Lockert <*tholo@sigmasoft.com*>

**BUGS**

The returned key is computed based on the device minor number and inode
of the specified *path* in combination with the lower 8 bits of the
given *id*. Thus it is quite possible for the routine to return
duplicate keys.

BSD July 9, 2009 BSD

--------------
