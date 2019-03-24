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
