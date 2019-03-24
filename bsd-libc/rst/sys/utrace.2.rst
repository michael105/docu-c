--------------

UTRACE(2) BSD System Calls Manual UTRACE(2)

**NAME**

**utrace** — insert user record in ktrace log

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/ktrace.h>**

*int*

**utrace**\ (*const void *addr*, *size_t len*);

**DESCRIPTION**

Adds a record to the process trace with information supplied by user.
The record contains *len* bytes from memory pointed to by *addr*. This
call only has an effect if the calling process is being traced.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

| **ERRORS**
| [EINVAL]

Specified data length *len* was bigger than KTR_USER_MAXLEN.

[ENOMEM]

Insufficient memory to honor the request.

[ENOSYS]

Currently running kernel was compiled without ktrace(2) support
(**options KTRACE**).

**SEE ALSO**

kdump(1), ktrace(1), truss(1), ktrace(2), sysdecode_utrace(3)

**HISTORY**

The **utrace**\ () system call first appeared in FreeBSD 2.2.

BSD December 11, 2015 BSD

--------------
