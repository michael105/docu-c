--------------

I386_GET_LDT(2) BSD System Calls Manual I386_GET_LDT(2)

**NAME**

**i386_get_ldt**, **i386_set_ldt** — manage i386 per-process Local
Descriptor Table entries

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <machine/segments.h>
#include <machine/sysarch.h>**

*int*

**i386_get_ldt**\ (*int start_sel*, *union descriptor *descs*,
*int num_sels*);

*int*

**i386_set_ldt**\ (*int start_sel*, *union descriptor *descs*,
*int num_sels*);

**DESCRIPTION**

The **i386_get_ldt**\ () system call returns a list of the i386
descriptors in the current process’ LDT. The **i386_set_ldt**\ () system
call sets a list of i386 descriptors in the current process’ LDT. For
both routines, *start_sel* specifies the index of the selector in the
LDT at which to begin and *descs* points to an array of *num_sels*
descriptors to be set or returned.

Each entry in the *descs* array can be either a segment_descriptor or
gate_descriptor and are defined in <*i386/segments.h*>. These structures
are defined by the architecture as disjoint bit-fields, so care must be
taken in constructing them.

If *start_sel* is *LDT_AUTO_ALLOC*, *num_sels* is 1 and the descriptor
pointed to by *descs* is legal, then **i386_set_ldt**\ () will allocate
a descriptor and return its selector number.

If *num_descs* is 1, *start_sels* is valid, and *descs* is NULL, then
**i386_set_ldt**\ () will free that descriptor (making it available to
be reallocated again later).

If *num_descs* is 0, *start_sels* is 0 and *descs* is NULL then, as a
special case, **i386_set_ldt**\ () will free all descriptors.

**RETURN VALUES**

Upon successful completion, **i386_get_ldt**\ () returns the number of
descriptors currently in the LDT. The **i386_set_ldt**\ () system call
returns the first selector set on success. If the kernel allocated a
descriptor in the LDT, the allocated index is returned. Otherwise, a
value of -1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **i386_get_ldt**\ () and **i386_set_ldt**\ () system calls will fail
if:

[EINVAL]

An inappropriate value was used for *start_sel* or *num_sels*.

[EACCES]

The caller attempted to use a descriptor that would circumvent
protection or cause a failure.

**SEE ALSO**

i386 Microprocessor Programmer’s Reference Manual, Intel

**WARNING**

You can really hose your process using this.

BSD October 14, 2006 BSD

--------------
