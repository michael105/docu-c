--------------

MINHERIT(2) BSD System Calls Manual MINHERIT(2)

**NAME**

**minherit** — control the inheritance of pages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**minherit**\ (*void *addr*, *size_t len*, *int inherit*);

**DESCRIPTION**

The **minherit**\ () system call changes the specified pages to have the
inheritance characteristic *inherit*. Not all implementations will
guarantee that the inheritance characteristic can be set on a page
basis; the granularity of changes may be as large as an entire region.
FreeBSD is capable of adjusting inheritance characteristics on a page
basis. Inheritance only effects children created by **fork**\ (). It has
no effect on **exec**\ (). exec’d processes replace their address space
entirely. This system call also has no effect on the parent’s address
space (other than to potentially share the address space with its
children).

Inheritance is a rather esoteric feature largely superseded by the
MAP_SHARED feature of **mmap**\ (). However, it is possible to use
**minherit**\ () to share a block of memory between parent and child
that has been mapped MAP_PRIVATE. That is, modifications made by parent
or child are shared but the original underlying file is left untouched.

INHERIT_SHARE

This option causes the address space in question to be shared between
parent and child. It has no effect on how the original underlying
backing store was mapped.

INHERIT_NONE

This option prevents the address space in question from being inherited
at all. The address space will be unmapped in the child.

INHERIT_COPY

This option causes the child to inherit the address space as
copy-on-write. This option also has an unfortunate side effect of
causing the parent address space to become copy-on-write when the parent
forks. If the original mapping was MAP_SHARED, it will no longer be
shared in the parent after the parent forks and there is no way to get
the previous shared-backing-store mapping without unmapping and
remapping the address space in the parent.

INHERIT_ZERO

This option causes the address space in question to be mapped as new
anonymous pages, which would be initialized to all zero bytes, in the
child process.

**RETURN VALUES**

The **minherit**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **minherit**\ () system call will fail if:

[EINVAL]

The virtual address range specified by the *addr* and *len* arguments is
not valid.

[EACCES]

The flags specified by the *inherit* argument were not valid for the
pages specified by the *addr* and *len* arguments.

**SEE ALSO**

fork(2), madvise(2), mincore(2), mprotect(2), msync(2), munmap(2),
rfork(2)

**HISTORY**

The **minherit**\ () system call first appeared in OpenBSD and then in
FreeBSD 2.2.

The INHERIT_ZERO support first appeared in OpenBSD 5.6 and then in
FreeBSD 12.0.

**BUGS**

Once you set inheritance to MAP_PRIVATE or MAP_SHARED, there is no way
to recover the original copy-on-write semantics short of unmapping and
remapping the area.

BSD March 15, 2017 BSD

--------------
