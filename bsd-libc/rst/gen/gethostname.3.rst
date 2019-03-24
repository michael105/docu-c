--------------

GETHOSTNAME(3) BSD Library Functions Manual GETHOSTNAME(3)

**NAME**

**gethostname**, **sethostname** — get/set name of current host

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**gethostname**\ (*char *name*, *size_t namelen*);

*int*

**sethostname**\ (*const char *name*, *int namelen*);

**DESCRIPTION**

The **gethostname**\ () function returns the standard host name for the
current processor, as previously set by **sethostname**\ (). The
*namelen* argument specifies the size of the *name* array. The returned
name is null-terminated unless insufficient space is provided.

The **sethostname**\ () function sets the name of the host machine to be
*name*, which has length *namelen*. This call is restricted to the
super-user and is normally used only when the system is bootstrapped.

Host names are limited to {HOST_NAME_MAX} characters, not including the
trailing null, currently 255.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following errors may be returned by these calls:

[EFAULT]

The *name* or *namelen* argument gave an invalid address.

[ENAMETOOLONG]

The current host name is longer than *namelen*. (For **gethostname**\ ()
only.)

[EPERM]

The caller tried to set the host name and was not the super-user.

**SEE ALSO**

sysconf(3), sysctl(3)

**STANDARDS**

The **gethostname**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’). Callers should be aware that {HOST_NAME_MAX} may be
variable or infinite, but is guaranteed to be no less than
{_POSIX_HOST_NAME_MAX}. On older systems, this limit was defined in the
non-standard header <*sys/param.h*> as MAXHOSTNAMELEN, and counted the
terminating null. The **sethostname**\ () function and the error returns
for **gethostname**\ () are not standardized.

**HISTORY**

The **gethostname**\ () function appeared in 4.2BSD. The *namelen*
argument to **gethostname**\ () was changed to *size_t* in FreeBSD 5.2
for alignment with IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

BSD August 18, 2003 BSD

--------------
