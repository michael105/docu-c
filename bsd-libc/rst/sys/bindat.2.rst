--------------

BINDAT(2) BSD System Calls Manual BINDAT(2)

**NAME**

**bindat** — assign a local protocol address to a socket

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

**#include <fcntl.h>**

*int*

**bindat**\ (*int fd*, *int s*, *const struct sockaddr *addr*,
*socklen_t addrlen*);

**DESCRIPTION**

The **bindat**\ () system call assigns the local protocol address to a
socket. When passed the special value AT_FDCWD in the *fd* parameter,
the behavior is identical to a call to bind(2). Otherwise,
**bindat**\ () works like the bind(2) system call with two exceptions:

1.

It is limited to sockets in the PF_LOCAL domain.

2.

If the file path stored in the *sun_path* field of the sockaddr_un
structure is a relative path, it is located relative to the directory
associated with the file descriptor *fd*.

**RETURN VALUES**

The **bindat**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **bindat**\ () system call may fail with the same errors as the
bind(2) system call or with the following errors:

[EBADF]

The *sun_path* field does not specify an absolute path and the *fd*
argument is neither AT_FDCWD nor a valid file descriptor.

[ENOTDIR]

The *sun_path* field is not an absolute path and *fd* is neither
AT_FDCWD nor a file descriptor associated with a directory.

**SEE ALSO**

bind(2), connectat(2), socket(2), unix(4)

**AUTHORS**

The **bindat** was developed by Pawel Jakub Dawidek
<*pawel@dawidek.net*> under sponsorship from the FreeBSD Foundation.

BSD February 13, 2013 BSD

--------------
