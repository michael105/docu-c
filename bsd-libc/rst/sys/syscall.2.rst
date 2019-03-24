--------------

SYSCALL(2) BSD System Calls Manual SYSCALL(2)

**NAME**

**syscall**, **\__syscall** — indirect system call

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/syscall.h>
#include <unistd.h>**

*int*

**syscall**\ (*int number*, *...*);

*off_t*

**\__syscall**\ (*quad_t number*, *...*);

**DESCRIPTION**

The **syscall**\ () function performs the system call whose assembly
language interface has the specified *number* with the specified
arguments. Symbolic constants for system calls can be found in the
header file <*sys/syscall.h*>. The **\__syscall**\ () form should be
used when one or more of the arguments is a 64-bit argument to ensure
that argument alignment is correct. This system call is useful for
testing new system calls that do not have entries in the C library.

**RETURN VALUES**

The return values are defined by the system call being invoked. In
general, a 0 return value indicates success. A -1 return value indicates
an error, and an error code is stored in *errno*.

**HISTORY**

The **syscall**\ () function appeared in 4.0BSD.

**BUGS**

There is no way to simulate system calls that have multiple return
values such as pipe(2).

BSD June 16, 1993 BSD

--------------
