--------------

DBM(3) BSD Library Functions Manual DBM(3)

**NAME**

**dbm_clearerr**, **dbm_close**, **dbm_delete**, **dbm_dirfno**,
**dbm_error**, **dbm_fetch**, **dbm_firstkey**, **dbm_nextkey**,
**dbm_open**, **dbm_store** — database access functions

**SYNOPSIS**

**#include <fcntl.h>
#include <ndbm.h>**

*DBM \**

**dbm_open**\ (*const char *base*, *int flags*, *mode_t mode*);

*void*

**dbm_close**\ (*DBM *db*);

*int*

**dbm_store**\ (*DBM *db*, *datum key*, *datum data*, *int flags*);

*datum*

**dbm_fetch**\ (*DBM *db*, *datum key*);

*int*

**dbm_delete**\ (*DBM *db*, *datum key*);

*datum*

**dbm_firstkey**\ (*DBM *db*);

*datum*

**dbm_nextkey**\ (*DBM *db*);

*int*

**dbm_error**\ (*DBM *db*);

*int*

**dbm_clearerr**\ (*DBM *db*);

*int*

**dbm_dirfno**\ (*DBM *db*);

**DESCRIPTION**

Database access functions. These functions are implemented using
dbopen(3) with a hash(3) database.

*datum* is declared in <*ndbm.h*>:

typedef struct {

+-----------------------+-----------------------+-----------------------+
|                       | void \*dptr;          |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int dsize;            |                       |
+-----------------------+-----------------------+-----------------------+

} datum;

The **dbm_open**\ (*base*, *flags*, *mode*) function opens or creates a
database. The *base* argument is the basename of the file containing the
database; the actual database has a *.db* suffix. I.e., if *base* is
"/home/me/mystuff" then the actual database is in the file
*/home/me/mystuff.db*. The *flags* and *mode* arguments are passed to
open(2). (O_RDWR \| O_CREAT) is a typical value for *flags*; 0660 is a
typical value for *mode*. O_WRONLY is not allowed in *flags*. The
pointer returned by **dbm_open**\ () identifies the database and is the
*db* argument to the other functions. The **dbm_open**\ () function
returns NULL and sets *errno* if there were any errors.

The **dbm_close**\ (*db*) function closes the database.

The **dbm_store**\ (*db*, *key*, *data*, *flags*) function inserts or
replaces an entry in the database. The *flags* argument is either
DBM_INSERT or DBM_REPLACE. If *flags* is DBM_INSERT and the database
already contains an entry for *key*, that entry is not replaced.
Otherwise the entry is replaced or inserted. The **dbm_store**\ ()
function normally returns zero but returns 1 if the entry could not be
inserted (because *flags* is DBM_INSERT, and an entry with *key* already
exists) or returns -1 and sets *errno* if there were any errors.

The **dbm_fetch**\ (*db*, *key*) function returns NULL or the *data*
corresponding to *key*.

The **dbm_delete**\ (*db*, *key*) function deletes the entry for *key*.
The **dbm_delete**\ () function normally returns zero or returns -1 and
sets *errno* if there were any errors.

The **dbm_firstkey**\ (*db*) function returns the first key in the
database. The **dbm_nextkey**\ (*db*) function returns subsequent keys.
The **db_firstkey**\ () function must be called before
**dbm_nextkey**\ (). The order in which keys are returned is unspecified
and may appear random. The **dbm_nextkey**\ () function returns NULL
after all keys have been returned.

The **dbm_error**\ (*db*) function returns the *errno* value of the most
recent error. The **dbm_clearerr**\ (*db*) function resets this value to
0 and returns 0.

The **dbm_dirfno**\ (*db*) function returns the file descriptor to the
database.

**SEE ALSO**

open(2), dbopen(3), hash(3)

**STANDARDS**

These functions (except **dbm_dirfno**\ ()) are included in the
Version 2 of the Single UNIX Specification (‘‘SUSv2’’).

BSD May 30, 2016 BSD

--------------
