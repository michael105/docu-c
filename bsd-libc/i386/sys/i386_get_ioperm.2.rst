--------------

I386_GET_IOPERM(2) BSD System Calls Manual I386_GET_IOPERM(2)

**NAME**

**i386_get_ioperm**, **i386_set_ioperm** — manage per-process access to
the i386 I/O port space

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <machine/sysarch.h>**

*int*

**i386_get_ioperm**\ (*unsigned int start*, *unsigned int *length*,
*int *enable*);

*int*

**i386_set_ioperm**\ (*unsigned int start*, *unsigned int length*,
*int enable*);

**DESCRIPTION**

The **i386_get_ioperm**\ () system call will return the permission for
the process’ I/O port space in the *\*enable* argument. The port range
starts at *start* and the number of contiguous entries will be returned
in *\*length*.

The **i386_set_ioperm**\ () system call will set access to a range of
I/O ports described by the *start* and *length* arguments to the state
specified by the *enable* argument.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **i386_get_ioperm**\ () and **i386_set_ioperm**\ () system calls
will fail if:

[EINVAL]

An invalid range was specified by the *start* or *length* arguments.

[EPERM]

The caller of i386_set_ioperm was not the superuser.

**SEE ALSO**

io(4)

**AUTHORS**

This man page was written by Jonathan Lemon.

BSD July 27, 1998 BSD

--------------
