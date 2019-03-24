--------------

GETOSRELDATE(3) BSD Library Functions Manual GETOSRELDATE(3)

**NAME**

**getosreldate** — get the value of \__FreeBSD_version

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getosreldate**\ (*void*);

**DESCRIPTION**

The **getosreldate**\ () function returns an integer showing the version
of the currently running FreeBSD kernel. Definitions of the values can
be found in *The Porter’s Handbook*:

**https://www.FreeBSD.org/doc/en/books/porters-handbook/**

**RETURN VALUES**

Upon successful completion, **getosreldate**\ () returns the value
requested; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

| **ENVIRONMENT**
| OSVERSION

If the environment variable OSVERSION is set, it will override the
**getosreldate**\ () return value.

**EXAMPLES**

An example can be found in */usr/share/examples/FreeBSD_version*.

**ERRORS**

The **getosreldate**\ () function may fail and set *errno* for any of
the errors specified for the library function sysctl(3).

**SEE ALSO** *
The Porter’s Handbook*

.

**HISTORY**

The **getosreldate**\ () function appeared in FreeBSD 2.0.

BSD June 13, 2018 BSD

--------------
