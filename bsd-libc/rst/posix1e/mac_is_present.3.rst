--------------

MAC_IS_PRESENT(3) BSD Library Functions Manual MAC_IS_PRESENT(3)

**NAME**

**mac_is_present** — report whether the running system has MAC support

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mac.h>**

*int*

**mac_is_present**\ (*const char *policyname*);

**DESCRIPTION**

The **mac_is_present**\ () function determines whether the
currently-running kernel supports MAC for a given policy or not. If
*policyname* is non-NULL, the presence of the named policy (e.g.
‘‘biba’’, ‘‘mls’’, ‘‘te’’) is checked, otherwise the presence of any MAC
policies at all is checked.

**RETURN VALUES**

If the system supports the given MAC policy, the value 1 is returned. If
the specified MAC policy is not supported, the value 0 is returned. If
an error occurs, the value −1 is returned.

| **ERRORS**
| [EINVAL]

The value of *policyname* is not valid.

[ENOMEM]

Insufficient memory was available to allocate internal storage.

**SEE ALSO**

mac(3), mac_free(3), mac_get(3), mac_prepare(3), mac_set(3),
mac_text(3), mac(4), mac(9)

**HISTORY**

Support for Mandatory Access Control was introduced in FreeBSD 5.0 as
part of the TrustedBSD Project.

BSD July 7, 2006 BSD

--------------
