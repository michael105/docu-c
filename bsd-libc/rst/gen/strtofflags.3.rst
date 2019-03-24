--------------

STRTOFFLAGS(3) BSD Library Functions Manual STRTOFFLAGS(3)

**NAME**

**fflagstostr**, **strtofflags** — convert between file flag bits and
their string names

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**fflagstostr**\ (*u_long flags*);

*int*

**strtofflags**\ (*char **stringp*, *u_long *setp*, *u_long *clrp*);

**DESCRIPTION**

The **fflagstostr**\ () function returns a comma separated string of the
file flags represented by *flags*. If no flags are set a zero length
string is returned.

If memory cannot be allocated for the return value, **fflagstostr**\ ()
returns NULL.

The value returned from **fflagstostr**\ () is obtained from
**malloc**\ () and should be returned to the system with **free**\ ()
when the program is done with it.

The **strtofflags**\ () function takes a string of file flags, as
described in chflags(1), parses it, and returns the ’set’ flags and
’clear’ flags such as would be given as arguments to chflags(2). On
success **strtofflags**\ () returns 0, otherwise it returns non-zero and
*stringp* is left pointing to the offending token.

**ERRORS**

The **fflagstostr**\ () function may fail and set errno for any of the
errors specified for the library routine malloc(3).

**SEE ALSO**

chflags(1), chflags(2), malloc(3)

**HISTORY**

The **fflagstostr**\ () and **strtofflags**\ () functions first appeared
in FreeBSD 4.0.

BSD January 1, 2000 BSD

--------------
