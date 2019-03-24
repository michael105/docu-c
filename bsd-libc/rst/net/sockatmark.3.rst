--------------

SOCKATMARK(3) BSD Library Functions Manual SOCKATMARK(3)

**NAME**

**sockatmark** — determine whether the read pointer is at the OOB mark

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/socket.h>**

*int*

**sockatmark**\ (*int s*);

**DESCRIPTION**

To find out if the read pointer is currently pointing at the mark in the
data stream, the **sockatmark**\ () function is provided. If
**sockatmark**\ () returns 1, the next read will return data after the
mark. Otherwise (assuming out of band data has arrived), the next read
will provide data sent by the client prior to transmission of the out of
band signal. The routine used in the remote login process to flush
output on receipt of an interrupt or quit signal is shown below. It
reads the normal data up to the mark (to discard it), then reads the
out-of-band byte.

| #include <sys/socket.h>
| ...
| oob()
| {

+-------------+-------------+-------------+-------------+-------------+
|             | int out =   |             |             |             |
|             | FWRITE,     |             |             |             |
|             | mark;       |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | char        |             |             |             |
|             | waste[BUFSI |             |             |             |
|             | Z];         |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | /\* flush   |             |             |             |
|             | local       |             |             |             |
|             | terminal    |             |             |             |
|             | output \*/  |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | ioctl(1,    |             |             |             |
|             | TIOCFLUSH,  |             |             |             |
|             | (char       |             |             |             |
|             | \*)&out);   |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | for (;;) {  |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | if ((mark = |             |             |
|             |             | sockatmark( |             |             |
|             |             | rem))       |             |             |
|             |             | < 0) {      |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             |             | perror("soc |             |
|             |             |             | katmark");  |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             |             | break;      |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | }           |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | if (mark)   |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             |             | break;      |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | (void)      |             |             |
|             |             | read(rem,   |             |             |
|             |             | waste,      |             |             |
|             |             | sizeof      |             |             |
|             |             | (waste));   |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | }           |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | if          |             |             |             |
|             | (recv(rem,  |             |             |             |
|             | &mark, 1,   |             |             |             |
|             | MSG_OOB) <  |             |             |             |
|             | 0) {        |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | perror("rec |             |             |
|             |             | v");        |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             |             | ...         |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | }           |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | ...         |             |             |             |
+-------------+-------------+-------------+-------------+-------------+

}

**RETURN VALUES**

Upon successful completion, the **sockatmark**\ () function returns the
value 1 if the read pointer is pointing at the OOB mark, 0 if it is not.
Otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sockatmark**\ () call fails if:

[EBADF]

The *s* argument is not a valid descriptor.

[ENOTTY]

The *s* argument is a descriptor for a file, not a socket.

**SEE ALSO**

recv(2), send(2)

**HISTORY**

The **sockatmark**\ () function was introduced by IEEE Std 1003.1-2001
(‘‘POSIX.1’’), to standardize the historical SIOCATMARK ioctl(2). The
ENOTTY error instead of the usual ENOTSOCK is to match the historical
behavior of SIOCATMARK.

BSD October 13, 2002 BSD

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

