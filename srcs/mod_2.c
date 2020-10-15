/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:09:22 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/15 19:31:28 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_conv.h"
#include "ftconvert.h"
#include "ftctype.h"

int
	mod_space(t_config *conf, char *format)
{
	int offset;

	offset = 1;
	format++;
	conf->space = ft_atoi(format) + 1;
	while (ft_isdigit((int)*format))
	{
		offset++;
		format++;
	}
	return (offset);
}

int
	mod_digit(t_config *conf, char *format)
{
	int offset;

	offset = 0;
	conf->width = ft_atoi(format);
	while (ft_isdigit((int)*format))
	{
		offset++;
		format++;
	}
	return (offset);
}

int
	mod_h(t_config *conf, char *format)
{
	format++;
	conf->flags |= (*format == 'h') ? (FLAG_HH) : (FLAG_H);
	return (1 + (*format == 'h'));
}

int
	mod_l(t_config *conf, char *format)
{
	format++;
	conf->flags |= (*format == 'l') ? (FLAG_LL) : (FLAG_L);
	return (1 + (*format == 'l'));
}

int
	mod_unkn(t_config *conf, char *format)
{
	(void)conf;
	(void)format;
	return (1);
}
