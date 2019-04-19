/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/19 16:21:40 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_conv.h"
#include "ft_printf.h"
#include "ftmem.h"
#include "ftconvert.h"
#include "ftctype.h"


static inline void		flush_buff(t_data *data)
{
	write(1, &data->buff, data->idx);
	data->carry += data->idx;
	data->idx = 0;
}

static inline void		init_data(t_data *data)
{
	data->carry = 0;
	data->idx = 0;
}

size_t				format_parser(const char *format, t_data *d)
{
	size_t offset;

	offset = 1;
	while (format[offset] && (g_mod[(int)format[offset]]))
	{
		if (format[offset] == '0')
			d->conf.zpad = ft_atoi(&format[offset]);
		else if (ft_isdigit(format[offset]))
			d->conf.width = ft_atoi(&format[offset]);
		else if (format[offset] == '-')
		{
			while (format[offset] == '-')
				offset++;
			d->conf.rpad = ft_atoi(&format[offset]);
		}
		else if (format[offset] == ' ')
			d->conf.space = ft_atoi(&format[offset]);
		else if (format[offset] == '+')
			d->conf.flags |= (FLAG_SHOWSIGN);
		else if (format[offset] == '.')
			d->conf.prec = ft_atoi(&format[offset]);
		else if (format[offset] == '#')
			d->conf.flags |= (FLAG_HASH);
		else if (format[offset] == 'l')
			d->conf.flags |= (format[++offset] == 'l') ? (FLAG_LL) : (FLAG_L);
		else if (format[offset] == 'h')
			d->conf.flags |= (format[++offset] == 'h') ? (FLAG_HH) : (FLAG_H);
		if ((g_conv[(int)format[offset]]))
			break;
		offset++;
		while (ft_isdigit(format[offset]))
			offset++;
	}
	if (format[offset] >= 97 && format[offset] <= 122)
		d->conf.flags |= (FLAG_UPCASE);
	d->conf.conv = format[offset];
	return (offset);
}


/*
**	ft_process is the dispacher.
**	It built the config.
**	Invoke the right function to convert the va_arg.
**	return the offset to move in the format string.
*/

static inline size_t	ft_process(const char *format, t_data *d, va_list vl)
{
	size_t	offset;

	offset = 1;
	ft_bzero(&d->conf, sizeof(t_config));
	offset = format_parser(format, d);
	// while (format[offset] && (g_conv[(int)format[offset]] == NULL))
	// 	offset++;
	if (format[offset] == '\0')
		return (1);
	if (g_conv[(int)format[offset]])
		d->idx += g_conv[(int)format[offset]](vl, d);
	return (offset + 1);
}


int						ft_printf(const char *format, ...)
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
