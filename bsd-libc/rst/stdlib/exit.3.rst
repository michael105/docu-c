--------------

EXIT(3) BSD Library Functions Manual EXIT(3)

**NAME**

**exit**, **\_Exit** — perform normal program termination

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void*

**exit**\ (*int status*);

*void*

**\_Exit**\ (*int status*);

**DESCRIPTION**

The **exit**\ () and **\_Exit**\ () functions terminate a process.

Before termination, **exit**\ () performs the following functions in the
order listed:

1.

Call the functions registered with the atexit(3) function, in the
reverse order of their registration.

2.

Flush all open output streams.

3.

Close all open streams.

4.

Unlink all files created with the tmpfile(3) function.

The **\_Exit**\ () function terminates without calling the functions
registered with the atexit(3) function, and may or may not perform the
other actions listed. Both functions make the low-order eight bits of
the *status* argument available to a parent process which has called a
wait(2)-family function.

The C Standard (ISO/IEC 9899:1999 (‘‘ISO C99’’)) defines the values 0,
EXIT_SUCCESS, and EXIT_FAILURE as possible values of *status*.
Cooperating processes may use other values; in a program which might be
called by a mail transfer agent, the values described in sysexits(3) may
be used to provide more information to the parent process.

Note that **exit**\ () does nothing to prevent bottomless recursion
should a function registered using atexit(3) itself call **exit**\ ().
Such functions must call **\_Exit**\ () instead (although this has other
effects as well which may not be desired).

**RETURN VALUES**

The **exit**\ () and **\_Exit**\ () functions never return.

**SEE ALSO**

\_exit(2), abort2(2), wait(2), at_quick_exit(3), atexit(3), intro(3),
quick_exit(3), sysexits(3), tmpfile(3)

**STANDARDS**

The **exit**\ () and **\_Exit**\ () functions conform to ISO/IEC
9899:1999 (‘‘ISO C99’’).

BSD May 28, 2018 BSD

--------------
