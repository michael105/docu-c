--------------

TCSENDBREAK(3) BSD Library Functions Manual TCSENDBREAK(3)

**NAME**

**tcsendbreak**, **tcdrain**, **tcflush**, **tcflow** — line control
functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <termios.h>**

*int*

**tcdrain**\ (*int fd*);

*int*

**tcflow**\ (*int fd*, *int action*);

*int*

**tcflush**\ (*int fd*, *int action*);

*int*

**tcsendbreak**\ (*int fd*, *int len*);

**DESCRIPTION**

The **tcdrain**\ () function waits until all output written to the
terminal referenced by *fd* has been transmitted to the terminal.

The **tcflow**\ () function suspends transmission of data to or the
reception of data from the terminal referenced by *fd* depending on the
value of *action*. The value of *action* must be one of the following:

*TCOOFF*

Suspend output.

*TCOON*

Restart suspended output.

*TCIOFF*

Transmit a STOP character, which is intended to cause the terminal to
stop transmitting data to the system. (See the description of IXOFF in
the ‘Input Modes’ section of termios(4)).

*TCION*

Transmit a START character, which is intended to cause the terminal to
start transmitting data to the system. (See the description of IXOFF in
the ‘Input Modes’ section of termios(4)).

The **tcflush**\ () function discards any data written to the terminal
referenced by *fd* which has not been transmitted to the terminal, or
any data received from the terminal but not yet read, depending on the
value of *action*. The value of *action* must be one of the following:

*TCIFLUSH*

Flush data received but not read.

*TCOFLUSH*

Flush data written but not transmitted.

*TCIOFLUSH*

Flush both data received but not read and data written but not
transmitted.

The **tcsendbreak**\ () function transmits a continuous stream of
zero-valued bits for four-tenths of a second to the terminal referenced
by *fd*. The *len* argument is ignored in this implementation.

**RETURN VALUES**

Upon successful completion, all of these functions return a value of
zero.

**ERRORS**

If any error occurs, a value of -1 is returned and the global variable
*errno* is set to indicate the error, as follows:

[EBADF]

The *fd* argument is not a valid file descriptor.

[EINVAL]

The *action* argument is not a proper value.

[ENOTTY]

The file associated with *fd* is not a terminal.

[EINTR]

A signal interrupted the **tcdrain**\ () function.

[EWOULDBLOCK]

The configured timeout expired before the **tcdrain**\ () function could
write all buffered output.

**SEE ALSO**

tcsetattr(3), termios(4), tty(4), comcontrol(8)

**STANDARDS**

The **tcsendbreak**\ (), **tcflush**\ () and **tcflow**\ () functions
are expected to be compliant with the IEEE Std 1003.1-1988 (‘‘POSIX.1’’)
specification.

The **tcdrain**\ () function is expected to be compliant with IEEE Std
1003.1-1988 (‘‘POSIX.1’’) when the drain wait value is set to zero with
comcontrol(8), or with ioctl(2) *TIOCSDRAINWAIT*, or with sysctl(8)
*kern.tty_drainwait*. A non-zero drain wait value can result in
**tcdrain**\ () returning *EWOULDBLOCK* without writing all output. The
default value for *kern.tty_drainwait* is 300 seconds.

BSD January 11, 2017 BSD

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

