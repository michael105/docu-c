--------------

SHMGET(2) BSD System Calls Manual SHMGET(2)

**NAME**

**shmget** — obtain a shared memory identifier

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/shm.h>**

*int*

**shmget**\ (*key_t key*, *size_t size*, *int flag*);

**DESCRIPTION**

Based on the values of *key* and *flag*, **shmget**\ () returns the
identifier of a newly created or previously existing shared memory
segment. The key is analogous to a filename: it provides a handle that
names an IPC object. There are three ways to specify a key:

**•**

IPC_PRIVATE may be specified, in which case a new IPC object will be
created.

**•**

An integer constant may be specified. If no IPC object corresponding to
*key* is specified and the IPC_CREAT bit is set in *flag*, a new one
will be created.

**•**

The ftok(3) may be used to generate a key from a pathname.

The mode of a newly created IPC object is determined by which are set by
ORing these constants into the *flag* argument:

0400

Read access for owner.

0200

Write access for owner.

0040

Read access for group.

0020

Write access for group.

0004

Read access for other.

0002

Write access for other.

When creating a new shared memory segment, *size* indicates the desired
size of the new segment in bytes. The size of the segment may be rounded
up to a multiple convenient to the kernel (i.e., the page size).

**RETURN VALUES**

Upon successful completion, **shmget**\ () returns the positive integer
identifier of a shared memory segment. Otherwise, -1 is returned and
*errno* set to indicate the error.

**ERRORS**

The **shmget**\ () system call will fail if:

[EINVAL]

Size specified is greater than the size of the previously existing
segment. Size specified is less than the system imposed minimum, or
greater than the system imposed maximum.

[ENOENT]

No shared memory segment was found matching *key*, and IPC_CREAT was not
specified.

[ENOSPC]

The kernel was unable to allocate enough memory to satisfy the request.

[EEXIST]

IPC_CREAT and IPC_EXCL were specified, and a shared memory segment
corresponding to *key* already exists.

**SEE ALSO**

shmat(2), shmctl(2), shmdt(2), ftok(3)

BSD March 4, 2018 BSD

--------------
