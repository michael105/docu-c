--------------

UNAME(3) BSD Library Functions Manual UNAME(3)

**NAME**

**uname** — get system identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/utsname.h>**

*int*

**uname**\ (*struct utsname *name*);

**DESCRIPTION**

The **uname**\ () function stores NUL-terminated strings of information
identifying the current system into the structure referenced by *name*.

The *utsname* structure is defined in the <*sys/utsname.h*> header file,
and contains the following members:

sysname

Name of the operating system implementation.

nodename

Network name of this machine.

release

Release level of the operating system.

version

Version level of the operating system.

machine

Machine hardware platform.

**RETURN VALUES**

The **uname**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

| **ENVIRONMENT**
| UNAME_s

If the environment variable UNAME_s is set, it will override the
*sysname* member.

UNAME_r

If the environment variable UNAME_r is set, it will override the
*release* member.

UNAME_v

If the environment variable UNAME_v is set, it will override the
*version* member.

UNAME_m

If the environment variable UNAME_m is set, it will override the
*machine* member.

**ERRORS**

The **uname**\ () function may fail and set *errno* for any of the
errors specified for the library functions sysctl(3).

**SEE ALSO**

uname(1), sysctl(3)

**STANDARDS**

The **uname**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**HISTORY**

The **uname**\ () function first appeared in 4.4BSD.

BSD December 2, 2005 BSD

--------------
