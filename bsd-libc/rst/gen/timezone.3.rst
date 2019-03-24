--------------

TIMEZONE(3) BSD Library Functions Manual TIMEZONE(3)

**NAME**

**timezone** — return the timezone abbreviation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

*char \**

**timezone**\ (*int zone*, *int dst*);

**DESCRIPTION**

**This interface is for compatibility only; it is impossible to reliably
map timezone’s arguments to a time zone abbreviation. See**
ctime(\ **3**)\ **.**

The **timezone**\ () function returns a pointer to a time zone
abbreviation for the specified *zone* and *dst* values. The *zone*
argument is the number of minutes west of GMT and *dst* is non-zero if
daylight savings time is in effect.

**SEE ALSO**

ctime(3)

**HISTORY**

A **timezone**\ () function appeared in Version 7 AT&T UNIX.

BSD April 19, 1994 BSD

--------------
