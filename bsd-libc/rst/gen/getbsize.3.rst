--------------

GETBSIZE(3) BSD Library Functions Manual GETBSIZE(3)

**NAME**

**getbsize** — get preferred block size

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*char \**

**getbsize**\ (*int *headerlenp*, *long *blocksizep*);

**DESCRIPTION**

The **getbsize**\ () function returns a preferred block size for
reporting by system utilities df(1), du(1), ls(1) and systat(1), based
on the value of the BLOCKSIZE environment variable. BLOCKSIZE may be
specified directly in bytes, or in multiples of a kilobyte by specifying
a number followed by ‘‘K’’ or ‘‘k’’, in multiples of a megabyte by
specifying a number followed by ‘‘M’’ or ‘‘m’’ or in multiples of a
gigabyte by specifying a number followed by ‘‘G’’ or ‘‘g’’. Multiples
must be integers.

Valid values of BLOCKSIZE are 512 bytes to 1 gigabyte. Sizes less than
512 bytes are rounded up to 512 bytes, and sizes greater than 1 GB are
rounded down to 1 GB. In each case **getbsize**\ () produces a warning
message via warnx(3).

The **getbsize**\ () function returns a pointer to a null-terminated
string describing the block size, something like ‘‘1K-blocks’’. The
memory referenced by *headerlenp* is filled in with the length of the
string (not including the terminating null). The memory referenced by
*blocksizep* is filled in with block size, in bytes.

**SEE ALSO**

df(1), du(1), ls(1), systat(1), environ(7)

**HISTORY**

The **getbsize**\ () function first appeared in 4.4BSD.

BSD June 11, 2017 BSD

--------------
