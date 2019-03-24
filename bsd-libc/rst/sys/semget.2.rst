--------------

SEMGET(2) BSD System Calls Manual SEMGET(2)

**NAME**

**semget** — obtain a semaphore id

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/sem.h>**

*int*

**semget**\ (*key_t key*, *int nsems*, *int flag*);

**DESCRIPTION**

Based on the values of *key* and *flag*, **semget**\ () returns the
identifier of a newly created or previously existing set of semaphores.
The key is analogous to a filename: it provides a handle that names an
IPC object. There are three ways to specify a key:

**•**

IPC_PRIVATE may be specified, in which case a new IPC object will be
created.

**•**

An integer constant may be specified. If no IPC object corresponding to
*key* is specified and the IPC_CREAT bit is set in *flag*, a new one
will be created.

**•**

The ftok(3) function may be used to generate a key from a pathname.

The mode of a newly created IPC object is determined by ORing these
constants into the *flag* argument:

0400

Read access for user.

0200

Alter access for user.

0040

Read access for group.

0020

Alter access for group.

0004

Read access for other.

0002

Alter access for other.

If a new set of semaphores is being created, *nsems* is used to indicate
the number of semaphores the set should contain. Otherwise, *nsems* may
be specified as 0.

**RETURN VALUES**

The **semget**\ () system call returns the id of a semaphore set if
successful; otherwise, -1 is returned and *errno* is set to indicate the
error.

**ERRORS**

The **semget**\ () system call will fail if:

[EACCES]

Access permission failure.

[EEXIST]

IPC_CREAT and IPC_EXCL were specified, and a semaphore set corresponding
to *key* already exists.

[EINVAL]

The number of semaphores requested exceeds the system imposed maximum
per set.

[EINVAL]

A semaphore set corresponding to *key* already exists and contains fewer
semaphores than *nsems*.

[EINVAL]

A semaphore set corresponding to *key* does not exist and *nsems* is 0
or negative.

[ENOSPC]

Insufficiently many semaphores are available.

[ENOSPC]

The kernel could not allocate a *struct semid_ds*.

[ENOENT]

No semaphore set was found corresponding to *key*, and IPC_CREAT was not
specified.

**SEE ALSO**

semctl(2), semop(2), ftok(3)

BSD March 4, 2018 BSD

--------------
