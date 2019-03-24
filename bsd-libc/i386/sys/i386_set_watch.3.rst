--------------

I386_SET_WATCH(3) BSD Library Functions Manual I386_SET_WATCH(3)

**NAME**

**i386_clr_watch**, **i386_set_watch** — manage i386 debug register
values

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <machine/reg.h>
#include <machine/sysarch.h>**

*int*

**i386_clr_watch**\ (*int watchnum*, *struct dbreg *d*);

*int*

**i386_set_watch**\ (*int watchnum*, *unsigned int watchaddr*,
*int size*, *int access*, *struct dbreg *d*);

**DESCRIPTION**

The **i386_clr_watch**\ () function will disable the indicated watch
point within the specified debug register set.

The **i386_set_watch**\ () function will set up the specified debug
registers as indicated by the arguments. The *watchnum* argument
specifies which watch register is used, 0, 1, 2, 3, or −1. If *watchnum*
is −1, a free watch register is found and used. If there are no free
watch registers, an error code of −1 is returned. The *watchaddr*
argument specifies the watch address, *size* specifies the size in bytes
of the area to be watched (1, 2, or 4 bytes), and *access* specifies the
type of watch point:

+-------------+-------------+-------------+-------------+-------------+
|             | DBREG_DR7_E |             | An          |             |
|             | XEC         |             | execution   |             |
|             |             |             | breakpoint. |             |
+-------------+-------------+-------------+-------------+-------------+

DBREG_DR7_WRONLY Break only when the watch area is written to.

+-------------+-------------+-------------+-------------+-------------+
|             | DBREG_DR7_R |             | Break when  |             |
|             | DWR         |             | the watch   |             |
|             |             |             | area is     |             |
|             |             |             | read from   |             |
|             |             |             | or written  |             |
+-------------+-------------+-------------+-------------+-------------+

to.

Note that these functions do not actually set or clear breakpoints; they
manipulate the indicated debug register set. You must use ptrace(2) to
retrieve and install the debug register values for a process.

**RETURN VALUES**

On success, the **i386_clr_watch**\ () function returns 0. On error, −1
returned which indicates that *watchnum* is invalid (not in the range of
0-3). If the specified watchnum was already disabled, no error is
returned.

On success, the **i386_set_watch**\ () function returns the *watchnum*
argument, or the watchnum actually used in the case where the specified
*watchnum* was −1. On error, the **i386_set_watch**\ () function returns
−1 indicating that the watchpoint could not established because either
no more watchpoints are available, or *watchnum*, *size*, or *access* is
invalid.

**SEE ALSO**

ptrace(2), procfs(5)

**AUTHORS**

This man page was written by Brian S. Dean.

BSD August 24, 2000 BSD

--------------
