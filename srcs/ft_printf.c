/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:37:00 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 01:01:50 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

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

static inline void	init_parse(char key, t_config *config)
{
	int	type;
	const t_config index_config[] = {
		{'c', &putchar_buff}, {'s', &putstr_buff}, {'p', &putptr_buff}, {0, NULL}
	};

	type = 0;
	while (index_config[type].token != 0)
	{
		if (index_config[type].token == key)
			break;
		type++;
	}
	config = ft_memcpy(config, &index_config[type], sizeof(t_config));
}

static inline size_t ft_process(char *format, t_data *data)
{
	size_t	offset;

	offset = 1;
	while (!is_ending_flag(format[offset]))
	{
		// built the config
		offset++;
	}
	// choose the type of conversion
	// dispach to the correct function
	return (offset);
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
			format += ft_process(format, &data);
		else
			data.buff[data.idx++] = *format++;
		if (data.idx > BUFF_SIZE - 50 || data.buff[data.idx] == '\n')
			flush_buff(&data);
	}
	flush_buff(&data);
	va_end(vl);
	return (data.carry);
}