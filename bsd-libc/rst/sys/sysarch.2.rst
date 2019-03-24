--------------

SYSARCH(2) BSD System Calls Manual SYSARCH(2)

**NAME**

**sysarch** — architecture-dependent system call

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <machine/sysarch.h>**

*int*

**sysarch**\ (*int number*, *void *args*);

**DESCRIPTION**

The **sysarch**\ () system call performs the architecture-dependent
function specified by *number* with the arguments specified by the
*args* pointer. The *args* argument is a pointer to a structure defining
the actual arguments of the function. Symbolic constants and argument
structures for the architecture-dependent functions can be found in the
header file <*machine/sysarch.h*>.

The **sysarch**\ () system call should never be called directly by user
programs. Instead, they should access its functions using the
architecture-dependent library.

**RETURN VALUES**

See the manual pages for specific architecture-dependent system calls
for information about their return values.

**SEE ALSO**

i386_get_ioperm(2), i386_get_ldt(2), i386_vm86(2)

**HISTORY**

This manual page was taken from NetBSD.

BSD October 11, 1993 BSD

--------------
