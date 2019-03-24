--------------

FHOPEN(2) BSD System Calls Manual FHOPEN(2)

**NAME**

**fhopen**, **fhstat**, **fhstatfs** — access file via file handle

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>
#include <sys/stat.h>**

*int*

**fhopen**\ (*const fhandle_t *fhp*, *int flags*);

*int*

**fhstat**\ (*const fhandle_t *fhp*, *struct stat *sb*);

*int*

**fhstatfs**\ (*const fhandle_t *fhp*, *struct statfs *buf*);

**DESCRIPTION**

These system calls provide a means to access a file given the file
handle *fhp*. As this method bypasses directory access restrictions,
these calls are restricted to the superuser.

The **fhopen**\ () system call opens the file referenced by *fhp* for
reading and/or writing as specified by the argument *flags* and returns
the file descriptor to the calling process. The *flags* argument is
specified by *or*\ ’ing together the flags used for the open(2) system
call. All said flags are valid except for O_CREAT.

The **fhstat**\ () and **fhstatfs**\ () system calls provide the
functionality of the fstat(2) and fstatfs(2) calls except that they
return information for the file referred to by *fhp* rather than an open
file.

**RETURN VALUES**

Upon successful completion, **fhopen**\ () returns the file descriptor
for the opened file; otherwise the value −1 is returned and the global
variable *errno* is set to indicate the error.

The **fhstat**\ () and **fhstatfs**\ () functions return the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

In addition to the errors returned by open(2), fstat(2), and fstatfs(2)
respectively, **fhopen**\ (), **fhstat**\ (), and **fhstatfs**\ () will
return

[EINVAL]

Calling **fhopen**\ () with O_CREAT set.

[ESTALE]

The file handle *fhp* is no longer valid.

**SEE ALSO**

fstat(2), fstatfs(2), getfh(2), open(2)

**HISTORY**

The **fhopen**\ (), **fhstat**\ (), and **fhstatfs**\ () system calls
first appeared in NetBSD 1.5 and were adapted to FreeBSD 4.0 by Alfred
Perlstein.

**AUTHORS**

This manual page was written by William Studenmund for NetBSD.

BSD June 29, 1999 BSD

--------------
