/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 02:12:05 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include "libft.h"

static inline void flush_buff(t_data *data)
{
	write(1, &data->buff, data->idx);
	data->carry += data->idx;
	data->idx = 0;
}

static inline int is_ending_flag(char c)
{
	char *flags;

	flags = "cspdiouxXf%";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

static inline size_t ft_process(const char *format, t_data *d, va_list vl)
{
	size_t	offset;
	char	*tmp;

	offset = 1;
	while (format[offset] && !is_ending_flag(format[offset]))
		offset++;
	if (format[offset] == 'c')
		d->buff[d->idx++] = (char)va_arg(vl, int);
	else if (format[offset] == 's')
	{
		tmp = (char *)va_arg(vl, char*);
		d->idx += ft_strlcpy(&d->buff[d->idx], tmp, BUFF_SIZE - d->idx);
	}
	else if (format[offset] == 'd')
	{
		tmp = ft_itoa((int)va_arg(vl, int));
		d->idx += ft_strlcpy(&d->buff[d->idx], tmp, BUFF_SIZE - d->idx);
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
		if (data.idx > BUFF_SIZE - 50 || data.buff[data.idx] == '\n')
			flush_buff(&data);
	}
	flush_buff(&data);
	va_end(vl);
	return (data.carry);
}