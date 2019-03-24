--------------

SETJMP(3) BSD Library Functions Manual SETJMP(3)

**NAME**

**sigsetjmp**, **siglongjmp**, **setjmp**, **longjmp**, **\_setjmp**,
**\_longjmp**, **longjmperror** — non-local jumps

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <setjmp.h>**

*int*

**sigsetjmp**\ (*sigjmp_buf env*, *int savemask*);

*void*

**siglongjmp**\ (*sigjmp_buf env*, *int val*);

*int*

**setjmp**\ (*jmp_buf env*);

*void*

**longjmp**\ (*jmp_buf env*, *int val*);

*int*

**\_setjmp**\ (*jmp_buf env*);

*void*

**\_longjmp**\ (*jmp_buf env*, *int val*);

*void*

**longjmperror**\ (*void*);

**DESCRIPTION**

The **sigsetjmp**\ (), **setjmp**\ (), and **\_setjmp**\ () functions
save their calling environment in *env*. Each of these functions returns
0.

The corresponding **longjmp**\ () functions restore the environment
saved by their most recent respective invocations of the **setjmp**\ ()
function. They then return so that program execution continues as if the
corresponding invocation of the **setjmp**\ () call had just returned
the value specified by *val*, instead of 0.

Pairs of calls may be intermixed, i.e., both **sigsetjmp**\ () and
**siglongjmp**\ () and **setjmp**\ () and **longjmp**\ () combinations
may be used in the same program, however, individual calls may not, e.g.
the *env* argument to **setjmp**\ () may not be passed to
**siglongjmp**\ ().

The **longjmp**\ () routines may not be called after the routine which
called the **setjmp**\ () routines returns.

All accessible objects have values as of the time **longjmp**\ ()
routine was called, except that the values of objects of automatic
storage invocation duration that do not have the *volatile* type and
have been changed between the **setjmp**\ () invocation and
**longjmp**\ () call are indeterminate.

The **setjmp**\ ()/**longjmp**\ () pairs save and restore the signal
mask while **\_setjmp**\ ()/**\_longjmp**\ () pairs save and restore
only the register set and the stack. (See **sigprocmask**\ (*2*).)

The **sigsetjmp**\ ()/**siglongjmp**\ () function pairs save and restore
the signal mask if the argument *savemask* is non-zero, otherwise only
the register set and the stack are saved.

**ERRORS**

If the contents of the *env* are corrupted, or correspond to an
environment that has already returned, the **longjmp**\ () routine calls
the routine **longjmperror**\ (*3*). If **longjmperror**\ () returns the
program is aborted (see abort(3)). The default version of
**longjmperror**\ () prints the message ‘‘longjmp botch’’ to standard
error and returns. User programs wishing to exit more gracefully should
write their own versions of **longjmperror**\ ().

**SEE ALSO**

sigaction(2), sigaltstack(2), signal(3)

**STANDARDS**

The **setjmp**\ () and **longjmp**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’). The **sigsetjmp**\ () and **siglongjmp**\ ()
functions conform to IEEE Std 1003.1-1988 (‘‘POSIX.1’’).

BSD June 4, 1993 BSD

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

