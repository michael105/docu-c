--------------

GETLOGINCLASS(2) BSD System Calls Manual GETLOGINCLASS(2)

**NAME**

**getloginclass**, **setloginclass** — get/set login class

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getloginclass**\ (*char *name*, *size_t len*);

*int*

**setloginclass**\ (*const char *name*);

**DESCRIPTION**

The **getloginclass**\ () routine returns the login class name
associated with the calling process, as previously set by
**setloginclass**\ (). The caller must provide the buffer *name* with
length *len* bytes to hold the result. The buffer should be at least
MAXLOGNAME bytes in length.

The **setloginclass**\ () system call sets the login class of the
calling process to *name*. This system call is restricted to the
super-user, and is normally used only when a new session is being
created on behalf of the named user (for example, at login time, or when
a remote shell is invoked). Processes inherit login class from their
parents.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following errors may be returned by these calls:

[EFAULT]

The *name* argument gave an invalid address.

[EINVAL]

The *name* argument pointed to a string that was too long. Login class
names are limited to MAXLOGNAME (from <*sys/param.h*>) characters,
currently 33 including null.

[EPERM]

The caller tried to set the login class and was not the super-user.

[ENAMETOOLONG]

The size of the buffer is smaller than the result to be returned.

**SEE ALSO**

ps(1), setusercontext(3), login.conf(5), rctl(8)

**HISTORY**

The **getloginclass**\ () and **setloginclass**\ () system calls first
appeared in FreeBSD 9.0.

BSD July 12, 2016 BSD

--------------
