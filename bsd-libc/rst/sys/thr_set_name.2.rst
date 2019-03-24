--------------

THR_SET_NAME(2) BSD System Calls Manual THR_SET_NAME(2)

**NAME**

**thr_set_name** — set user-visible thread name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/thr.h>**

*int*

**thr_set_name**\ (*long id*, *const char *name*);

**DESCRIPTION**

The **thr_set_name**\ () system call sets the user-visible name for the
thread with the identifier *id* in the current process to the
NUL-terminated string *name*. The name will be silently truncated to fit
into a buffer of MAXCOMLEN + 1 bytes. The thread name can be seen in the
output of the ps(1) and top(1) commands, in the kernel debuggers and
kernel tracing facility outputs, and in userland debuggers and program
core files, as notes.

**RETURN VALUES**

If successful, **thr_set_name**\ () returns zero; otherwise, −1 is
returned, and *errno* is set to indicate the error.

**ERRORS**

The **thr_set_name**\ () system call may return the following errors:

[EFAULT]

The memory pointed to by the *name* argument is not valid.

[ESRCH]

The thread with the identifier *id* does not exist in the current
process.

**SEE ALSO**

ps(1), thr_exit(2), thr_kill(2), thr_kill2(2), thr_new(2), thr_self(2),
\_umtx_op(2), pthread_set_name_np(3), ddb(4), ktr(9)

**STANDARDS**

The **thr_set_name**\ () system call is non-standard and is used by the
1:1 Threading Library (libthr, −lthr).

BSD December 2, 2016 BSD

--------------
