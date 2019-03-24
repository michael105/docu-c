--------------

PUBLICKEY(3) BSD Library Functions Manual PUBLICKEY(3)

**NAME**

**publickey**, **getpublickey**, **getsecretkey** — get public or secret
key

**LIBRARY**

RPC Service Library (librpcsvc, −lrpcsvc)

**SYNOPSIS**

**#include <rpc/rpc.h>
#include <rpc/key_prot.h>**

*int*

**getpublickey**\ (*const char netname[MAXNETNAMELEN+1]*,
*char publickey[HEXKEYBYTES+1]*);

*int*

**getsecretkey**\ (*char netname[MAXNETNAMELEN+1]*,
*char secretkey[HEXKEYBYTES+1]*, *char *passwd*);

**DESCRIPTION**

These routines are used to get public and secret keys from the YP
database. The **getsecretkey**\ () function has an extra argument,
*passwd*, which is used to decrypt the encrypted secret key stored in
the database. Both routines return 1 if they are successful in finding
the key, 0 otherwise. The keys are returned as NUL−terminated,
hexadecimal strings. If the password supplied to **getsecretkey**\ ()
fails to decrypt the secret key, the routine will return 1 but the
*secretkey* argument will be a NUL string (‘‘’’).

**SEE ALSO**

publickey(5)

*RPC Programmer’s Manual* in */usr/share/doc/psd/23.rpc*.

BSD October 6, 1987 BSD

--------------
