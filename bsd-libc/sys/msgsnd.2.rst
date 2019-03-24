--------------

MSGSND(2) BSD System Calls Manual MSGSND(2)

**NAME**

**msgsnd** — send a message to a message queue

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>**

*int*

**msgsnd**\ (*int msqid*, *const void *msgp*, *size_t msgsz*,
*int msgflg*);

**DESCRIPTION**

The **msgsnd**\ () function sends a message to the message queue
specified in *msqid*. The *msgp* argument points to a structure
containing the message. This structure should consist of the following
members:

| long mtype; /\* message type \*/
| char mtext[1]; /\* body of message \*/

*mtype* is an integer greater than 0 that can be used for selecting
messages (see msgrcv(2)), *mtext* is an array of *msgsz* bytes. The
argument *msgsz* can range from 0 to a system-imposed maximum, MSGMAX.

If the number of bytes already on the message queue plus *msgsz* is
bigger than the maximum number of bytes on the message queue
(*msg_qbytes*, see msgctl(2)), or the number of messages on all queues
system-wide is already equal to the system limit, *msgflg* determines
the action of **msgsnd**\ (). If *msgflg* has IPC_NOWAIT mask set in it,
the call will return immediately. If *msgflg* does not have IPC_NOWAIT
set in it, the call will block until:

**•**

The condition which caused the call to block does no longer exist. The
message will be sent.

**•**

The message queue is removed, in which case -1 will be returned, and
*errno* is set to EINVAL.

**•**

The caller catches a signal. The call returns with *errno* set to EINTR.

After a successful call, the data structure associated with the message
queue is updated in the following way:

**•**

*msg_cbytes* is incremented by the size of the message.

**•**

*msg_qnum* is incremented by 1.

**•**

*msg_lspid* is set to the pid of the calling process.

**•**

*msg_stime* is set to the current time.

**RETURN VALUES**

The **msgsnd**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **msgsnd**\ () function will fail if:

[EINVAL]

The *msqid* argument is not a valid message queue identifier.

The message queue was removed while **msgsnd**\ () was waiting for a
resource to become available in order to deliver the message.

The *msgsz* argument is greater than *msg_qbytes*.

The *mtype* argument is not greater than 0.

[EACCES]

The calling process does not have write access to the message queue.

[EAGAIN]

There was no space for this message either on the queue, or in the whole
system, and IPC_NOWAIT was set in *msgflg*.

[EFAULT]

The *msgp* argument points to an invalid address.

[EINTR]

The system call was interrupted by the delivery of a signal.

**HISTORY**

Message queues appeared in the first release of AT&T Unix System V.

**BUGS**

NetBSD and FreeBSD do not define the EIDRM error value, which should be
used in the case of a removed message queue.

BSD July 9, 2009 BSD

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

