--------------

CAP_SANDBOXED(3) BSD Library Functions Manual CAP_SANDBOXED(3)

**NAME**

**cap_sandboxed** — Check if in a capability mode sandbox

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>
#include <stdbool.h>**

*bool*

**cap_sandboxed**\ (*void*);

**DESCRIPTION**

**cap_sandboxed**\ () returns *true* if the process is in a capability
mode sandbox or *false* if it is not. This function is a more handy
alternative to the cap_getmode(2) system call as it always succeeds, so
there is no need for error checking. If the support for capability mode
is not compiled into the kernel, **cap_sandboxed**\ () will always
return *false*.

**RETURN VALUES**

Function **cap_sandboxed**\ () is always successful and will return
either *true* or *false*.

**SEE ALSO**

cap_enter(2), capsicum(4)

**AUTHORS**

This function was implemented and manual page was written by Pawel Jakub
Dawidek <*pawel@dawidek.net*> under sponsorship of the FreeBSD
Foundation.

BSD March 27, 2014 BSD

--------------
