--------------

--------------

STDIO(3) BSD Library Functions Manual STDIO(3)

\**NAME*\*

\**stdio*\* â standard input/output library functions

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*FILE tdin*; \* FILE tdout*; \* FILE tderr*;

\**DESCRIPTION*\*

The standard I/O library provides a simple and efficient buffered stream
I/O interface. Input and output is mapped into logical data streams and
the physical I/O characteristics are concealed. The functions and macros
are listed below; more information is available from the individual man
pages.

A stream is associated with an external file (which may be a physical
device) by \*opening\* a file, which may involve creating a new file.
Creating an existing file causes its former contents to be discarded. If
a file can support positioning requests (such as a disk file, as opposed
to a terminal) then a \*file position indicator\* associated with the
stream is positioned at the start of the file (byte zero), unless the
file is opened with append mode. If append mode is used, the position
indicator will be placed at the end-of-file. The position indicator is
maintained by subsequent reads, writes and positioning requests. All
input occurs as if the characters were read by successive calls to the
fgetc(3) function; all output takes place as if all characters were
written by successive calls to the fputc(3) function.

A file is disassociated from a stream by \*closing\* the file. Output
streams are flushed (any unwritten buffer contents are transferred to
the host environment) before the stream is disassociated from the file.
The value of a pointer to a FILE object is indeterminate (garbage) after
a file is closed.

A file may be subsequently reopened, by the same or another program
execution, and its contents reclaimed or modified (if it can be
repositioned at the start). If the main function returns to its original
caller, or the exit(3) function is called, all open files are closed
(hence all output streams are flushed) before program termination. Other
methods of program termination may not close files properly and hence
buffered output may be lost. In particular, \_exit(2) does not flush
stdio files. Neither does an exit due to a signal. Buffers are flushed
by abort(3) as required by POSIX, although previous implementations did
not.

This implementation makes no distinction between ââtextââ and ââbinaryââ
streams. In effect, all streams are binary. No translation is performed
and no extra padding appears on any stream.

At program startup, three streams are predefined and need not be opened
explicitly:

\**â¢*\*

\*standard input\* (for reading conventional input),

\**â¢*\*

\*standard output\* (for writing conventional output), and

\**â¢*\*

\*standard error\* (for writing diagnostic output).

These streams are abbreviated stdin, stdout and stderr. Initially, the
standard error stream is unbuffered; the standard input and output
streams are fully buffered if and only if the streams do not refer to an
interactive or ââterminalââ device, as determined by the isatty(3)
function. In fact, \*all\* freshly-opened streams that refer to terminal
devices default to line buffering, and pending output to such streams is
written automatically whenever such an input stream is read. Note that
this applies only to ââtrue readsââ; if the read request can be
satisfied by existing buffered data, no automatic flush will occur. In
these cases, or when a large amount of computation is done after
printing part of a line on an output terminal, it is necessary to
fflush(3) the standard output before going off and computing so that the
output will appear. Alternatively, these defaults may be modified via
the setvbuf(3) function.

The \**stdio*\* library is a part of the library \**libc*\* and routines
are automatically loaded as needed by the C compiler. The SYNOPSIS
sections of the following manual pages indicate which include files are
to be used, what the compiler declaration for the function looks like
and which external variables are of interest.

The following are defined as macros; these names may not be re-used
without first removing their current definitions with \**#undef**:
BUFSIZ, EOF, FILENAME_MAX, FOPEN_MAX, L_ctermid, L_cuserid, L_tmpnam,
NULL, P_tmpdir, SEEK_CUR, SEEK_END, SEEK_SET, TMP_MAX, clearerr,
clearerr_unlocked, feof, feof_unlocked, ferror, ferror_unlocked, fileno,
fileno_unlocked, fropen, fwopen, getc, getc_unlocked, getchar,
getchar_unlocked, putc, putc_unlocked, putchar, putchar_unlocked,
stderr, stdin and stdout. Function versions of the macro functions
clearerr, clearerr_unlocked, feof, feof_unlocked, ferror,
ferror_unlocked, fileno, fileno_unlocked, getc, getc_unlocked, getchar,
getchar_unlocked, putc, putc_unlocked, putchar, and putchar_unlocked
exist and will be used if the macro definitions are explicitly removed.

\**SEE ALSO*\*

close(2), open(2), read(2), write(2)

\**STANDARDS*\*

The \**stdio*\* library conforms to ISO/IEC 9899:1999 (ââISOÂ C99ââ).

\**LIST OF FUNCTIONS*\*

\| \**Function Description*\* \| asprintf formatted output conversion \|
clearerr check and reset stream status \| dprintf formatted output
conversion \| fclose close a stream \| fdopen stream open functions \|
feof check and reset stream status \| ferror check and reset stream
status \| fflush flush a stream \| fgetc get next character or word from
input stream \| fgetln get a line from a stream \| fgetpos reposition a
stream \| fgets get a line from a stream \| fgetwc get next wide
character from input stream \| fgetws get a line of wide characters from
a stream \| fileno check and reset stream status \| fopen stream open
functions \| fprintf formatted output conversion \| fpurge flush a
stream \| fputc output a character or word to a stream \| fputs output a
line to a stream \| fputwc output a wide character to a stream \| fputws
output a line of wide characters to a stream \| fread binary stream
input/output \| freopen stream open functions \| fropen open a stream \|
fscanf input format conversion \| fseek reposition a stream \| fsetpos
reposition a stream \| ftell reposition a stream \| funopen open a
stream \| fwide set/get orientation of stream \| fwopen open a stream \|
fwprintf formatted wide character output conversion \| fwrite binary
stream input/output \| getc get next character or word from input stream
\| getchar get next character or word from input stream \| getdelim get
a line from a stream \| getline get a line from a stream \| gets get a
line from a stream \| getw get next character or word from input stream
\| getwc get next wide character from input stream \| getwchar get next
wide character from input stream \| mkdtemp create unique temporary
directory \| mkstemp create unique temporary file \| mktemp create
unique temporary file \| perror system error messages \| printf
formatted output conversion \| putc output a character or word to a
stream \| putchar output a character or word to a stream \| puts output
a line to a stream \| putw output a character or word to a stream \|
putwc output a wide character to a stream \| putwchar output a wide
character to a stream \| remove remove directory entry \| rewind
reposition a stream \| scanf input format conversion \| setbuf stream
buffering operations \| setbuffer stream buffering operations \|
setlinebuf stream buffering operations \| setvbuf stream buffering
operations \| snprintf formatted output conversion \| sprintf formatted
output conversion \| sscanf input format conversion \| strerror system
error messages \| swprintf formatted wide character output conversion \|
sys_errlist system error messages \| sys_nerr system error messages \|
tempnam temporary file routines \| tmpfile temporary file routines \|
tmpnam temporary file routines \| ungetc un-get character from input
stream \| ungetwc un-get wide character from input stream \| vasprintf
formatted output conversion \| vdprintf formatted output conversion \|
vfprintf formatted output conversion \| vfscanf input format conversion
\| vfwprintf formatted wide character output conversion \| vprintf
formatted output conversion \| vscanf input format conversion \|
vsnprintf formatted output conversion \| vsprintf formatted output
conversion \| vsscanf input format conversion \| vswprintf formatted
wide character output conversion \| vwprintf formatted wide character
output conversion \| wprintf formatted wide character output conversion

\**BUGS*\*

The standard buffered functions do not interact well with certain other
library and system functions, especially vfork(2).

BSD MarchÂ 3, 2009 BSD

--------------

--------------
