--------------

PSIGNAL(3) BSD Library Functions Manual PSIGNAL(3)

**NAME**

**psignal**, **strsignal**, **sys_siglist**, **sys_signame** — system
signal messages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*void*

**psignal**\ (*int sig*, *const char *s*);

*extern const char \* const sys_siglist[]*; *
extern const char \* const sys_signame[]*;

**#include <string.h>**

*char \**

**strsignal**\ (*int sig*);

**DESCRIPTION**

The **psignal**\ () and **strsignal**\ () functions locate the
descriptive message string for a signal number.

The **strsignal**\ () function accepts a signal number argument *sig*
and returns a pointer to the corresponding message string.

The **psignal**\ () function accepts a signal number argument *sig* and
writes it to the standard error. If the argument *s* is non-NULL and
does not point to the null character, *s* is written to the standard
error file descriptor prior to the message string, immediately followed
by a colon and a space. If the signal number is not recognized
(sigaction(2)), the string ‘‘Unknown signal’’ is produced.

The message strings can be accessed directly through the external array
*sys_siglist*, indexed by recognized signal numbers. The external array
*sys_signame* is used similarly and contains short, upper-case
abbreviations for signals which are useful for recognizing signal names
in user input. The defined variable NSIG contains a count of the strings
in *sys_siglist* and *sys_signame*.

**SEE ALSO**

sigaction(2), perror(3), strerror(3)

**HISTORY**

The **psignal**\ () function appeared in 4.2BSD.

BSD May 30, 2016 BSD

--------------
