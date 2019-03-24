--------------

ACL_INIT(3) BSD Library Functions Manual ACL_INIT(3)

**NAME**

**acl_init** — initialize ACL working storage

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*acl_t*

**acl_init**\ (*int count*);

**DESCRIPTION**

The **acl_init**\ () function allocates and initializes the working
storage for an ACL of at least *count* ACL entries. A pointer to the
working storage is returned. The working storage allocated to contain
the ACL is freed by a call to acl_free(3). When the area is first
allocated, it shall contain an ACL that contains no ACL entries.

This function may cause memory to be allocated. The caller should free
any releasable memory, when the new ACL is no longer required, by
calling acl_free(3) with the *(void*)acl_t* as an argument.

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

Upon successful completion, this function shall return a pointer to the
working storage. Otherwise, a value of *(acl_t)NULL* shall be returned,
and *errno* shall be set to indicate the error.

**ERRORS**

If any of the following conditions occur, the **acl_init**\ () function
shall return a value of *(acl_t)NULL* and set *errno* to the
corresponding value:

[EINVAL]

The value of count is less than zero.

[ENOMEM]

The *acl_t* to be returned requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_free(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0, and development
continues.

**AUTHORS**

Robert N M Watson

BSD January 28, 2000 BSD

--------------
