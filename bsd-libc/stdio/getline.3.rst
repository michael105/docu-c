--------------

GETLINE(3) BSD Library Functions Manual GETLINE(3)

**NAME**

**getdelim**, **getline** — get a line from a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*ssize_t*

**getdelim**\ (*char ** restrict linep*, *size_t * restrict linecapp*,
*int delimiter*, *FILE * restrict stream*);

*ssize_t*

**getline**\ (*char ** restrict linep*, *size_t * restrict linecapp*,
*FILE * restrict stream*);

**DESCRIPTION**

The **getdelim**\ () function reads a line from *stream*, delimited by
the character *delimiter*. The **getline**\ () function is equivalent to
**getdelim**\ () with the newline character as the delimiter. The
delimiter character is included as part of the line, unless the end of
the file is reached.

The caller may provide a pointer to a malloced buffer for the line in
*\*linep*, and the capacity of that buffer in *\*linecapp*. These
functions expand the buffer as needed, as if via **realloc**\ (). If
*linep* points to a NULL pointer, a new buffer will be allocated. In
either case, *\*linep* and *\*linecapp* will be updated accordingly.

**RETURN VALUES**

The **getdelim**\ () and **getline**\ () functions return the number of
characters stored in the buffer, excluding the terminating NUL
character. The value −1 is returned if an error occurs, or if
end-of-file is reached.

**EXAMPLES**

The following code fragment reads lines from a file and writes them to
standard output. The **fwrite**\ () function is used in case the line
contains embedded NUL characters.

| char \*line = NULL;
| size_t linecap = 0;
| ssize_t linelen;
| while ((linelen = getline(&line, &linecap, fp)) > 0)

+-----------------------+-----------------------+-----------------------+
|                       | fwrite(line, linelen, |                       |
|                       | 1, stdout);           |                       |
+-----------------------+-----------------------+-----------------------+

free(line);

**ERRORS**

These functions may fail if:

[EINVAL]

Either *linep* or *linecapp* is NULL.

[EOVERFLOW]

No delimiter was found in the first SSIZE_MAX characters.

These functions may also fail due to any of the errors specified for
**fgets**\ () and **malloc**\ ().

**SEE ALSO**

fgetln(3), fgets(3), malloc(3)

**STANDARDS**

The **getdelim**\ () and **getline**\ () functions conform to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

These routines first appeared in FreeBSD 8.0.

**BUGS**

There are no wide character versions of **getdelim**\ () or
**getline**\ ().

BSD July 30, 2016 BSD

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

