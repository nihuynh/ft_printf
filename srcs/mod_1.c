/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:24:41 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/16 18:40:11 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_conv.h"
#include "ftconvert.h"
#include "ftctype.h"

int
	mod_hash(t_config *conf, char *format)
{
	(void)format;
	conf->flags |= (FLAG_HASH);
	return (1);
}

int
	mod_zero(t_config *conf, char *format)
{
	int offset;

	offset = 1;
	format++;
	conf->zpad = ft_atoi(format);
	if (*format == '+')
	{
		conf->flags |= (FLAG_SHOWSIGN);
		format++;
		offset++;
	}
	while (ft_isdigit((int)*format))
	{
		format++;
		offset++;
	}
	return (offset);
}

int
	mod_dot(t_config *conf, char *format)
{
	int offset;

	offset = 1;
	format++;
	conf->prec = ft_atoi(format) + 1;
	while (ft_isdigit((int)*format))
	{
		format++;
		offset++;
	}
	return (offset);
}

int
	mod_plus(t_config *conf, char *format)
{
	(void)format;
	conf->flags |= (FLAG_SHOWSIGN);
	return (1);
}

int
	mod_minus(t_config *conf, char *format)
{
	int offset;

	offset = 0;
	while (*format == '-')
	{
		format++;
		offset++;
	}
	conf->rpad = ft_atoi(format);
	while (ft_isdigit((int)*format))
	{
		format++;
		offset++;
	}
	return (offset);
}
