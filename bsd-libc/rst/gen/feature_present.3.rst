--------------

FEATURE_PRESENT(3) BSD Library Functions Manual FEATURE_PRESENT(3)

**NAME**

**feature_present** — query presence of a kernel feature

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**feature_present**\ (*const char *feature*);

**DESCRIPTION**

The **feature_present**\ () function provides a method for an
application to determine if a specific kernel feature is present in the
currently running kernel. The *feature* argument specifies the name of
the feature to check. The **feature_present**\ () function will return 1
if the specified feature is present, otherwise it will return 0. If the
**feature_present**\ () function is not able to determine the presence
of *feature* due to an internal error it will return 0.

**RETURN VALUES**

If *feature* is present then 1 is returned; otherwise 0 is returned.

**SEE ALSO**

sysconf(3), sysctl(3)

**HISTORY**

The **feature_present**\ () function first appeared in FreeBSD 8.0.

BSD January 8, 2008 BSD

--------------
