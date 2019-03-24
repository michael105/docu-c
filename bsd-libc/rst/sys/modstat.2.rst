--------------

MODSTAT(2) BSD System Calls Manual MODSTAT(2)

**NAME**

**modstat** — get status of kernel module

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/module.h>**

*int*

**modstat**\ (*int modid*, *struct module_stat *stat*);

**DESCRIPTION**

The **modstat**\ () system call writes the info for the kernel module
referred to by *modid* into *stat*.

struct module_stat {

+-----------------------+-----------------------+-----------------------+
|                       | int version; /\* set  |                       |
|                       | to                    |                       |
|                       | sizeof(module_stat)   |                       |
|                       | \*/                   |                       |
+-----------------------+-----------------------+-----------------------+
|                       | char                  |                       |
|                       | name[MAXMODNAME];     |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int refs;             |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int id;               |                       |
+-----------------------+-----------------------+-----------------------+
|                       | modspecific_t data;   |                       |
+-----------------------+-----------------------+-----------------------+

| };
| typedef union modspecific {

+-----------------------------------+-----------------------------------+
|                                   | int intval;                       |
+-----------------------------------+-----------------------------------+
|                                   | u_int uintval;                    |
+-----------------------------------+-----------------------------------+
|                                   | long longval;                     |
+-----------------------------------+-----------------------------------+
|                                   | u_long ulongval;                  |
+-----------------------------------+-----------------------------------+

} modspecific_t;

version

This field is set to the size of the structure mentioned above by the
code calling **modstat**\ (), and not **modstat**\ () itself.

name

The name of the module referred to by *modid*.

refs

The number of modules referenced by *modid*.

id

The id of the module specified in *modid*.

data

Module specific data.

**RETURN VALUES**

The **modstat**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The information for the module referred to by *modid* is filled into the
structure pointed to by *stat* unless:

[ENOENT]

The module was not found (probably not loaded).

[EINVAL]

The version specified in the *version* field of stat is not the proper
version. You would need to rebuild world, the kernel, or your
application, if this error occurs, given that you did properly fill in
the *version* field.

[EFAULT]

There was a problem copying one, some, or all of the fields into *stat*
in the copyout(9) function.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), kldunload(2), modfind(2), modfnext(2), modnext(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD July 15, 2008 BSD

--------------
