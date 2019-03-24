--------------

AT_QUICK_EXIT(3) BSD Library Functions Manual AT_QUICK_EXIT(3)

**NAME**

**at_quick_exit** — registers a cleanup function to run on quick exit

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**at_quick_exit**\ (*void (*func)(void)*);

**DESCRIPTION**

The **at_quick_exit**\ () function registers a cleanup function to be
called when the program exits as a result of calling quick_exit(3). The
cleanup functions are called in the reverse order and will not be called
if the program exits by calling exit(3), \_Exit(3), or abort(3).

**RETURN VALUES**

The **at_quick_exit**\ () function returns the value 0 if successful and
a non-zero value on failure.

**SEE ALSO**

exit(3), quick_exit(3)

**STANDARDS**

The **at_quick_exit**\ () function conforms to ISO/IEC 9899:2011
(‘‘ISO C11’’).

BSD December 7, 2011 BSD

--------------
