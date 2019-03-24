--------------

MQ_GETATTR(2) BSD System Calls Manual MQ_GETATTR(2)

**NAME**

**mq_getattr** — get message queue attributes (REALTIME)

**LIBRARY**

POSIX Real-time Library (librt, −lrt)

**SYNOPSIS**

**#include <mqueue.h>**

*int*

**mq_getattr**\ (*mqd_t mqdes*, *struct mq_attr *mqstat*);

**DESCRIPTION**

The **mq_getattr**\ () system call obtains status information and
attributes of the message queue and the open message queue description
associated with the message queue descriptor.

The *mqdes* argument specifies a message queue descriptor.

The results are returned in the *mq_attr* structure referenced by the
*mqstat* argument.

Upon return, the following members will have the values associated with
the open message queue description as set when the message queue was
opened and as modified by subsequent **mq_setattr**\ () calls:
*mq_flags*.

The following attributes of the message queue will be returned as set at
message queue creation: *mq_maxmsg*, *mq_msgsize*.

Upon return, the following members within the *mq_attr* structure
referenced by the *mqstat* argument will be set to the current state of
the message queue:

*mq_curmsgs*

The number of messages currently on the queue.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **mq_getattr**\ () system call will fail if:

[EBADF]

The *mqdes* argument is not a valid message queue descriptor.

**SEE ALSO**

mq_open(2), mq_send(2), mq_setattr(2), mq_timedsend(2)

**STANDARDS**

The **mq_getattr**\ () system call conforms to IEEE Std 1003.1-2004
(‘‘POSIX.1’’).

**HISTORY**

Support for POSIX message queues first appeared in FreeBSD 7.0.

**COPYRIGHT**

Portions of this text are reprinted and reproduced in electronic form
from IEEE Std 1003.1, 2004 Edition, Standard for Information Technology
-- Portable Operating System Interface (POSIX), The Open Group Base
Specifications Issue 6, Copyright (C) 2001-2004 by the Institute of
Electrical and Electronics Engineers, Inc and The Open Group. In the
event of any discrepancy between this version and the original IEEE and
The Open Group Standard, the original IEEE and The Open Group Standard
is the referee document. The original Standard can be obtained online at
http://www.opengroup.org/unix/online.html.

BSD February 21, 2014 BSD

--------------
