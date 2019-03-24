--------------

ACL_GET_BRAND_NP(3) BSD Library Functions Manual ACL_GET_BRAND_NP(3)

**NAME**

**acl_get_brand_np** — retrieve the ACL brand from an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_brand_np**\ (*acl_t acl*, *int *brand_p*);

**DESCRIPTION**

The **acl_get_brand_np**\ () function is a non-portable call that
returns the ACL brand for the ACL *acl*. Upon successful completion, the
location referred to by the argument *brand_p* will be set to the ACL
brand of the ACL *acl*.

Branding is an internal mechanism intended to prevent mixing POSIX.1e
and NFSv4 entries by mistake. It’s also used by the libc to determine
how to print out the ACL. The first call to function that is specific
for one particular brand - POSIX.1e or NFSv4 - "brands" the ACL. After
that, calling function specific to another brand will result in error.

**RETURN VALUES**

The **acl_get_brand_np**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_get_brand_np**\ () function fails if:

[EINVAL]

Argument *acl* does not point to a valid ACL.

**SEE ALSO**

acl(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_brand_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_get_brand_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD June 25, 2009 BSD

--------------
