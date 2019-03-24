--------------

FFS(3) BSD Library Functions Manual FFS(3)

**NAME**

**ffs**, **ffsl**, **ffsll**, **fls**, **flsl**, **flsll** — find first
or last bit set in a bit string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*int*

**ffs**\ (*int value*);

*int*

**ffsl**\ (*long value*);

*int*

**ffsll**\ (*long long value*);

*int*

**fls**\ (*int value*);

*int*

**flsl**\ (*long value*);

*int*

**flsll**\ (*long long value*);

**DESCRIPTION**

The **ffs**\ (), **ffsl**\ () and **ffsll**\ () functions find the first
(least significant) bit set in *value* and return the index of that bit.

The **fls**\ (), **flsl**\ () and **flsll**\ () functions find the last
(most significant) bit set in *value* and return the index of that bit.

Bits are numbered starting at 1, the least significant bit. A return
value of zero from any of these functions means that the argument was
zero.

**SEE ALSO**

bitstring(3), bitset(9)

**HISTORY**

The **ffs**\ () function appeared in 4.3BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

The **ffsl**\ (), **fls**\ () and **flsl**\ () functions appeared in
FreeBSD 5.3. The **ffsll**\ () and **flsll**\ () functions appeared in
FreeBSD 7.1.

BSD October 17, 2015 BSD

--------------
