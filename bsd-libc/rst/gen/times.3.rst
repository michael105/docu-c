--------------

TIMES(3) BSD Library Functions Manual TIMES(3)

**NAME**

**times** — process times

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/times.h>**

*clock_t*

**times**\ (*struct tms *tp*);

**DESCRIPTION**

**This interface is obsoleted by** getrusage(\ **2**) **and**
gettimeofday(\ **2**)\ **.**

The **times**\ () function returns the value of time in CLK_TCK’s of a
second since the system startup time. The current value of CLK_TCK, the
frequency of the statistics clock in ticks per second, may be obtained
through the sysconf(3) interface.

It also fills in the structure pointed to by *tp* with time-accounting
information.

The *tms* structure is defined as follows:

struct tms {

+-----------------------+-----------------------+-----------------------+
|                       | clock_t tms_utime;    |                       |
+-----------------------+-----------------------+-----------------------+
|                       | clock_t tms_stime;    |                       |
+-----------------------+-----------------------+-----------------------+
|                       | clock_t tms_cutime;   |                       |
+-----------------------+-----------------------+-----------------------+
|                       | clock_t tms_cstime;   |                       |
+-----------------------+-----------------------+-----------------------+

};

The elements of this structure are defined as follows:

*tms_utime*

The CPU time charged for the execution of user instructions.

*tms_stime*

The CPU time charged for execution by the system on behalf of the
process.

*tms_cutime*

The sum of the *tms_utime*\ s and *tms_cutime*\ s of the child
processes.

*tms_cstime*

The sum of the *tms_stime*\ s and *tms_cstime*\ s of the child
processes.

All times are in CLK_TCK’s of a second.

The times of a terminated child process are included in the *tms_cutime*
and *tms_cstime* elements of the parent when one of the wait(2)
functions returns the process ID of the terminated child to the parent.
If an error occurs, **times**\ () returns the value ((

*clock_t* )−1), and sets *errno* to indicate the error.

**ERRORS**

The **times**\ () function may fail and set the global variable *errno*
for any of the errors specified for the library routines getrusage(2)
and gettimeofday(2).

**SEE ALSO**

time(1), getrusage(2), gettimeofday(2), wait(2), sysconf(3), clocks(7)

**STANDARDS**

The **times**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

BSD December 1, 2008 BSD

--------------
