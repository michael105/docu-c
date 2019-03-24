--------------

FOPENCOOKIE(3) BSD Library Functions Manual FOPENCOOKIE(3)

**NAME**

**fopencookie** — open a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*typedef ssize_t*

**(*cookie_read_function_t)**\ (*void *cookie*, *char *buf*,
*size_t size*);

*typedef ssize_t*

**(*cookie_write_function_t)**\ (*void *cookie*, *const char *buf*,
*size_t size*);

*typedef int*

**(*cookie_seek_function_t)**\ (*void *cookie*, *off64_t *offset*,
*int whence*);

*typedef int*

**(*cookie_close_function_t)**\ (*void *cookie*);

typedef struct {

+-------------+-------------+-------------+-------------+-------------+
|             | cookie_read |             | \*read;     |             |
|             | _function_t |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | cookie_writ |             | \*write;    |             |
|             | e_function_ |             |             |             |
|             | t           |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | cookie_seek |             | \*seek;     |             |
|             | _function_t |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | cookie_clos |             | \*close;    |             |
|             | e_function_ |             |             |             |
|             | t           |             |             |             |
+-------------+-------------+-------------+-------------+-------------+

} cookie_io_functions_t;

*FILE \**

**fopencookie**\ (*void *cookie*, *const char *mode*,
*cookie_io_functions_t io_funcs*);

**DESCRIPTION**

The **fopencookie** function associates a stream with up to four ‘‘I/O
functions’’. These I/O functions will be used to read, write, seek and
close the new stream.

In general, omitting a function means that any attempt to perform the
associated operation on the resulting stream will fail. If the write
function is omitted, data written to the stream is discarded. If the
close function is omitted, closing the stream will flush any buffered
output and then succeed.

The calling conventions of *read*, *write*, and *close* must match
those, respectively, of read(2), write(2), and close(2) with the single
exception that they are passed the *cookie* argument specified to
**fopencookie** in place of the traditional file descriptor argument.
The *seek* function updates the current stream offset using *\*offset*
and *whence*. If *\*offset* is non-NULL, it updates *\*offset* with the
current stream offset.

**fopencookie** is implemented as a thin shim around the funopen(3)
interface. Limitations, possibilities, and requirements of that
interface apply to **fopencookie**.

**RETURN VALUES**

Upon successful completion, **fopencookie** returns a FILE pointer.
Otherwise, NULL is returned and the global variable *errno* is set to
indicate the error.

| **ERRORS**
| [EINVAL]

A bogus *mode* was provided to **fopencookie**.

[ENOMEM]

The **fopencookie** function may fail and set *errno* for any of the
errors specified for the malloc(3) routine.

**SEE ALSO**

fcntl(2), open(2), fclose(3), fopen(3), fseek(3), funopen(3)

**HISTORY**

The **funopen**\ () functions first appeared in 4.4BSD. The
**fopencookie** function first appeared in FreeBSD 11.

**BUGS**

The **fopencookie** function is a nonstandard glibc extension and may
not be portable to systems other than FreeBSD and Linux.

BSD May 9, 2016 BSD

--------------
