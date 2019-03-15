/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/15 15:49:35 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_conv.h"
#include "ft_printf.h"
#include "ftmem.h"

int		ft_atoi(const	char *str)
{
	int	result;
	int	neg;

	neg = 1;
	result = 0;
	while (*str == '\v' || *str == '\f' || *str == '\r' || *str == '\t'
			|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (neg == -1)
			result = (result * 10) - (*str - 48);
		else
			result = (result * 10) + (*str - 48);
		str++;
	}
	return (result);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

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

static inline int		is_ending_flag(char c)
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

static size_t				format_parser(const char *format, t_data *d)
{
	size_t offset;

	offset = 1;
	while (format[offset] && !is_ending_flag(format[offset]))
	{
		if (ft_isdigit(format[offset]))
			d->conf.lpad = ft_atoi(&format[++offset]);
		if (format[offset] == '-')
			d->conf.rpad = ft_atoi(&format[++offset]);
		if (format[offset] == ' ')
			d->conf.space = ft_atoi(&format[++offset]);
		// '+'
		/*
		if (format[offset] == '+')
			d->
		// '0'
		// '#'
		if (format[offset] == '#')
			d->
			*/
		// 'l'
		// 'h'

	
		while (ft_isdigit(format[offset]))
			offset++;
	}
	if (format[offset] >= 97 && format[offset] <= 122)
		d->conf.flags |= (FLAG_UPCASE);
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

	ft_bzero(&d->conf, sizeof(t_config));
	offset = format_parser(format, d);
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
