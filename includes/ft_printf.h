/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:32:54 by nihuynh           #+#    #+#             */
/*   Updated: 2019/02/16 15:20:54 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>
#include <stdarg.h>

# define PF_BUFF	2048
# define CONF_FLAG	"#0+- "
# define MOD_FLAG	"hl"
# define MIN_FLAG	"diouxXDOUeEfFgGaACcSspn%"
# define END_FLAG	"cspdiouxXf%"

# define FLAG_HALF		(1UL)
# define FLAG_HALFHALF	(1UL << 1)
# define FLAG_LONG		(1UL << 2)
# define FLAG_LONGLONG	(1UL << 3)
# define FLAG_INTMAX	(1UL << 4)
# define FLAG_SIZE_T	(1UL << 5)
# define FLAG_UPCASE	(1UL << 6)
# define FLAG_SHOWSIGN	(1UL << 7)

typedef struct s_data	t_data;

typedef struct	s_config
{
	char	flags;
	int		space;
	int		width;
	int		prec;
	int		lpad;
	int		rpad;
}				t_config;

struct			s_data
{
	size_t		idx;
	size_t		carry;
	t_config	conf;
	char		buff[PF_BUFF];
	char		tmp[50];
};

int				ft_itob_base(int value, int base, char *buff, int upcase);

// int				form_unknown(va_list vl, t_data *data);
// int				form_percent(va_list vl, t_data *data);
// int				form_integer(va_list vl, t_data *data);
// int				form_unsigned(va_list vl, t_data *data);
// int				form_octal(va_list vl, t_data *data);
// int				form_hexa(va_list vl, t_data *data);
// int				form_float(va_list vl, t_data *data);
// int				form_character(va_list vl, t_data *data);
// int				form_string(va_list vl, t_data *data);
// int				form_pointer(va_list vl, t_data *data);

#endif