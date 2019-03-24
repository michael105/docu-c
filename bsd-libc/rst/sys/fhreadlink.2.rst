--------------

FHREADLINK(2) BSD System Calls Manual FHREADLINK(2)

**NAME**

**fhreadlink** — read value of a symbolic link

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>**

*int*

**fhreadlink**\ (*fhandle_t *fhp*, *char *buf*, *size_t bufsize*);

**DESCRIPTION**

The **fhreadlink**\ () system call places the contents of the symbolic
link *fhp* in the buffer *buf*, which has size *bufsiz*. The
**fhreadlink**\ () system call does not append a NUL character to *buf*.

**RETURN VALUES**

The call returns the count of characters placed in the buffer if it
succeeds, or a −1 if an error occurs, placing the error code in the
global variable *errno*.

**ERRORS**

The **readlink**\ () system call will fail if:

[ENOENT]

The named file does not exist.

[ELOOP]

Too many symbolic links were encountered in translating the file handle
*fhp*.

[EINVAL]

The named file is not a symbolic link.

[EIO]

An I/O error occurred while reading from the file system.

[EFAULT]

The *buf* argument extends outside the process’s allocated address
space.

[ESTALE]

The file handle *fhp* is no longer valid

**SEE ALSO**

fhstat(2), fhlink(2),

BSD November 29, 2018 BSD

--------------
