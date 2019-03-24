--------------

ACL_DUP(3) BSD Library Functions Manual ACL_DUP(3)

**NAME**

**acl_dup** — duplicate an ACL

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*acl_t*

**acl_dup**\ (*acl_t acl*);

**DESCRIPTION**

The **acl_dup**\ () function returns a pointer to a copy of the ACL
pointed to by the argument *acl*.

This function may cause memory to be allocated. The caller should free
any releasable memory, when the new ACL is no longer required, by
calling acl_free(3) with the *(void*)acl_t* as an argument.

Any existing ACL pointers that refer to the ACL referred to by *acl*
shall continue to refer to the ACL.

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

Upon successful completion, this function shall return a pointer to the
duplicate ACL. Otherwise, a value of *(acl_t)NULL* shall be returned,
and *errno* shall be set to indicate the error.

**ERRORS**

If any of the following conditions occur, the **acl_init**\ () function
shall return a value of *(acl_t)NULL* and set *errno* to the
corresponding value:

[EINVAL]

Argument *acl* does not point to a valid ACL.

[ENOMEM]

The *acl_t* to be returned requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_free(3), acl_get(3), posix1e(3)

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
