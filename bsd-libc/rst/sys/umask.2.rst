--------------

UMASK(2) BSD System Calls Manual UMASK(2)

**NAME**

**umask** — set file creation mode mask

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/stat.h>**

*mode_t*

**umask**\ (*mode_t numask*);

**DESCRIPTION**

The **umask**\ () routine sets the process’s file mode creation mask to
*numask* and returns the previous value of the mask. The 9 low-order
access permission bits of *numask* are used by system calls, including
open(2), mkdir(2), and mkfifo(2), to turn off corresponding bits
requested in file mode. (See chmod(2)). This clearing allows each user
to restrict the default access to his files.

The default mask value is S_IWGRP|S_IWOTH (022, write access for the
owner only). Child processes inherit the mask of the calling process.

**RETURN VALUES**

The previous value of the file mode mask is returned by the call.

**ERRORS**

The **umask**\ () system call is always successful.

**SEE ALSO**

chmod(2), mkfifo(2), mknod(2), open(2)

**STANDARDS**

The **umask**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **umask**\ () function appeared in Version 7 AT&T UNIX.

BSD June 4, 1993 BSD

--------------
