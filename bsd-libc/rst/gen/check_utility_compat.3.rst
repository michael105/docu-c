--------------

CHECK_UTILITY_COMPAT(3) BSD Library Functions Manual
CHECK_UTILITY_COMPAT(3)

**NAME**

**check_utility_compat** — determine whether a utility should be
compatible

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**check_utility_compat**\ (*const char *utility*);

**DESCRIPTION**

The **check_utility_compat**\ () function checks whether *utility*
should behave in a traditional (FreeBSD 4.7-compatible) manner, or in
accordance with IEEE Std 1003.1-2001 (‘‘POSIX.1’’). The configuration is
given as a comma-separated list of utility names; if the list is present
but empty, all supported utilities assume their most compatible mode.
The **check_utility_compat**\ () function first checks for an
environment variable named \_COMPAT_FreeBSD_4. If that environment
variable does not exist, then **check_utility_compat**\ () will attempt
to read the contents of a symbolic link named
*/etc/compat-FreeBSD-4-util*. If no configuration is found,
compatibility mode is disabled.

**RETURN VALUES**

The **check_utility_compat**\ () function returns zero if *utility*
should implement strict IEEE Std 1003.1-2001 (‘‘POSIX.1’’) behavior, and
nonzero otherwise.

| **FILES**
| /etc/compat-FreeBSD-4-util

If present, a symbolic link whose expansion gives system-wide default
settings for the **check_utility_compat**\ () function.

**ERRORS**

No errors are detected.

**HISTORY**

The **check_utility_compat**\ () function first appeared in FreeBSD 5.0.

**AUTHORS**

This manual page was written by Garrett Wollman <*wollman@FreeBSD.org*>.

BSD October 27, 2002 BSD

--------------
