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

