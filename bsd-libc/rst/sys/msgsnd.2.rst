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
