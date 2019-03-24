--------------

POSIX1E(3) BSD Library Functions Manual POSIX1E(3)

**NAME**

**posix1e** — introduction to the POSIX.1e security API

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>
#include <sys/mac.h>**

**DESCRIPTION**

POSIX.1e describes five security extensions to the POSIX.1 API: Access
Control Lists (ACLs), Auditing, Capabilities, Mandatory Access Control,
and Information Flow Labels. While IEEE POSIX.1e D17 specification has
not been standardized, several of its interfaces are widely used.

FreeBSD implements POSIX.1e interface for access control lists,
described in acl(3), and supports ACLs on the ffs(7) file system; ACLs
must be administratively enabled using tunefs(8).

FreeBSD implements a POSIX.1e-like mandatory access control interface,
described in mac(3), although with a number of extensions and important
semantic differences.

FreeBSD does not implement the POSIX.1e audit, privilege (capability),
or information flow label APIs. However, FreeBSD does implement the
libbsm(3) audit API. It also provides capsicum(4), a lightweight OS
capability and sandbox framework implementing a hybrid capability system
model.

**ENVIRONMENT**

POSIX.1e assigns security attributes to all objects, extending the
security functionality described in POSIX.1. These additional attributes
store fine-grained discretionary access control information and
mandatory access control labels; for files, they are stored in extended
attributes, described in extattr(3).

POSIX.2c describes a set of userland utilities for manipulating these
attributes, including getfacl(1) and setfacl(1) for access control
lists, and getfmac(8) and setfmac(8) for mandatory access control
labels.

**SEE ALSO**

getfacl(1), setfacl(1), extattr(2), acl(3), extattr(3), libbsm(3),
libcasper(3), mac(3), capsicum(4), ffs(7), getfmac(8), setfmac(8),
tunefs(8), acl(9), extattr(9), mac(9)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0; most features were
available as of FreeBSD 5.0.

**AUTHORS**

| Robert N M Watson
| Chris D. Faulhaber
| Thomas Moestl
| Ilmar S Habibulin

BSD February 25, 2016 BSD

--------------
