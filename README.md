# ft_printf
Basic test	=	111/197		Fails
undefined	=	32/40		Fails
moulitest	=	41/48		Fails
Curqui		=	82/233		Pass

       Basic tests          2/2
       Conv d-i-D           20/40
       Conv u-U             0/26
       Conv o-O             13/34
       Conv x-X             13/39
       Conv c               8/8
       Conv C               1/22
       Conv s               11/15
       Conv S               2/23
       Conv p               0/7
       Percent              12/12
       Mixed tests          0/5
       ----------------------------
       TOTAL                82/233
       ----------------------------

	Modifier          d, i           o, u, x, X
	hh                signed char    unsigned char
	h                 short          unsigned short
	l (ell)           long           unsigned long
	ll (ell ell)      long long      unsigned long long

	Modifier    a, A, e, E, f, F, g, G
    l (ell)     double (ignored, same behavior as without it)
    L           long double

unsigned char
signed char
unsigned short
short
unsigned long
long
unsigned long long
long long
double
long double

flag_space			/* for ' ' */
flag_plus			/* for '+' */
flag_minus			/* for '-' */
flag_hash			/* for '#' */
flag_zero			/* for '0' */

width_asterics		/* for '*' */
width				/* for '1'...'9' */
precision			/* for '.' */

mod_half			/* for 'h' */
mod_halfhalf
mod_long			/* for 'l' */
mod_longlong
