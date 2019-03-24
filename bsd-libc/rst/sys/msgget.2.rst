--------------

MSGGET(2) BSD System Calls Manual MSGGET(2)

**NAME**

**msgget** — get message queue

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/msg.h>**

*int*

**msgget**\ (*key_t key*, *int msgflg*);

**DESCRIPTION**

The **msgget**\ () function returns the message queue identifier
associated with *key*. A message queue identifier is a unique integer
greater than zero.

A message queue is created if either *key* is equal to IPC_PRIVATE, or
*key* does not have a message queue identifier associated with it, and
the IPC_CREAT bit is set in *msgflg*.

If a new message queue is created, the data structure associated with it
(the *msqid_ds* structure, see msgctl(2)) is initialized as follows:

**•**

*msg_perm.cuid* and *msg_perm.uid* are set to the effective uid of the
calling process.

**•**

*msg_perm.gid* and *msg_perm.cgid* are set to the effective gid of the
calling process.

**•**

*msg_perm.mode* is set to the lower 9 bits of *msgflg* which are set by
ORing these constants:

0400

Read access for user.

0200

Write access for user.

0040

Read access for group.

0020

Write access for group.

0004

Read access for other.

0002

Write access for other.

**•**

*msg_cbytes*, *msg_qnum*, *msg_lspid*, *msg_lrpid*, *msg_rtime*, and
*msg_stime* are set to 0.

**•**

*msg_qbytes* is set to the system wide maximum value for the number of
bytes in a queue (MSGMNB).

**•**

*msg_ctime* is set to the current time.

**RETURN VALUES**

Upon successful completion a positive message queue identifier is
returned. Otherwise, -1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EACCES]

A message queue is already associated with *key* and the caller has no
permission to access it.

[EEXIST]

Both IPC_CREAT and IPC_EXCL are set in *msgflg*, and a message queue is
already associated with *key*.

[ENOSPC]

A new message queue could not be created because the system limit for
the number of message queues has been reached.

[ENOENT]

IPC_CREAT was not set in *msgflg* and no message queue associated with
*key* was found.

**SEE ALSO**

msgctl(2), msgrcv(2), msgsnd(2)

**HISTORY**

Message queues appeared in the first release of AT&T System V UNIX.

BSD March 4, 2018 BSD

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

