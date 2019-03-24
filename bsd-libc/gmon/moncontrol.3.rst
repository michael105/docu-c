--------------

MONCONTROL(3) BSD Library Functions Manual MONCONTROL(3)

**NAME**

**moncontrol**, **monstartup** — control execution profile

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/gmon.h>**

*void*

**moncontrol**\ (*int mode*);

*void*

**monstartup**\ (*u_long lowpc*, *u_long highpc*);

**DESCRIPTION**

An executable program compiled using the **−pg** option to cc(1)
automatically includes calls to collect statistics for the gprof(1)
call-graph execution profiler. In typical operation, profiling begins at
program startup and ends when the program calls exit. When the program
exits, the profiling data are written to the file *progname.gmon*, where
progname is the name of the program, then gprof(1) can be used to
examine the results.

The **moncontrol**\ () function selectively controls profiling within a
program. When the program starts, profiling begins. To stop the
collection of histogram ticks and call counts use **moncontrol**\ (*0*);
to resume the collection of histogram ticks and call counts use
**moncontrol**\ (*1*). This feature allows the cost of particular
operations to be measured. Note that an output file will be produced on
program exit regardless of the state of **moncontrol**\ ().

Programs that are not loaded with **−pg** may selectively collect
profiling statistics by calling **monstartup**\ () with the range of
addresses to be profiled. The *lowpc* and *highpc* arguments specify the
address range that is to be sampled; the lowest address sampled is that
of *lowpc* and the highest is just below *highpc*. Only functions in
that range that have been compiled with the **−pg** option to cc(1) will
appear in the call graph part of the output; however, all functions in
that address range will have their execution time measured. Profiling
begins on return from **monstartup**\ ().

**ENVIRONMENT**

The following environment variables affect the execution of
**moncontrol**:

PROFIL_USE_PID

If set, the pid of the process is inserted into the filename.

| **FILES**
| progname.gmon

execution data file

**SEE ALSO**

cc(1), gprof(1), profil(2), clocks(7)

BSD June 14, 2004 BSD

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

