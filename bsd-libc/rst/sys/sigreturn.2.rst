--------------

SIGRETURN(2) BSD System Calls Manual SIGRETURN(2)

**NAME**

**sigreturn** — return from signal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigreturn**\ (*const ucontext_t *scp*);

**DESCRIPTION**

The **sigreturn**\ () system call allows users to atomically unmask,
switch stacks, and return from a signal context. The thread’s signal
mask and stack status are restored from the context structure pointed to
by *scp*. The system call does not return; the users stack pointer,
frame pointer, argument pointer, and processor status longword are
restored from the context. Execution resumes at the specified pc. This
system call is used by the trampoline code and longjmp(3) when returning
from a signal to the previously executing program.

**RETURN VALUES**

If successful, the system call does not return. Otherwise, a value of -1
is returned and *errno* is set to indicate the error.

**ERRORS**

The **sigreturn**\ () system call will fail and the thread context will
remain unchanged if one of the following occurs.

[EFAULT]

The *scp* argument points to memory that is not a valid part of the
process address space.

[EINVAL]

The process status longword is invalid or would improperly raise the
privilege level of the process.

**SEE ALSO**

sigaction(2), setjmp(3), ucontext(3)

**HISTORY**

The **sigreturn**\ () system call appeared in 4.3BSD.

BSD September 6, 2013 BSD

--------------
