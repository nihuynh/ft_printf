/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 05:53:13 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include "ftstring.h"
#include "ftconvert.h"

static inline void flush_buff(t_data *data)
{
	write(1, &data->buff, data->idx);
	data->carry += data->idx;
	data->idx = 0;
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
	char	*tmp;

	offset = 1;
	while (format[offset] && !is_ending_flag(format[offset]))
		offset++;
	if (format[offset] == '\0')
		return (1);
	else if (format[offset] == 'c')
		d->buff[d->idx++] = (char)va_arg(vl, int);
	else if (format[offset] == '%')
		d->buff[d->idx++] = '%';
	else if (format[offset] == 's')
		d->idx += ft_strlcpy(&d->buff[d->idx], (char *)va_arg(vl, char*), PF_BUFF - d->idx);
	else if (format[offset] == 'd')
	{
		tmp = ft_itoa((int)va_arg(vl, int));
		d->idx += ft_strlcpy(&d->buff[d->idx], tmp, PF_BUFF - d->idx);
		ft_strdel(&tmp);
	}
	return (offset + 1);
}


int	ft_printf(const char *format, ...)
{
	va_list		vl;
	t_data		data;

	va_start(vl, format);
	data.carry = 0;
	data.idx = 0;
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