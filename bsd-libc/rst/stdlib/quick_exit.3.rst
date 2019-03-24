--------------

QUICK_EXIT(3) BSD Library Functions Manual QUICK_EXIT(3)

**NAME**

**quick_exit** — exits a program quickly, running minimal cleanup

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*\_Noreturn void*

**quick_exit**\ (*int status*);

**DESCRIPTION**

The **quick_exit**\ () function exits the program quickly calling any
cleanup functions registered with at_quick_exit(3) but not any C++
destructors or cleanup code registered with atexit(3). The stdio(3) file
buffers are not flushed.

The function **quick_exit**\ () is *async-signal safe* when the
functions registered with at_quick_exit(3) are.

**RETURN VALUES**

The **quick_exit**\ () function does not return.

**SEE ALSO**

at_quick_exit(3), exit(3)

**STANDARDS**

The **quick_exit**\ () function conforms to ISO/IEC 9899:2011
(‘‘ISO C11’’).

BSD November 4, 2017 BSD

--------------
