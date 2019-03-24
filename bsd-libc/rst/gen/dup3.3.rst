--------------

DUP3(3) BSD Library Functions Manual DUP3(3)

**NAME**

**dup3** — duplicate an existing file descriptor

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>
#include <unistd.h>**

*int*

**dup3**\ (*int oldd*, *int newd*, *int flags*);

**DESCRIPTION**

The **dup3**\ () function duplicates an existing object descriptor while
allowing the value of the new descriptor to be specified.

The close-on-exec flag on the new file descriptor is determined by the
O_CLOEXEC bit in *flags*.

If *oldd* ≠ *newd* and *flags* == 0, the behavior is identical to
dup2(oldd, newd).

If *oldd* == *newd*, then **dup3**\ () fails, unlike dup2(2).

**RETURN VALUES**

The value -1 is returned if an error occurs. The external variable
*errno* indicates the cause of the error.

**ERRORS**

The **dup3**\ () function fails if:

[EBADF]

The *oldd* argument is not a valid active descriptor or the *newd*
argument is negative or exceeds the maximum allowable descriptor number

[EINVAL]

The *oldd* argument is equal to the *newd* argument.

[EINVAL]

The *flags* argument has bits set other than O_CLOEXEC.

**SEE ALSO**

accept(2), close(2), dup2(2), fcntl(2), getdtablesize(2), open(2),
pipe(2), socket(2), socketpair(2)

**STANDARDS**

The **dup3**\ () function does not conform to any standard.

**HISTORY**

The **dup3**\ () function appeared in FreeBSD 10.0.

BSD August 16, 2013 BSD

--------------
