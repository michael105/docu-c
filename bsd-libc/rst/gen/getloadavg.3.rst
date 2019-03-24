--------------

GETLOADAVG(3) BSD Library Functions Manual GETLOADAVG(3)

**NAME**

**getloadavg** — get system load averages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**getloadavg**\ (*double loadavg[]*, *int nelem*);

**DESCRIPTION**

The **getloadavg**\ () function returns the number of processes in the
system run queue averaged over various periods of time. Up to *nelem*
samples are retrieved and assigned to successive elements of
*loadavg*\ []. The system imposes a maximum of 3 samples, representing
averages over the last 1, 5, and 15 minutes, respectively.

**DIAGNOSTICS**

If the load average was unobtainable, −1 is returned; otherwise, the
number of samples actually retrieved is returned.

**SEE ALSO**

uptime(1), kvm_getloadavg(3), sysctl(3)

**HISTORY**

The **getloadavg**\ () function appeared in 4.3BSD−Reno.

BSD June 4, 1993 BSD

--------------
