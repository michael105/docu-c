--------------

RPMATCH(3) BSD Library Functions Manual RPMATCH(3)

**NAME**

**rpmatch** — determine whether the response to a question is
affirmative or negative

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**rpmatch**\ (*const char *response*);

**DESCRIPTION**

The **rpmatch**\ () function determines whether the *response* argument
is an affirmative or negative response to a question according to the
current locale.

**RETURN VALUES**

The **rpmatch**\ () functions returns:

1

The response is affirmative.

0

The response is negative.

-1

The response is not recognized.

**SEE ALSO**

nl_langinfo(3), setlocale(3)

**HISTORY**

The **rpmatch**\ () function appeared in FreeBSD 6.0.

BSD July 21, 2005 BSD

--------------
