/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 02:35:14 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/19 13:33:15 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <stdarg.h>
# include "ft_printf.h"

char		*ft_cut(char *str, int n);

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

static const t_conv g_conv[256] =
{
	['c'] = &form_character,
	['s'] = &form_string,
	['p'] = &form_pointer,
	['d'] = &form_integer,
	['D'] = &form_integer,
	['i'] = &form_integer,
	['o'] = &form_octal,
	['u'] = &form_unsigned,
	['U'] = &form_unsigned,
	['x'] = &form_hexa,
	['X'] = &form_hexa,
	['f'] = &form_float,
	['F'] = &form_float,
	['%'] = &form_percent,
	['O'] = &f_unkn,
	['e'] = &f_unkn,
	['E'] = &f_unkn,
	['g'] = &f_unkn,
	['G'] = &f_unkn,
	['a'] = &f_unkn,
	['A'] = &f_unkn,
	['C'] = &f_unkn,
	['S'] = &f_unkn,
	['n'] = &f_unkn
};

static const t_conv g_mod[256] =
{
	['#'] = &f_unkn,
	['0'] = &f_unkn,
	['.'] = &f_unkn,
	['+'] = &f_unkn,
	['-'] = &f_unkn,
	[' '] = &f_unkn,
	['1'] = &f_unkn,
	['2'] = &f_unkn,
	['3'] = &f_unkn,
	['4'] = &f_unkn,
	['5'] = &f_unkn,
	['6'] = &f_unkn,
	['7'] = &f_unkn,
	['8'] = &f_unkn,
	['9'] = &f_unkn,
	['h'] = &f_unkn,
	['H'] = &f_unkn,
	['l'] = &f_unkn,
	['L'] = &f_unkn,
	['j'] = &f_unkn,
	['J'] = &f_unkn,
	['z'] = &f_unkn,
	['Z'] = &f_unkn,
	['*'] = &f_unkn
};

#endif
