/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/15 19:30:41 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_conv.h"
#include "ft_printf.h"
#include "ftmem.h"

/*
**	Write the data of the buffer into stdout.
**	Place the write char count into the carry
**	to handle the return value of printf.
**	Reset the idx value so the next data is at the start of the buffer.
*/

void
	flush_buff(t_data *data)
{
	write(1, &data->buff, data->idx);
	data->carry += data->idx;
	data->idx = 0;
}

static inline void
	init_data(t_data *data)
{
	data->carry = 0;
	data->idx = 0;
}

/*
**	Read the format between the % and the conversion char.
**	It built the config.
**	Return the offset between the % abd the conv char
**	TODO: Make uses the g_mod to avoid the if else.
*/

size_t
	format_parser(const char *format, t_data *d)
{
	size_t	offset;
	t_mod	mod_fn;

	offset = 1;
	while (format[offset] && (g_mod[(int)format[offset]]))
	{
		mod_fn = g_mod[(int)format[offset]];
		if (mod_fn)
			offset += mod_fn(&d->conf, (char *)&format[offset]);
		if ((g_conv[(int)format[offset]]))
			break ;
	}
	if (format[offset] >= 97 && format[offset] <= 122)
		d->conf.flags |= (FLAG_UPCASE);
	d->conf.conv = format[offset];
	return (offset);
}

/*
**	ft_process is the dispacher.
**	Invoke the right function to convert the va_arg.
**	return the offset to move in the format string.
*/

static inline size_t
	ft_process(const char *format, t_data *d, va_list vl)
{
	size_t	offset;
	char	conv_char;
	t_conv	conversion_fn;

	offset = 1;
	ft_bzero(&d->conf, sizeof(t_config));
	offset = format_parser(format, d);
	conv_char = format[offset];
	if (conv_char == '\0')
		return (1);
	conversion_fn = g_conv[(int)conv_char];
	if (conversion_fn)
		d->idx += conversion_fn(vl, d);
	return (offset + 1);
}

/*
**	Main loop
**	Flush the buffer if there is less than 50 char remaining.
**	Return the carry value. (Number of char written in stdout)
*/

int
	ft_printf(const char *format, ...)
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
