--------------

SEMCTL(2) BSD System Calls Manual SEMCTL(2)

**NAME**

**semctl** — control operations on a semaphore set

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>**

*int*

**semctl**\ (*int semid*, *int semnum*, *int cmd*, *...*);

**DESCRIPTION**

The **semctl**\ () system call performs the operation indicated by *cmd*
on the semaphore set indicated by *semid*. A fourth argument, a *union
semun arg*, is required for certain values of *cmd*. For the commands
that use the *arg* argument, *union semun* must be defined as follows:

| union semun {
| int val; /\* value for SETVAL \*/
| struct semid_ds \*buf; /\* buffer for IPC_STAT & IPC_SET \*/
| u_short \*array; /\* array for GETALL & SETALL \*/
| };
| Non-portable software may define \_WANT_SEMUN before including
  *sys/sem.h* to use the system definition of *union semun*.

Commands are performed as follows:

IPC_STAT

Fetch the semaphore set’s *struct semid_ds*, storing it in the memory
pointed to by *arg.buf*.

IPC_SET

Changes the *sem_perm.uid*, *sem_perm.gid*, and *sem_perm.mode* members
of the semaphore set’s *struct semid_ds* to match those of the struct
pointed to by *arg.buf*. The calling process’s effective uid must match
either *sem_perm.uid* or *sem_perm.cuid*, or it must have superuser
privileges.

IPC_RMID

Immediately removes the semaphore set from the system. The calling
process’s effective uid must equal the semaphore set’s *sem_perm.uid* or
*sem_perm.cuid*, or the process must have superuser privileges.

GETVAL

Return the value of semaphore number *semnum*.

SETVAL

Set the value of semaphore number *semnum* to *arg.val*. Outstanding
adjust on exit values for this semaphore in any process are cleared.

GETPID

Return the pid of the last process to perform an operation on semaphore
number *semnum*.

GETNCNT

Return the number of processes waiting for semaphore number *semnum*\ ’s
value to become greater than its current value.

GETZCNT

Return the number of processes waiting for semaphore number *semnum*\ ’s
value to become 0.

GETALL

Fetch the value of all of the semaphores in the set into the array
pointed to by *arg.array*.

SETALL

Set the values of all of the semaphores in the set to the values in the
array pointed to by *arg.array*. Outstanding adjust on exit values for
all semaphores in this set, in any process are cleared.

The *struct semid_ds* is defined as follows:

| struct semid_ds {
| struct ipc_perm sem_perm; /\* operation permission struct \*/
| struct sem \*__sem_base; /\* kernel data, don’t use \*/
| u_short sem_nsems; /\* number of sems in set \*/
| time_t sem_otime; /\* last operation time \*/
| time_t sem_ctime; /\* last change time \*/
| /\* Times measured in secs since \*/
| /\* 00:00:00 GMT, Jan. 1, 1970 \*/
| };

**RETURN VALUES**

On success, when *cmd* is one of GETVAL, GETPID, GETNCNT or GETZCNT,
**semctl**\ () returns the corresponding value; otherwise, 0 is
returned. On failure, -1 is returned, and *errno* is set to indicate the
error.

**ERRORS**

The **semctl**\ () system call will fail if:

[EINVAL]

No semaphore set corresponds to *semid*.

[EINVAL]

The *semnum* argument is not in the range of valid semaphores for given
semaphore set.

[EPERM]

The calling process’s effective uid does not match the uid of the
semaphore set’s owner or creator.

[EACCES]

Permission denied due to mismatch between operation and mode of
semaphore set.

[ERANGE]

SETVAL or SETALL attempted to set a semaphore outside the allowable
range [0 .. SEMVMX].

**SEE ALSO**

semget(2), semop(2)

**BUGS**

SETALL may update some semaphore elements before returning an error.

BSD February 23, 2018 BSD

--------------

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

