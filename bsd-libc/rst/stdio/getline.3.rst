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
