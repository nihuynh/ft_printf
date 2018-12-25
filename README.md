# ft_printf

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


{'d', &buff_digit}, {'i', &buff_digit}, {'o', &buff_octal},
{'u', &buff_hex}, {'x', &buff_hex}, {'X', &buff_hex_up},
{'f', &buff_double}, {'d', &buff_double},
static inline void	init_parse(char key, t_config *config)
{
	int	type;
	const t_config index_config[] = {
		{'c', &putchar_buff}, {'s', &putstr_buff}, {'p', &putptr_buff}, {0, NULL}
	};

	type = 0;
	while (index_config[type].token != 0)
	{
		if (index_config[type].token == key)
			break;
		type++;
	}
	config = ft_memcpy(config, &index_config[type], sizeof(t_config));
}