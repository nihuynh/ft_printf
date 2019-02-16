/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 02:35:14 by nihuynh           #+#    #+#             */
/*   Updated: 2019/02/16 15:37:10 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <stdarg.h>
# include "ft_printf.h"

int			f_unkn(va_list vl, t_data *data);
int			form_percent(va_list vl, t_data *data);
int			form_integer(va_list vl, t_data *data);
int			form_unsigned(va_list vl, t_data *data);
int			form_octal(va_list vl, t_data *data);
int			form_hexa(va_list vl, t_data *data);
int			form_float(va_list vl, t_data *data);
int			form_character(va_list vl, t_data *data);
int			form_string(va_list vl, t_data *data);
int			form_pointer(va_list vl, t_data *data);

typedef int	(*t_conv)(va_list vl, t_data *data);

const t_conv g_dispach[128] =
{
	['c'] = &form_character,
	['s'] = &form_string,
	['p'] = &form_pointer,
	['d'] = &form_integer,
	['i'] = &form_integer,
	['o'] = &form_octal,
	['u'] = &form_unsigned,
	['x'] = &form_hexa,
	['X'] = &form_hexa,
	['f'] = &form_float,
	['%'] = &form_percent
};

#endif
