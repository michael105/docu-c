--------------

ULIMIT(3) BSD Library Functions Manual ULIMIT(3)

**NAME**

**ulimit** — get and set process limits

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ulimit.h>**

*long*

**ulimit**\ (*int cmd*, *...*);

**DESCRIPTION**

The **ulimit**\ () function will get and set process limits. Currently
this is limited to the maximum file size. The *cmd* argument is one of
the following:

UL_GETFSIZE

will return the maximum file size in units of 512 blocks of the current
process.

UL_SETFSIZE

will attempt to set the maximum file size of the current process and its
children with the second argument expressed as a long.

**RETURN VALUES**

Upon successful completion, **ulimit**\ () returns the value requested;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **ulimit**\ () function will fail if:

[EINVAL]

The command specified was invalid.

[EPERM]

The limit specified to **ulimit**\ () would have raised the maximum
limit value, and the caller is not the super-user.

**SEE ALSO**

getrlimit(2)

**STANDARDS**

The **ulimit**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **ulimit**\ () function first appeared in FreeBSD 5.0.

**BUGS**

The **ulimit**\ () function provides limited precision for setting and
retrieving process limits. If there is a need for greater precision than
the type *long* provides, the getrlimit(2) and setrlimit(2) functions
should be considered.

BSD January 4, 2003 BSD

--------------
