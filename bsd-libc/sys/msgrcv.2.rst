--------------

MSGRCV(2) BSD System Calls Manual MSGRCV(2)

**NAME**

**msgrcv** — receive a message from a message queue

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>**

*ssize_t*

**msgrcv**\ (*int msqid*, *void *msgp*, *size_t msgsz*, *long msgtyp*,
*int msgflg*);

**DESCRIPTION**

The **msgrcv**\ () function receives a message from the message queue
specified in *msqid*, and places it into the structure pointed to by
*msgp*. This structure should consist of the following members:

| long mtype; /\* message type \*/
| char mtext[1]; /\* body of message \*/

*mtype* is an integer greater than 0 that can be used for selecting
messages, *mtext* is an array of bytes, with a size up to that of the
system limit (MSGMAX).

The value of *msgtyp* has one of the following meanings:

**•**

The *msgtyp* argument is greater than 0. The first message of type
*msgtyp* will be received.

**•**

The *msgtyp* argument is equal to 0. The first message on the queue will
be received.

**•**

The *msgtyp* argument is less than 0. The first message of the lowest
message type that is less than or equal to the absolute value of
*msgtyp* will be received.

The *msgsz* argument specifies the maximum length of the requested
message. If the received message has a length greater than *msgsz* it
will be silently truncated if the MSG_NOERROR flag is set in *msgflg*,
otherwise an error will be returned.

If no matching message is present on the message queue specified by
*msqid*, the behavior of **msgrcv**\ () depends on whether the
IPC_NOWAIT flag is set in *msgflg* or not. If IPC_NOWAIT is set,
**msgrcv**\ () will immediately return a value of -1, and set *errno* to
ENOMSG. If IPC_NOWAIT is not set, the calling process will be blocked
until:

**•**

A message of the requested type becomes available on the message queue.

**•**

The message queue is removed, in which case -1 will be returned, and
*errno* set to EINVAL.

**•**

A signal is received and caught. -1 is returned, and *errno* set to
EINTR.

If a message is successfully received, the data structure associated
with *msqid* is updated as follows:

**•**

*msg_cbytes* is decremented by the size of the message.

**•**

*msg_lrpid* is set to the pid of the caller.

**•**

*msg_lrtime* is set to the current time.

**•**

*msg_qnum* is decremented by 1.

**RETURN VALUES**

Upon successful completion, **msgrcv**\ () returns the number of bytes
received into the *mtext* field of the structure pointed to by *msgp*.
Otherwise, -1 is returned, and *errno* set to indicate the error.

**ERRORS**

The **msgrcv**\ () function will fail if:

[EINVAL]

The *msqid* argument is not a valid message queue identifier.

The message queue was removed while **msgrcv**\ () was waiting for a
message of the requested type to become available on it.

The *msgsz* argument is less than 0.

[E2BIG]

A matching message was received, but its size was greater than *msgsz*
and the MSG_NOERROR flag was not set in *msgflg*.

[EACCES]

The calling process does not have read access to the message queue.

[EFAULT]

The *msgp* argument points to an invalid address.

[EINTR]

The system call was interrupted by the delivery of a signal.

[ENOMSG]

There is no message of the requested type available on the message
queue, and IPC_NOWAIT is set in *msgflg*.

**SEE ALSO**

msgctl(2), msgget(2), msgsnd(2)

**HISTORY**

Message queues appeared in the first release of AT&T System V UNIX.

BSD July 28, 2016 BSD

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

