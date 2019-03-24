--------------

MQ_CLOSE(2) BSD System Calls Manual MQ_CLOSE(2)

**NAME**

**mq_close** — close a message queue (REALTIME)

**LIBRARY**

POSIX Real-time Library (librt, −lrt)

**SYNOPSIS**

**#include <mqueue.h>**

*int*

**mq_close**\ (*mqd_t mqdes*);

**DESCRIPTION**

The **mq_close**\ () system call removes the association between the
message queue descriptor, *mqdes*, and its message queue. The results of
using this message queue descriptor after successful return from this
**mq_close**\ (), and until the return of this message queue descriptor
from a subsequent **mq_open**\ (), are undefined.

If the process has successfully attached a notification request to the
message queue via this *mqdes*, this attachment will be removed, and the
message queue is available for another process to attach for
notification.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **mq_close**\ () system call will fail if:

[EBADF]

The *mqdes* argument is not a valid message queue descriptor.

**SEE ALSO**

mq_open(2), mq_unlink(2)

**STANDARDS**

The **mq_close**\ () system call conforms to IEEE Std 1003.1-2004
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

BSD November 29, 2005 BSD

--------------
