--------------

CAP_FCNTLS_LIMIT(2) BSD System Calls Manual CAP_FCNTLS_LIMIT(2)

**NAME**

**cap_fcntls_limit**, **cap_fcntls_get** — manage allowed fcntl commands

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>**

*int*

**cap_fcntls_limit**\ (*int fd*, *uint32_t fcntlrights*);

*int*

**cap_fcntls_get**\ (*int fd*, *uint32_t *fcntlrightsp*);

**DESCRIPTION**

If a file descriptor is granted the CAP_FCNTL capability right, the list
of allowed fcntl(2) commands can be selectively reduced (but never
expanded) with the **cap_fcntls_limit**\ () system call.

A bitmask of allowed fcntls commands for a given file descriptor can be
obtained with the **cap_fcntls_get**\ () system call.

**FLAGS**

The following flags may be specified in the *fcntlrights* argument or
returned in the *fcntlrightsp* argument:

CAP_FCNTL_GETFL

Permit F_GETFL command.

CAP_FCNTL_SETFL

Permit F_SETFL command.

CAP_FCNTL_GETOWN

Permit F_GETOWN command.

CAP_FCNTL_SETOWN

Permit F_SETOWN command.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

**cap_fcntls_limit**\ () succeeds unless:

[EBADF]

The *fd* argument is not a valid descriptor.

[EINVAL]

An invalid flag has been passed in *fcntlrights*.

[ENOTCAPABLE]

*fcntlrights* would expand the list of allowed fcntl(2) commands.

**cap_fcntls_get**\ () succeeds unless:

[EBADF]

The *fd* argument is not a valid descriptor.

[EFAULT]

The *fcntlrightsp* argument points at an invalid address.

**SEE ALSO**

cap_ioctls_limit(2), cap_rights_limit(2), fcntl(2)

**HISTORY**

Support for capabilities and capabilities mode was developed as part of
the TrustedBSD Project.

**AUTHORS**

This function was created by Pawel Jakub Dawidek <*pawel@dawidek.net*>
under sponsorship of the FreeBSD Foundation.

BSD March 27, 2014 BSD

--------------
