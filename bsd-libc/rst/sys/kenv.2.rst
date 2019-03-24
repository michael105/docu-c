--------------

KENV(2) BSD System Calls Manual KENV(2)

**NAME**

**kenv** — kernel environment

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <kenv.h>**

*int*

**kenv**\ (*int action*, *const char *name*, *char *value*, *int len*);

**DESCRIPTION**

The **kenv**\ () system call manipulates kernel environment variables.
It supports the well known userland actions of getting, setting and
unsetting environment variables, as well as the ability to dump all of
the entries in the kernel environment.

The *action* argument can be one of the following:

KENV_GET

Get the *value* of the variable with the given *name*. The size of the
*value* buffer is given by *len*, which should be at least KENV_MVALLEN
+ 1 bytes to avoid truncation and to ensure NUL termination.

KENV_SET

Set or add a variable. The *name* and *value* are limited to
KENV_MNAMELEN and KENV_MVALLEN characters, respectively (not including
the NUL terminator.) The *len* argument indicates the length of the
*value* and must include the NUL terminator. This option is only
available to the superuser.

KENV_UNSET

Unset the variable with the given *name*. The *value* and *len*
arguments are ignored. This option is only available to the superuser.

KENV_DUMP

Dump as much of the kernel environment as will fit in *value*, whose
size is given in *len*. If *value* is NULL, **kenv**\ () will return the
number of bytes required to copy out the entire environment. The *name*
is ignored.

**RETURN VALUES**

The **kenv**\ () system call returns 0 if successful in the case of
KENV_SET and KENV_UNSET, and the number of bytes copied into *value* in
the case of KENV_DUMP and KENV_GET. If an error occurs, a value of −1 is
returned and the global variable *errno* is set to indicate the error.

**ERRORS**

The **kenv**\ () system call will fail if:

[EINVAL]

The *action* argument is not a valid option, or the length of the
*value* is less than 1 for a KENV_SET.

[ENOENT]

No value could be found for *name* for a KENV_GET or KENV_UNSET.

[EPERM]

A user other than the superuser attempted to set or unset a kernel
environment variable.

[EFAULT]

A bad address was encountered while attempting to copy in user arguments
or copy out value(s).

[ENAMETOOLONG]

The *name* or the *value* is longer than KENV_MNAMELEN or KENV_MVALLEN
characters, respectively, or *len* did not include the NUL terminator
for a KENV_SET.

**SEE ALSO**

kenv(1)

**AUTHORS**

This manual page was written by Chad David <*davidc@FreeBSD.org*>.

The **kenv**\ () system call was written by Maxime Henrion
<*mux@FreeBSD.org*>.

BSD February 20, 2017 BSD

--------------
