/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 02:35:14 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/15 18:32:59 by nihuynh          ###   ########.fr       */
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

typedef int	(*t_mod)(t_config *conf, char *format);

int			mod_hash(t_config *conf, char *format);
int			mod_zero(t_config *conf, char *format);
int			mod_dot(t_config *conf, char *format);
int			mod_plus(t_config *conf, char *format);
int			mod_minus(t_config *conf, char *format);
int			mod_space(t_config *conf, char *format);
int			mod_digit(t_config *conf, char *format);
int			mod_h(t_config *conf, char *format);
int			mod_l(t_config *conf, char *format);

int			mod_unkn(t_config *conf, char *format);

static const t_mod g_mod[256] =
{
	['#'] = &mod_hash,
	['0'] = &mod_zero,
	['.'] = &mod_dot,
	['+'] = &mod_plus,
	['-'] = &mod_minus,
	[' '] = &mod_space,
	['1'] = &mod_digit,
	['2'] = &mod_digit,
	['3'] = &mod_digit,
	['4'] = &mod_digit,
	['5'] = &mod_digit,
	['6'] = &mod_digit,
	['7'] = &mod_digit,
	['8'] = &mod_digit,
	['9'] = &mod_digit,
	['h'] = &mod_h,
	['l'] = &mod_l,
	['H'] = &mod_unkn,
	['L'] = &mod_unkn,
	['j'] = &mod_unkn,
	['J'] = &mod_unkn,
	['z'] = &mod_unkn,
	['Z'] = &mod_unkn,
	['*'] = &mod_unkn
};

#endif
