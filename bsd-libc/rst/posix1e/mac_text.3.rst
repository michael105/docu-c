--------------

MAC_TEXT(3) BSD Library Functions Manual MAC_TEXT(3)

**NAME**

**mac_from_text**, **mac_to_text** — convert MAC label to/from text
representation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mac.h>**

*int*

**mac_from_text**\ (*mac_t *mac*, *const char *text*);

*int*

**mac_to_text**\ (*mac_t label*, *char **text*);

**DESCRIPTION**

The **mac_from_text**\ () function converts the text representation of a
label into the internal policy label format (*mac_t*) and places it in
*\*mac*, which must later be freed with free(3).

The **mac_to_text**\ () function allocates storage for *\*text*, which
will be set to the text representation of *label*.

Refer to maclabel(7) for the MAC label format.

**RETURN VALUES**

The **mac_from_text**\ () and **mac_to_text**\ () functions return the
value 0 if successful; otherwise the value −1 is returned and the global
variable *errno* is set to indicate the error.

**COMPATIBILITY**

POSIX.1e does not define a format for text representations of MAC
labels.

POSIX.1e requires that text strings allocated using **mac_to_text**\ ()
be freed using mac_free(3); in the FreeBSD implementation, they must be
freed using free(3), as mac_free(3) is used only to free memory used for
type *mac_t*.

| **ERRORS**
| [ENOMEM]

Insufficient memory was available to allocate internal storage.

**SEE ALSO**

free(3), mac(3), mac_get(3), mac_is_present(3), mac_prepare(3),
mac_set(3), posix1e(3), mac(4), maclabel(7)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

Support for Mandatory Access Control was introduced in FreeBSD 5.0 as
part of the TrustedBSD Project.

BSD December 21, 2001 BSD

--------------
