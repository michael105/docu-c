--------------

MAKECONTEXT(3) BSD Library Functions Manual MAKECONTEXT(3)

**NAME**

**makecontext**, **swapcontext** — modify and exchange user thread
contexts

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ucontext.h>**

*void*

**makecontext**\ (*ucontext_t *ucp*, *void *\ (*\*func*)(\ *void*),
*int argc*, *...*);

*int*

**swapcontext**\ (*ucontext_t *oucp*, *const ucontext_t *ucp*);

**DESCRIPTION**

The **makecontext**\ () function modifies the user thread context
pointed to by *ucp*, which must have previously been initialized by a
call to getcontext(3) and had a stack allocated for it. The context is
modified so that it will continue execution by invoking **func**\ ()
with the arguments provided. The *argc* argument must be equal to the
number of additional arguments of type *int* provided to
**makecontext**\ () and also equal to the number of arguments of type
*int* to **func**\ (); otherwise , the behavior is undefined.

The *ucp->uc_link* argument must be initialized before calling
**makecontext**\ () and determines the action to take when **func**\ ()
returns: if equal to NULL, the process exits; otherwise,
**setcontext**\ (*ucp->uc_link*) is implicitly invoked.

The **swapcontext**\ () function saves the current thread context in
*\*oucp* and makes *\*ucp* the currently active context.

**RETURN VALUES**

If successful, **swapcontext**\ () returns zero; otherwise −1 is
returned and the global variable *errno* is set appropriately.

**ERRORS**

The **swapcontext**\ () function will fail if:

[ENOMEM]

There is not enough stack space in *ucp* to complete the operation.

**SEE ALSO**

setcontext(3), ucontext(3)

BSD January 31, 2018 BSD

--------------
