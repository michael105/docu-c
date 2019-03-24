--------------

TIME(3) BSD Library Functions Manual TIME(3)

**NAME**

**time** — get time of day

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*time_t*

**time**\ (*time_t *tloc*);

**DESCRIPTION**

The **time**\ () function returns the value of time in seconds since 0
hours, 0 minutes, 0 seconds, January 1, 1970, Coordinated Universal
Time. If an error occurs, **time**\ () returns the value (

*time_t* )−1.

The return value is also stored in \*\ *tloc*, provided that *tloc* is
non-null.

**ERRORS**

The **time**\ () function may fail for any of the reasons described in
gettimeofday(2).

**SEE ALSO**

clock_gettime(2), gettimeofday(2), ctime(3)

**STANDARDS**

The **time** function conforms to IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

A **time**\ () function appeared in Version 6 AT&T UNIX.

**BUGS**

Neither ISO/IEC 9899:1999 (‘‘ISO C99’’) nor IEEE Std 1003.1-2001
(‘‘POSIX.1’’) requires **time**\ () to set *errno* on failure; thus, it
is impossible for an application to distinguish the valid time value −1
(representing the last UTC second of 1969) from the error return value.

Systems conforming to earlier versions of the C and POSIX standards
(including older versions of FreeBSD) did not set \*\ *tloc* in the
error case.

BSD July 18, 2003 BSD

--------------
