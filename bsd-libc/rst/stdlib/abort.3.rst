--------------

ABORT(3) BSD Library Functions Manual ABORT(3)

**NAME**

**abort** — cause abnormal program termination

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void*

**abort**\ (*void*);

**DESCRIPTION**

The **abort**\ () function causes abnormal program termination to occur,
unless the signal SIGABRT is being caught and the signal handler does
not return.

Any open streams are flushed and closed.

**IMPLEMENTATION NOTES**

The **abort**\ () function is thread-safe. It is unknown if it is
async-cancel-safe.

**RETURN VALUES**

The **abort**\ () function never returns.

**SEE ALSO**

abort2(2), sigaction(2), exit(3)

**STANDARDS**

The **abort**\ () function conforms to ISO/IEC 9945-1:1990
(‘‘POSIX.1’’). The **abort**\ () function also conforms to ISO/IEC
9899:1999 (‘‘ISO C99’’) with the implementation specific details as
noted above.

BSD May 28, 2018 BSD

--------------
