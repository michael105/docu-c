--------------

TIMESPEC_GET(3) BSD Library Functions Manual TIMESPEC_GET(3)

**NAME**

**timespec_get** — get current calendar time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*int*

**timespec_get**\ (*struct timespec *ts*, *int base*);

**DESCRIPTION**

The **timespec_get** function sets the interval pointed to by *ts* to
hold the current calendar time based on the specified time base in
*base*.

The base TIME_UTC returns the time since the epoch. This time is
expressed in seconds and nanoseconds since midnight (0 hour), January 1,
1970. In FreeBSD, this corresponds to CLOCK_REALTIME.

**RETURN VALUES**

The **timespec_get** function returns the passed value of *base* if
successful, otherwise 0 on failure.

**SEE ALSO**

gettimeofday(2), clock_gettime(2), time(3)

**STANDARDS**

The **timespec_get** function with a *base* of TIME_UTC conforms to
ISO/IEC 9899:2011 (‘‘ISO C11’’).

**HISTORY**

This interface first appeared in FreeBSD 12.

**AUTHORS**

| Kamil Rytarowski <*kamil@NetBSD.org*>
| Warner Losh <*imp@FreeBSD.org*>

BSD August 10, 2018 BSD

--------------
