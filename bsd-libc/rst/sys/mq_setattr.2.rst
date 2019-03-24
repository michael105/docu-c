--------------

MQ_SETATTR(2) BSD System Calls Manual MQ_SETATTR(2)

**NAME**

**mq_setattr** — set message queue attributes (REALTIME)

**LIBRARY**

POSIX Real-time Library (librt, −lrt)

**SYNOPSIS**

**#include <mqueue.h>**

*int*

**mq_setattr**\ (*mqd_t mqdes*, *const struct mq_attr *restrict mqstat*,
*struct mq_attr *restrict omqstat*);

**DESCRIPTION**

The **mq_setattr**\ () system call sets attributes associated with the
open message queue description referenced by the message queue
descriptor specified by *mqdes*. The message queue attributes
corresponding to the following members defined in the *mq_attr*
structure will be set to the specified values upon successful completion
of **mq_setattr**\ ():

*mq_flags*

The value of this member is zero or O_NONBLOCK.

The values of the *mq_maxmsg*, *mq_msgsize*, and *mq_curmsgs* members of
the *mq_attr* structure are ignored by **mq_setattr**\ ().

**RETURN VALUES**

Upon successful completion, the function returns a value of zero and the
attributes of the message queue will have been changed as specified.

Otherwise, the message queue attributes are unchanged, and the function
returns a value of −1 and sets the global variable *errno* to indicate
the error.

**ERRORS**

The **mq_setattr**\ () system call will fail if:

[EBADF]

The *mqdes* argument is not a valid message queue descriptor.

**SEE ALSO**

mq_open(2), mq_send(2), mq_timedsend(2)

**STANDARDS**

The **mq_setattr**\ () system call conforms to IEEE Std 1003.1-2004
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

BSD May 17, 2011 BSD

--------------
