--------------

UCONTEXT(3) BSD Library Functions Manual UCONTEXT(3)

**NAME**

**ucontext** — user thread context

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ucontext.h>**

**DESCRIPTION**

The *ucontext_t* type is a structure type suitable for holding the
context for a user thread of execution. A thread’s context includes its
stack, saved registers, and list of blocked signals.

The *ucontext_t* structure contains at least these fields:

*ucontext_t \*uc_link*

context to assume when this one returns

*sigset_t uc_sigmask*

signals being blocked

*stack_t uc_stack*

stack area

*mcontext_t uc_mcontext*

saved registers

The *uc_link* field points to the context to resume when this context’s
entry point function returns. If *uc_link* is equal to NULL, then the
process exits when this context returns.

The *uc_mcontext* field is machine-dependent and should be treated as
opaque by portable applications.

The following functions are defined to manipulate *ucontext_t*
structures:

*int* **getcontext**\ (*ucontext_t \**); *
ucontext_t \** **getcontextx**\ (*void*); *
int* **setcontext**\ (*const ucontext_t \**); *
void* **makecontext**\ (*ucontext_t \**, *void* (*\**)(\ *void*), *int*,
*...*); *
int* **swapcontext**\ (*ucontext_t \**, *const ucontext_t \**);

**SEE ALSO**

sigaltstack(2), getcontext(3), getcontextx(3), makecontext(3)

BSD September 10, 2002 BSD

--------------
