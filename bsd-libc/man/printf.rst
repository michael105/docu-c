==> append : to filename to view the nroff source
PRINTF(3)                BSD Library Functions Manual                PRINTF(3)

NNAAMMEE
     pprriinnttff, ffpprriinnttff, sspprriinnttff, ssnnpprriinnttff, aasspprriinnttff, ddpprriinnttff, vvpprriinnttff, vvffpprriinnttff,
     vvsspprriinnttff, vvssnnpprriinnttff, vvaasspprriinnttff, vvddpprriinnttff -- formatted output conversion

LLIIBBRRAARRYY
     Standard C Library (libc, -lc)

SSYYNNOOPPSSIISS
     ##iinncclluuddee <<ssttddiioo..hh>>

     _i_n_t
     pprriinnttff(_c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _._._.);

     _i_n_t
     ffpprriinnttff(_F_I_L_E _* _r_e_s_t_r_i_c_t _s_t_r_e_a_m, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _._._.);

     _i_n_t
     sspprriinnttff(_c_h_a_r _* _r_e_s_t_r_i_c_t _s_t_r, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _._._.);

     _i_n_t
     ssnnpprriinnttff(_c_h_a_r _* _r_e_s_t_r_i_c_t _s_t_r, _s_i_z_e___t _s_i_z_e, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t,
         _._._.);

     _i_n_t
     aasspprriinnttff(_c_h_a_r _*_*_r_e_t, _c_o_n_s_t _c_h_a_r _*_f_o_r_m_a_t, _._._.);

     _i_n_t
     ddpprriinnttff(_i_n_t _f_d, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _._._.);

     ##iinncclluuddee <<ssttddaarrgg..hh>>

     _i_n_t
     vvpprriinnttff(_c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _v_a___l_i_s_t _a_p);

     _i_n_t
     vvffpprriinnttff(_F_I_L_E _* _r_e_s_t_r_i_c_t _s_t_r_e_a_m, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t,
         _v_a___l_i_s_t _a_p);

     _i_n_t
     vvsspprriinnttff(_c_h_a_r _* _r_e_s_t_r_i_c_t _s_t_r, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _v_a___l_i_s_t _a_p);

     _i_n_t
     vvssnnpprriinnttff(_c_h_a_r _* _r_e_s_t_r_i_c_t _s_t_r, _s_i_z_e___t _s_i_z_e, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t,
         _v_a___l_i_s_t _a_p);

     _i_n_t
     vvaasspprriinnttff(_c_h_a_r _*_*_r_e_t, _c_o_n_s_t _c_h_a_r _*_f_o_r_m_a_t, _v_a___l_i_s_t _a_p);

     _i_n_t
     vvddpprriinnttff(_i_n_t _f_d, _c_o_n_s_t _c_h_a_r _* _r_e_s_t_r_i_c_t _f_o_r_m_a_t, _v_a___l_i_s_t _a_p);

DDEESSCCRRIIPPTTIIOONN
     The pprriinnttff() family of functions produces output according to a _f_o_r_m_a_t as
     described below.  The pprriinnttff() and vvpprriinnttff() functions write output to
     stdout, the standard output stream; ffpprriinnttff() and vvffpprriinnttff() write output
     to the given output _s_t_r_e_a_m; ddpprriinnttff() and vvddpprriinnttff() write output to the
     given file descriptor; sspprriinnttff(), ssnnpprriinnttff(), vvsspprriinnttff(), and vvssnnpprriinnttff()
     write to the character string _s_t_r; and aasspprriinnttff() and vvaasspprriinnttff() dynami-
     cally allocate a new string with malloc(3).

     These functions write the output under the control of a _f_o_r_m_a_t string
     that specifies how subsequent arguments (or arguments accessed via the
     variable-length argument facilities of stdarg(3)) are converted for out-
     put.

     The aasspprriinnttff() and vvaasspprriinnttff() functions set _*_r_e_t to be a pointer to a
     buffer sufficiently large to hold the formatted string.  This pointer
     should be passed to free(3) to release the allocated storage when it is
     no longer needed.  If sufficient space cannot be allocated, aasspprriinnttff()
     and vvaasspprriinnttff() will return -1 and set _r_e_t to be a NULL pointer.

     The ssnnpprriinnttff() and vvssnnpprriinnttff() functions will write at most _s_i_z_e-1 of the
     characters printed into the output string (the _s_i_z_e'th character then
     gets the terminating `\0'); if the return value is greater than or equal
     to the _s_i_z_e argument, the string was too short and some of the printed
     characters were discarded.  The output is always null-terminated, unless
     _s_i_z_e is 0.

     The sspprriinnttff() and vvsspprriinnttff() functions effectively assume a _s_i_z_e of
     INT_MAX + 1.

     The format string is composed of zero or more directives: ordinary char-
     acters (not %%), which are copied unchanged to the output stream; and con-
     version specifications, each of which results in fetching zero or more
     subsequent arguments.  Each conversion specification is introduced by the
     %% character.  The arguments must correspond properly (after type promo-
     tion) with the conversion specifier.  After the %%, the following appear
     in sequence:

     ··   An optional field, consisting of a decimal digit string followed by a
         $$, specifying the next argument to access.  If this field is not pro-
         vided, the argument following the last argument accessed will be
         used.  Arguments are numbered starting at 11.  If unaccessed arguments
         in the format string are interspersed with ones that are accessed the
         results will be indeterminate.

     ··   Zero or more of the following flags:

         `##'          The value should be converted to an ``alternate form''.
                      For cc, dd, ii, nn, pp, ss, and uu conversions, this option has
                      no effect.  For oo conversions, the precision of the num-
                      ber is increased to force the first character of the
                      output string to a zero.  For xx and XX conversions, a
                      non-zero result has the string `0x' (or `0X' for XX con-
                      versions) prepended to it.  For aa, AA, ee, EE, ff, FF, gg, and
                      GG conversions, the result will always contain a decimal
                      point, even if no digits follow it (normally, a decimal
                      point appears in the results of those conversions only
                      if a digit follows).  For gg and GG conversions, trailing
                      zeros are not removed from the result as they would oth-
                      erwise be.

         `00' (zero)   Zero padding.  For all conversions except nn, the con-
                      verted value is padded on the left with zeros rather
                      than blanks.  If a precision is given with a numeric
                      conversion (dd, ii, oo, uu, ii, xx, and XX), the 00 flag is
                      ignored.

         `--'          A negative field width flag; the converted value is to
                      be left adjusted on the field boundary.  Except for nn
                      conversions, the converted value is padded on the right
                      with blanks, rather than on the left with blanks or
                      zeros.  A -- overrides a 00 if both are given.

         ` ' (space)  A blank should be left before a positive number produced
                      by a signed conversion (aa, AA, dd, ee, EE, ff, FF, gg, GG, or
                      ii).

         `++'          A sign must always be placed before a number produced by
                      a signed conversion.  A ++ overrides a space if both are
                      used.

         `'' (apostrophe)
                      Decimal conversions (dd, uu, or ii) or the integral portion
                      of a floating point conversion (ff or FF) should be
                      grouped and separated by thousands using the non-mone-
                      tary separator returned by localeconv(3).

     ··   An optional decimal digit string specifying a minimum field width.
         If the converted value has fewer characters than the field width, it
         will be padded with spaces on the left (or right, if the left-adjust-
         ment flag has been given) to fill out the field width.

     ··   An optional precision, in the form of a period .. followed by an
         optional digit string.  If the digit string is omitted, the precision
         is taken as zero.  This gives the minimum number of digits to appear
         for dd, ii, oo, uu, xx, and XX conversions, the number of digits to appear
         after the decimal-point for aa, AA, ee, EE, ff, and FF conversions, the
         maximum number of significant digits for gg and GG conversions, or the
         maximum number of characters to be printed from a string for ss con-
         versions.

     ··   An optional length modifier, that specifies the size of the argument.
         The following length modifiers are valid for the dd, ii, nn, oo, uu, xx, or
         XX conversion:

         MMooddiiffiieerr          dd, ii           oo, uu, xx, XX            nn
         hhhh                _s_i_g_n_e_d _c_h_a_r    _u_n_s_i_g_n_e_d _c_h_a_r         _s_i_g_n_e_d _c_h_a_r _*
         hh                 _s_h_o_r_t          _u_n_s_i_g_n_e_d _s_h_o_r_t        _s_h_o_r_t _*
         ll (ell)           _l_o_n_g           _u_n_s_i_g_n_e_d _l_o_n_g         _l_o_n_g _*
         llll (ell ell)      _l_o_n_g _l_o_n_g      _u_n_s_i_g_n_e_d _l_o_n_g _l_o_n_g    _l_o_n_g _l_o_n_g _*
         jj                 _i_n_t_m_a_x___t       _u_i_n_t_m_a_x___t             _i_n_t_m_a_x___t _*
         tt                 _p_t_r_d_i_f_f___t      (see note)            _p_t_r_d_i_f_f___t _*
         zz                 (see note)     _s_i_z_e___t                (see note)
         qq _(_d_e_p_r_e_c_a_t_e_d_)    _q_u_a_d___t         _u___q_u_a_d___t              _q_u_a_d___t _*

         Note: the tt modifier, when applied to a oo, uu, xx, or XX conversion,
         indicates that the argument is of an unsigned type equivalent in size
         to a _p_t_r_d_i_f_f___t.  The zz modifier, when applied to a dd or ii conversion,
         indicates that the argument is of a signed type equivalent in size to
         a _s_i_z_e___t.  Similarly, when applied to an nn conversion, it indicates
         that the argument is a pointer to a signed type equivalent in size to
         a _s_i_z_e___t.

         The following length modifier is valid for the aa, AA, ee, EE, ff, FF, gg,
         or GG conversion:

         MMooddiiffiieerr    aa, AA, ee, EE, ff, FF, gg, GG
         ll (ell)     _d_o_u_b_l_e (ignored, same behavior as without it)
         LL           _l_o_n_g _d_o_u_b_l_e

         The following length modifier is valid for the cc or ss conversion:

         MMooddiiffiieerr    cc         ss
         ll (ell)     _w_i_n_t___t    _w_c_h_a_r___t _*

     ··   A character that specifies the type of conversion to be applied.

     A field width or precision, or both, may be indicated by an asterisk `*'
     or an asterisk followed by one or more decimal digits and a `$' instead
     of a digit string.  In this case, an _i_n_t argument supplies the field
     width or precision.  A negative field width is treated as a left adjust-
     ment flag followed by a positive field width; a negative precision is
     treated as though it were missing.  If a single format directive mixes
     positional (nn$) and non-positional arguments, the results are undefined.

     The conversion specifiers and their meanings are:

     ddiioouuxxXX  The _i_n_t (or appropriate variant) argument is converted to signed
             decimal (dd and ii), unsigned octal (oo), unsigned decimal (uu), or
             unsigned hexadecimal (xx and XX) notation.  The letters ``abcdef''
             are used for xx conversions; the letters ``ABCDEF'' are used for XX
             conversions.  The precision, if any, gives the minimum number of
             digits that must appear; if the converted value requires fewer
             digits, it is padded on the left with zeros.

     DDOOUU     The _l_o_n_g _i_n_t argument is converted to signed decimal, unsigned
             octal, or unsigned decimal, as if the format had been lldd, lloo, or
             lluu respectively.  These conversion characters are deprecated, and
             will eventually disappear.

     eeEE      The _d_o_u_b_l_e argument is rounded and converted in the style
             [-]_d._d_d_de±_d_d where there is one digit before the decimal-point
             character and the number of digits after it is equal to the pre-
             cision; if the precision is missing, it is taken as 6; if the
             precision is zero, no decimal-point character appears.  An EE con-
             version uses the letter `E' (rather than `e') to introduce the
             exponent.  The exponent always contains at least two digits; if
             the value is zero, the exponent is 00.

             For aa, AA, ee, EE, ff, FF, gg, and GG conversions, positive and negative
             infinity are represented as inf and -inf respectively when using
             the lowercase conversion character, and INF and -INF respectively
             when using the uppercase conversion character.  Similarly, NaN is
             represented as nan when using the lowercase conversion, and NAN
             when using the uppercase conversion.

     ffFF      The _d_o_u_b_l_e argument is rounded and converted to decimal notation
             in the style [-]_d_d_d._d_d_d, where the number of digits after the
             decimal-point character is equal to the precision specification.
             If the precision is missing, it is taken as 6; if the precision
             is explicitly zero, no decimal-point character appears.  If a
             decimal point appears, at least one digit appears before it.

     ggGG      The _d_o_u_b_l_e argument is converted in style ff or ee (or FF or EE for GG
             conversions).  The precision specifies the number of significant
             digits.  If the precision is missing, 6 digits are given; if the
             precision is zero, it is treated as 1.  Style ee is used if the
             exponent from its conversion is less than -4 or greater than or
             equal to the precision.  Trailing zeros are removed from the
             fractional part of the result; a decimal point appears only if it
             is followed by at least one digit.

     aaAA      The _d_o_u_b_l_e argument is rounded and converted to hexadecimal nota-
             tion in the style [-]0x_h._h_h_h_p[±]_d, where the number of digits
             after the hexadecimal-point character is equal to the precision
             specification.  If the precision is missing, it is taken as
             enough to represent the floating-point number exactly, and no
             rounding occurs.  If the precision is zero, no hexadecimal-point
             character appears.  The pp is a literal character `p', and the
             exponent consists of a positive or negative sign followed by a
             decimal number representing an exponent of 2.  The AA conversion
             uses the prefix ``0X'' (rather than ``0x''), the letters
             ``ABCDEF'' (rather than ``abcdef'') to represent the hex digits,
             and the letter `P' (rather than `p') to separate the mantissa and
             exponent.

             Note that there may be multiple valid ways to represent floating-
             point numbers in this hexadecimal format.  For example,
             0x1.92p+1, 0x3.24p+0, 0x6.48p-1, and 0xc.9p-2 are all equivalent.
             FreeBSD 8.0 and later always prints finite non-zero numbers using
             `1' as the digit before the hexadecimal point.  Zeroes are always
             represented with a mantissa of 0 (preceded by a `-' if appropri-
             ate) and an exponent of +0.

     CC       Treated as cc with the ll (ell) modifier.

     cc       The _i_n_t argument is converted to an _u_n_s_i_g_n_e_d _c_h_a_r, and the
             resulting character is written.

             If the ll (ell) modifier is used, the _w_i_n_t___t argument shall be
             converted to a _w_c_h_a_r___t, and the (potentially multi-byte) sequence
             representing the single wide character is written, including any
             shift sequences.  If a shift sequence is used, the shift state is
             also restored to the original state after the character.

     SS       Treated as ss with the ll (ell) modifier.

     ss       The _c_h_a_r _* argument is expected to be a pointer to an array of
             character type (pointer to a string).  Characters from the array
             are written up to (but not including) a terminating NUL charac-
             ter; if a precision is specified, no more than the number speci-
             fied are written.  If a precision is given, no null character
             need be present; if the precision is not specified, or is greater
             than the size of the array, the array must contain a terminating
             NUL character.

             If the ll (ell) modifier is used, the _w_c_h_a_r___t _* argument is
             expected to be a pointer to an array of wide characters (pointer
             to a wide string).  For each wide character in the string, the
             (potentially multi-byte) sequence representing the wide character
             is written, including any shift sequences.  If any shift sequence
             is used, the shift state is also restored to the original state
             after the string.  Wide characters from the array are written up
             to (but not including) a terminating wide NUL character; if a
             precision is specified, no more than the number of bytes speci-
             fied are written (including shift sequences).  Partial characters
             are never written.  If a precision is given, no null character
             need be present; if the precision is not specified, or is greater
             than the number of bytes required to render the multibyte repre-
             sentation of the string, the array must contain a terminating
             wide NUL character.

     pp       The _v_o_i_d _* pointer argument is printed in hexadecimal (as if by
             `%#x' or `%#lx').

     nn       The number of characters written so far is stored into the inte-
             ger indicated by the _i_n_t _* (or variant) pointer argument.  No
             argument is converted.

     mm       Print the string representation of the error code stored in the
             errno variable at the beginning of the call, as returned by
             strerror(3).  No argument is taken.

     %%       A `%' is written.  No argument is converted.  The complete con-
             version specification is `%%'.

     The decimal point character is defined in the program's locale (category
     LC_NUMERIC).

     In no case does a non-existent or small field width cause truncation of a
     numeric field; if the result of a conversion is wider than the field
     width, the field is expanded to contain the conversion result.

RREETTUURRNN VVAALLUUEESS
     These functions return the number of characters printed (not including
     the trailing `\0' used to end output to strings), except for ssnnpprriinnttff()
     and vvssnnpprriinnttff(), which return the number of characters that would have
     been printed if the _s_i_z_e were unlimited (again, not including the final
     `\0').  These functions return a negative value if an error occurs.

EEXXAAMMPPLLEESS
     To print a date and time in the form ``Sunday, July 3, 10:02'', where
     _w_e_e_k_d_a_y and _m_o_n_t_h are pointers to strings:

           #include <stdio.h>
           fprintf(stdout, "%s, %s %d, %.2d:%.2d\n",
                   weekday, month, day, hour, min);

     To print pi to five decimal places:

           #include <math.h>
           #include <stdio.h>
           fprintf(stdout, "pi = %.5f\n", 4 * atan(1.0));

     To allocate a 128 byte string and print into it:

           #include <stdio.h>
           #include <stdlib.h>
           #include <stdarg.h>
           char *newfmt(const char *fmt, ...)
           {
                   char *p;
                   va_list ap;
                   if ((p = malloc(128)) == NULL)
                           return (NULL);
                   va_start(ap, fmt);
                   (void) vsnprintf(p, 128, fmt, ap);
                   va_end(ap);
                   return (p);
           }

CCOOMMPPAATTIIBBIILLIITTYY
     The conversion formats %%DD, %%OO, and %%UU are not standard and are provided
     only for backward compatibility.  The conversion format %%mm is also not
     standard and provides the popular extension from the GNU C library.

     The effect of padding the %%pp format with zeros (either by the 00 flag or
     by specifying a precision), and the benign effect (i.e., none) of the ##
     flag on %%nn and %%pp conversions, as well as other nonsensical combinations
     such as %%LLdd, are not standard; such combinations should be avoided.

EERRRROORRSS
     In addition to the errors documented for the write(2) system call, the
     pprriinnttff() family of functions may fail if:

     [EILSEQ]           An invalid wide character code was encountered.

     [ENOMEM]           Insufficient storage space is available.

     [EOVERFLOW]        The _s_i_z_e argument exceeds INT_MAX + 1, or the return
                        value would be too large to be represented by an _i_n_t.

SSEEEE AALLSSOO
     printf(1), errno(2), fmtcheck(3), scanf(3), setlocale(3), strerror(3),
     wprintf(3)

SSTTAANNDDAARRDDSS
     Subject to the caveats noted in the _B_U_G_S section below, the ffpprriinnttff(),
     pprriinnttff(), sspprriinnttff(), vvpprriinnttff(), vvffpprriinnttff(), and vvsspprriinnttff() functions con-
     form to ANSI X3.159-1989 (``ANSI C89'') and ISO/IEC 9899:1999
     (``ISO C99'').  With the same reservation, the ssnnpprriinnttff() and vvssnnpprriinnttff()
     functions conform to ISO/IEC 9899:1999 (``ISO C99''), while ddpprriinnttff() and
     vvddpprriinnttff() conform to IEEE Std 1003.1-2008 (``POSIX.1'').

HHIISSTTOORRYY
     The functions aasspprriinnttff() and vvaasspprriinnttff() first appeared in the GNU C
     library.  These were implemented by Peter Wemm <_p_e_t_e_r_@_F_r_e_e_B_S_D_._o_r_g> in
     FreeBSD 2.2, but were later replaced with a different implementation from
     OpenBSD 2.3 by Todd C. Miller <_T_o_d_d_._M_i_l_l_e_r_@_c_o_u_r_t_e_s_a_n_._c_o_m>.  The ddpprriinnttff()
     and vvddpprriinnttff() functions were added in FreeBSD 8.0.  The %%mm format exten-
     sion first appeared in the GNU C library, and was implemented in
     FreeBSD 12.0.

BBUUGGSS
     The pprriinnttff family of functions do not correctly handle multibyte charac-
     ters in the _f_o_r_m_a_t argument.

SSEECCUURRIITTYY CCOONNSSIIDDEERRAATTIIOONNSS
     The sspprriinnttff() and vvsspprriinnttff() functions are easily misused in a manner
     which enables malicious users to arbitrarily change a running program's
     functionality through a buffer overflow attack.  Because sspprriinnttff() and
     vvsspprriinnttff() assume an infinitely long string, callers must be careful not
     to overflow the actual space; this is often hard to assure.  For safety,
     programmers should use the ssnnpprriinnttff() interface instead.  For example:

     void
     foo(const char *arbitrary_string, const char *and_another)
     {
             char onstack[8];

     #ifdef BAD
             /*
              * This first sprintf is bad behavior.  Do not use sprintf!
              */
             sprintf(onstack, "%s, %s", arbitrary_string, and_another);
     #else
             /*
              * The following two lines demonstrate better use of
              * snprintf().
              */
             snprintf(onstack, sizeof(onstack), "%s, %s", arbitrary_string,
                 and_another);
     #endif
     }

     The pprriinnttff() and sspprriinnttff() family of functions are also easily misused in
     a manner allowing malicious users to arbitrarily change a running pro-
     gram's functionality by either causing the program to print potentially
     sensitive data ``left on the stack'', or causing it to generate a memory
     fault or bus error by dereferencing an invalid pointer.

     %%nn can be used to write arbitrary data to potentially carefully-selected
     addresses.  Programmers are therefore strongly advised to never pass
     untrusted strings as the _f_o_r_m_a_t argument, as an attacker can put format
     specifiers in the string to mangle your stack, leading to a possible
     security hole.  This holds true even if the string was built using a
     function like ssnnpprriinnttff(), as the resulting string may still contain user-
     supplied conversion specifiers for later interpolation by pprriinnttff().

     Always use the proper secure idiom:

           snprintf(buffer, sizeof(buffer), "%s", string);

BSD                              May 22, 2018                              BSD
