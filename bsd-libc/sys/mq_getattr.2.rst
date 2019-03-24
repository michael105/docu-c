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

