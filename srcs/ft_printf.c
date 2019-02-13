/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2019/01/10 23:29:46 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include "ftmem.h"

static inline void flush_buff(t_data *data)
{
	write(1, &data->buff, data->idx);
	data->carry += data->idx;
	data->idx = 0;
}

static inline void init_data(t_data *data)
{
	data->carry = 0;
	data->idx = 0;
	ft_bzero(&data->conf, sizeof(t_config));
	data->table['c'] = &form_character;
	data->table['s'] = &form_string;
	data->table['p'] = &form_pointer;
	data->table['d'] = &form_integer;
	data->table['i'] = &form_integer;
	data->table['o'] = &form_octal;
	data->table['u'] = &form_unsigned;
	data->table['x'] = &form_hexa;
	data->table['X'] = &form_hexa;
	data->table['f'] = &form_float;
	data->table['%'] = &form_percent;
}

static inline int is_ending_flag(char c)
{
	char *flags;

	flags = END_FLAG;
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

/*
**	ft_process is the dispacher.
**	It built the config.
**	Invoke the right function to convert the va_arg.
**	return the offset to move in the format string.
*/


static inline size_t ft_process(const char *format, t_data *d, va_list vl)
{
	size_t	offset;

	offset = 1;
	while (format[offset] && !is_ending_flag(format[offset]))
		offset++;
	if (format[offset] == '\0')
		return (1);
	if (format[offset] >= 97 && format[offset] <= 122)
		d->conf.flags |= (FLAG_UPCASE);
	d->idx += d->table[(int)format[offset]](vl, d);
	return (offset + 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		vl;
	t_data		data;

	va_start(vl, format);
	init_data(&data);
	while (format && *format)
	{
		if (*format == '%')
			format += ft_process(format, &data, vl);
		else
			data.buff[data.idx++] = *format++;
		if (data.idx > PF_BUFF - 50)
			flush_buff(&data);
	}
	flush_buff(&data);
	va_end(vl);
	return (data.carry);
}