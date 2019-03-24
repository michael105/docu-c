--------------

SETMODE(3) BSD Library Functions Manual SETMODE(3)

**NAME**

**getmode**, **setmode** — modify mode bits

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*mode_t*

**getmode**\ (*const void *set*, *mode_t mode*);

*void \**

**setmode**\ (*const char *mode_str*);

**DESCRIPTION**

The **getmode**\ () function returns a copy of the file permission bits
*mode* as altered by the values pointed to by *set*. While only the mode
bits are altered, other parts of the file mode may be examined.

The **setmode**\ () function takes an absolute (octal) or symbolic
value, as described in chmod(1), as an argument and returns a pointer to
mode values to be supplied to **getmode**\ (). Because some of the
symbolic values are relative to the file creation mask, **setmode**\ ()
may call umask(2). If this occurs, the file creation mask will be
restored before **setmode**\ () returns. If the calling program changes
the value of its file creation mask after calling **setmode**\ (),
**setmode**\ () must be called again if **getmode**\ () is to modify
future file modes correctly.

If the mode passed to **setmode**\ () is invalid or if memory cannot be
allocated for the return value, **setmode**\ () returns NULL.

The value returned from **setmode**\ () is obtained from **malloc**\ ()
and should be returned to the system with **free**\ () when the program
is done with it, generally after a call to **getmode**\ ().

**ERRORS**

The **setmode**\ () function may fail and set errno for any of the
errors specified for the library routine malloc(3) or strtol(3). In
addition, **setmode**\ () will fail and set *errno* to:

[EINVAL]

The *mode* argument does not represent a valid mode.

**SEE ALSO**

chmod(1), stat(2), umask(2), malloc(3)

**HISTORY**

The **getmode**\ () and **setmode**\ () functions first appeared in
4.4BSD.

BSD February 22, 2015 BSD

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

