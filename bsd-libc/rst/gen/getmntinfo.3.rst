--------------

GETMNTINFO(3) BSD Library Functions Manual GETMNTINFO(3)

**NAME**

**getmntinfo** — get information about mounted file systems

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>**

*int*

**getmntinfo**\ (*struct statfs **mntbufp*, *int mode*);

**DESCRIPTION**

The **getmntinfo**\ () function returns an array of **statfs**\ ()
structures describing each currently mounted file system (see
statfs(2)).

The **getmntinfo**\ () function passes its *mode* argument transparently
to getfsstat(2).

**RETURN VALUES**

On successful completion, **getmntinfo**\ () returns a count of the
number of elements in the array. The pointer to the array is stored into
*mntbufp*.

If an error occurs, zero is returned and the external variable *errno*
is set to indicate the error. Although the pointer *mntbufp* will be
unmodified, any information previously returned by **getmntinfo**\ ()
will be lost.

**ERRORS**

The **getmntinfo**\ () function may fail and set errno for any of the
errors specified for the library routines getfsstat(2) or malloc(3).

**SEE ALSO**

getfsstat(2), mount(2), statfs(2), mount(8)

**HISTORY**

The **getmntinfo**\ () function first appeared in 4.4BSD.

**BUGS**

The **getmntinfo**\ () function writes the array of structures to an
internal static object and returns a pointer to that object. Subsequent
calls to **getmntinfo**\ () will modify the same object.

The memory allocated by **getmntinfo**\ () cannot be free(3)’d by the
application.

BSD December 27, 2016 BSD

--------------
