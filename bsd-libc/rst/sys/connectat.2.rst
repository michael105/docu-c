--------------

CONNECTAT(2) BSD System Calls Manual CONNECTAT(2)

**NAME**

**connectat** — initiate a connection on a socket

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

**#include <fcntl.h>**

*int*

**connectat**\ (*int fd*, *int s*, *const struct sockaddr *name*,
*socklen_t namelen*);

**DESCRIPTION**

The **connectat**\ () system call initiates a connection on a socket.
When passed the special value AT_FDCWD in the *fd* parameter, the
behavior is identical to a call to connect(2). Otherwise,
**connectat**\ () works like the connect(2) system call with two
exceptions:

1.

It is limited to sockets in the PF_LOCAL domain.

2.

If the file path stored in the *sun_path* field of the sockaddr_un
structure is a relative path, it is located relative to the directory
associated with the file descriptor *fd*.

**RETURN VALUES**

The **connectat**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **connectat**\ () system call may fail with the same errors as the
connect(2) system call or with the following errors:

[EBADF]

The *sun_path* field does not specify an absolute path and the *fd*
argument is neither AT_FDCWD nor a valid file descriptor.

[ENOTDIR]

The *sun_path* field is not an absolute path and *fd* is neither
AT_FDCWD nor a file descriptor associated with a directory.

**SEE ALSO**

bindat(2), connect(2), socket(2), unix(4)

**AUTHORS**

The **connectat** was developed by Pawel Jakub Dawidek
<*pawel@dawidek.net*> under sponsorship from the FreeBSD Foundation.

BSD February 13, 2013 BSD

--------------
