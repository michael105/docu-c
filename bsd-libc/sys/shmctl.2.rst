--------------

SHMCTL(2) BSD System Calls Manual SHMCTL(2)

**NAME**

**shmctl** — shared memory control

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>**

*int*

**shmctl**\ (*int shmid*, *int cmd*, *struct shmid_ds *buf*);

**DESCRIPTION**

Performs the action specified by *cmd* on the shared memory segment
identified by *shmid*:

IPC_STAT

Fetch the segment’s *struct shmid_ds*, storing it in the memory pointed
to by *buf*.

IPC_SET

Changes the *shm_perm.uid*, *shm_perm.gid*, and *shm_perm.mode* members
of the segment’s *struct shmid_ds* to match those of the struct pointed
to by *buf*. The calling process’s effective uid must match either
*shm_perm.uid* or *shm_perm.cuid*, or it must have superuser privileges.

IPC_RMID

Removes the segment from the system. The removal will not take effect
until all processes having attached the segment have exited. For the
operation to succeed, the calling process’s effective uid must match
*shm_perm.uid* or *shm_perm.cuid*, or the process must have superuser
privileges. If the *kern.ipc.shm_allow_removed* sysctl(3) variable is
set to 0, once the IPC_RMID operation has taken place, no further
processes will be allowed to attach the segment.

The *shmid_ds* structure is defined as follows:

| struct shmid_ds {
| struct ipc_perm shm_perm; /\* operation permission structure \*/
| size_t shm_segsz; /\* size of segment in bytes \*/
| pid_t shm_lpid; /\* process ID of last shared memory op \*/
| pid_t shm_cpid; /\* process ID of creator \*/
| int shm_nattch; /\* number of current attaches \*/
| time_t shm_atime; /\* time of last shmat() \*/
| time_t shm_dtime; /\* time of last shmdt() \*/
| time_t shm_ctime; /\* time of last change by shmctl() \*/
| };

**RETURN VALUES**

The **shmctl**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **shmctl**\ () system call will fail if:

[EINVAL]

Invalid operation, or no shared memory segment was found corresponding
to *shmid*.

[EPERM]

The calling process’s effective uid does not match the uid of the shared
memory segment’s owner or creator.

[EACCES]

Permission denied due to mismatch between operation and mode of shared
memory segment.

**SEE ALSO**

shmat(2), shmdt(2), shmget(2), ftok(3)

BSD October 10, 2015 BSD

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

