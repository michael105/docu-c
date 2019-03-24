--------------

NICE(3) BSD Library Functions Manual NICE(3)

**NAME**

**nice** — set program scheduling priority

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**nice**\ (*int incr*);

**DESCRIPTION**

**This interface is obsoleted by** setpriority(\ **2**)\ **.**

The **nice**\ () function adds *incr* to the scheduling priority of the
process. The priority is a value in the range -20 to 20. The default
priority is 0; lower priorities cause more favorable scheduling. Only
the super-user may lower priorities.

Children inherit the priority of their parent processes via fork(2).

**RETURN VALUES**

Upon successful completion, **nice**\ () returns 0, and *errno* is
unchanged. Otherwise, −1 is returned, the process’ nice value is not
changed, and *errno* is set to indicate the error.

**ERRORS**

The **nice**\ () function will fail if:

[EPERM]

The *incr* argument is negative and the caller does not have appropriate
privileges.

**SEE ALSO**

nice(1), fork(2), setpriority(2), renice(8)

**STANDARDS**

The **nice**\ () function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’)
except for the return value. This implementation returns 0 upon
successful completion but the standard requires returning the new nice
value, which could be −1.

**HISTORY**

A **nice**\ () syscall appeared in Version 6 AT&T UNIX.

BSD February 28, 2015 BSD

--------------
