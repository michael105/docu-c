--------------

RAND(3) BSD Library Functions Manual RAND(3)

**NAME**

**rand**, **srand**, **sranddev**, **rand_r** — bad random number
generator

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void*

**srand**\ (*unsigned seed*);

*void*

**sranddev**\ (*void*);

*int*

**rand**\ (*void*);

*int*

**rand_r**\ (*unsigned *ctx*);

**DESCRIPTION**

**The functions described in this manual page are not cryptographically
secure. Cryptographic applications should use** arc4random(\ **3**)
**instead.**

These interfaces are obsoleted by random(3).

The **rand**\ () function computes a sequence of pseudo-random integers
in the range of 0 to RAND_MAX (as defined by the header file
<*stdlib.h*>).

The **srand**\ () function sets its argument *seed* as the seed for a
new sequence of pseudo-random numbers to be returned by **rand**\ ().
These sequences are repeatable by calling **srand**\ () with the same
seed value.

If no *seed* value is provided, the functions are automatically seeded
with a value of 1.

The **sranddev**\ () function initializes a seed using pseudo-random
numbers obtained from the kernel.

The **rand_r**\ () function provides the same functionality as
**rand**\ (). A pointer to the context value *ctx* must be supplied by
the caller.

For better generator quality, use random(3) or lrand48(3).

**SEE ALSO**

arc4random(3), lrand48(3), random(3), random(4)

**STANDARDS**

The **rand**\ () and **srand**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’).

The **rand_r**\ () function is as proposed in the POSIX.4a Draft #6
document.

BSD April 2, 2013 BSD

--------------
