--------------

FSEEK(3) BSD Library Functions Manual FSEEK(3)

**NAME**

**fgetpos**, **fseek**, **fseeko**, **fsetpos**, **ftell**, **ftello**,
**rewind** — reposition a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fseek**\ (*FILE *stream*, *long offset*, *int whence*);

*long*

**ftell**\ (*FILE *stream*);

*void*

**rewind**\ (*FILE *stream*);

*int*

**fgetpos**\ (*FILE * restrict stream*, *fpos_t * restrict pos*);

*int*

**fsetpos**\ (*FILE *stream*, *const fpos_t *pos*);

**#include <sys/types.h>**

*int*

**fseeko**\ (*FILE *stream*, *off_t offset*, *int whence*);

*off_t*

**ftello**\ (*FILE *stream*);

**DESCRIPTION**

The **fseek**\ () function sets the file position indicator for the
stream pointed to by *stream*. The new position, measured in bytes, is
obtained by adding *offset* bytes to the position specified by *whence*.
If *whence* is set to SEEK_SET, SEEK_CUR, or SEEK_END, the offset is
relative to the start of the file, the current position indicator, or
end-of-file, respectively. A successful call to the **fseek**\ ()
function clears the end-of-file indicator for the stream and undoes any
effects of the ungetc(3) and ungetwc(3) functions on the same stream.

The **ftell**\ () function obtains the current value of the file
position indicator for the stream pointed to by *stream*.

The **rewind**\ () function sets the file position indicator for the
stream pointed to by *stream* to the beginning of the file. It is
equivalent to:

(void)fseek(stream, 0L, SEEK_SET)

except that the error indicator for the stream is also cleared (see
clearerr(3)).

Since **rewind**\ () does not return a value, an application wishing to
detect errors should clear *errno*, then call **rewind**\ (), and if
*errno* is non-zero, assume an error has occurred.

The **fseeko**\ () function is identical to **fseek**\ (), except it
takes an *off_t* argument instead of a *long*. Likewise, the
**ftello**\ () function is identical to **ftell**\ (), except it returns
an *off_t*.

The **fgetpos**\ () and **fsetpos**\ () functions are alternate
interfaces for retrieving and setting the current position in the file,
similar to **ftell**\ () and **fseek**\ (), except that the current
position is stored in an opaque object of type *fpos_t* pointed to by
*pos*. These functions provide a portable way to seek to offsets larger
than those that can be represented by a *long int*. They may also store
additional state information in the *fpos_t* object to facilitate
seeking within files containing multibyte characters with
state-dependent encodings. Although *fpos_t* has traditionally been an
integral type, applications cannot assume that it is; in particular,
they must not perform arithmetic on objects of this type.

If the stream is a wide character stream (see fwide(3)), the position
specified by the combination of *offset* and *whence* must contain the
first byte of a multibyte sequence.

**RETURN VALUES**

The **rewind**\ () function returns no value.

The **fgetpos**\ (), **fseek**\ (), **fseeko**\ (), and **fsetpos**\ ()
functions return the value 0 if successful; otherwise the value −1 is
returned and the global variable *errno* is set to indicate the error.

Upon successful completion, **ftell**\ () and **ftello**\ () return the
current offset. Otherwise, −1 is returned and the global variable
*errno* is set to indicate the error.

| **ERRORS**
| [EBADF]

The *stream* argument is not a seekable stream.

[EINVAL]

The *whence* argument is invalid or the resulting file-position
indicator would be set to a negative value.

[EOVERFLOW]

The resulting file offset would be a value which cannot be represented
correctly in an object of type *off_t* for **fseeko**\ () and
**ftello**\ () or *long* for **fseek**\ () and **ftell**\ ().

[ESPIPE]

The file descriptor underlying stream is associated with a pipe or FIFO
or file-position indicator value is unspecified (see ungetc(3)).

The functions **fgetpos**\ (), **fseek**\ (), **fseeko**\ (),
**fsetpos**\ (), **ftell**\ (), **ftello**\ (), and **rewind**\ () may
also fail and set *errno* for any of the errors specified for the
routines fflush(3), fstat(2), lseek(2), and malloc(3).

**SEE ALSO**

lseek(2), clearerr(3), fwide(3), ungetc(3), ungetwc(3)

**STANDARDS**

The **fgetpos**\ (), **fsetpos**\ (), **fseek**\ (), **ftell**\ (), and
**rewind**\ () functions conform to ISO/IEC 9899:1990 (‘‘ISO C90’’).

The **fseeko**\ () and **ftello**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

BSD March 19, 2004 BSD

--------------
