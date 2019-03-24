--------------

KLDSTAT(2) BSD System Calls Manual KLDSTAT(2)

**NAME**

**kldstat** — get status of kld file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldstat**\ (*int fileid*, *struct kld_file_stat *stat*);

**DESCRIPTION**

The **kldstat**\ () system call writes the info for the file referred to
by *fileid* into *stat*.

struct kld_file_stat {

+-----------------------+-----------------------+-----------------------+
|                       | int version; /\* set  |                       |
|                       | to sizeof(struct      |                       |
|                       | kld_file_stat) \*/    |                       |
+-----------------------+-----------------------+-----------------------+
|                       | char                  |                       |
|                       | name[MAXPATHLEN];     |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int refs;             |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int id;               |                       |
+-----------------------+-----------------------+-----------------------+
|                       | caddr_t address;      |                       |
+-----------------------+-----------------------+-----------------------+
|                       | size_t size;          |                       |
+-----------------------+-----------------------+-----------------------+
|                       | char                  |                       |
|                       | pathname[MAXPATHLEN]; |                       |
+-----------------------+-----------------------+-----------------------+

};

version

This field is set to the size of the structure mentioned above by the
code calling **kldstat**\ (), and not **kldstat**\ () itself.

name

The name of the file referred to by *fileid*.

refs

The number of modules referenced by *fileid*.

id

The id of the file specified in *fileid*.

address

The load address of the kld file.

size

The amount of memory in bytes allocated by the file.

pathname

The full name of the file referred to by *fileid*, including the path.

**RETURN VALUES**

The **kldstat**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The information for the file referred to by *fileid* is filled into the
structure pointed to by *stat* unless:

[ENOENT]

The file was not found (probably not loaded).

[EINVAL]

The version specified in the *version* field of stat is not the proper
version. You would need to rebuild world, the kernel, or your
application, if this error occurs, given that you did properly fill in
the *version* field.

[EFAULT]

There was a problem copying one, some, or all of the fields into *stat*
in the copyout(9) function.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldsym(2),
kldunload(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

**BUGS**

The pathname may not be accurate if the file system mounts have changed
since the module was loaded, or if this function is called within a
chrooted environment.

BSD March 28, 2012 BSD

--------------
