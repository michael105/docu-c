--------------

PROFIL(2) BSD System Calls Manual PROFIL(2)

**NAME**

**profil** — control process profiling

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**profil**\ (*char *samples*, *size_t size*, *vm_offset_t offset*,
*int scale*);

**DESCRIPTION**

The **profil**\ () system call enables or disables program counter
profiling of the current process. If profiling is enabled, then at every
profiling clock tick, the kernel updates an appropriate count in the
*samples* buffer. The frequency of the profiling clock is recorded in
the header in the profiling output file.

The buffer *samples* contains *size* bytes and is divided into a series
of 16-bit bins. Each bin counts the number of times the program counter
was in a particular address range in the process when a profiling clock
tick occurred while profiling was enabled. For a given program counter
address, the number of the corresponding bin is given by the relation:

[(pc - offset) / 2] \* scale / 65536

The *offset* argument is the lowest address at which the kernel takes
program counter samples. The *scale* argument ranges from 1 to 65536 and
can be used to change the span of the bins. A scale of 65536 maps each
bin to 2 bytes of address range; a scale of 32768 gives 4 bytes, 16384
gives 8 bytes and so on. Intermediate values provide approximate
intermediate ranges. A *scale* value of 0 disables profiling.

**RETURN VALUES**

The **profil**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

| **FILES**
| /usr/lib/gcrt0.o

profiling C run-time startup file

gmon.out

conventional name for profiling output file

**ERRORS**

The following error may be reported:

[EFAULT]

The buffer *samples* contains an invalid address.

**SEE ALSO**

gprof(1)

**HISTORY**

The **profil**\ () function appeared in Version 6 AT&T UNIX.

**BUGS**

This routine should be named **profile**\ ().

The *samples* argument should really be a vector of type *unsigned
short*.

The format of the gmon.out file is undocumented.

BSD December 1, 2017 BSD

--------------
