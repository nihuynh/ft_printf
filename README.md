# ft_printf
Basic test	=	111/197		Fails
undefined	=	32/40		Fails
moulitest	=	41/48		Fails
Curqui		=	64/233		Pass

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
