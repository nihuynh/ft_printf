/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:02 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/01 12:28:11 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"
#include "ftmem.h"

static inline long long
	cast(va_list vl, t_config *cfg)
{
	long long carry;

	if (cfg->conv == 'D' || (cfg->flags & FLAG_LL))
		carry = va_arg(vl, long long);
	else if (cfg->flags & FLAG_L)
		carry = va_arg(vl, long);
	else if (cfg->flags & FLAG_H)
		carry = (short)va_arg(vl, int);
	else if (cfg->flags & FLAG_HH)
		carry = (char)va_arg(vl, int);
	else
		carry = va_arg(vl, int);
	return (carry);
}

static inline void
	padding(t_data *data, t_config *cfg, long long carry, int len_num)
{
	if (data->conf.width)
	{
		ft_memset(&data->buff[data->idx], ' ', data->conf.width - len_num - 1);
		data->idx += data->conf.width - len_num - 1;
	}
	if (cfg->space)
	{
		ft_memset(&data->buff[data->idx], ' ', cfg->space);
		data->idx += cfg->space;
	}
	if (((cfg->flags & FLAG_SHOWSIGN) && carry >= 0) || carry < 0)
		data->buff[data->idx++] = (carry < 0) ? '-' : '+';
	if (cfg->prec > (unsigned int)len_num)
	{
		ft_memset(&data->buff[data->idx], '0', cfg->prec - len_num - 1);
		data->idx += cfg->prec - len_num - 1;
	}
	if (cfg->zpad > (unsigned int)len_num)
	{
		ft_memset(&data->buff[data->idx], '0', cfg->zpad - len_num);
		data->idx += cfg->zpad - len_num - (carry != 0);
	}
}

int
	form_integer(va_list vl, t_data *d)
{
	int			res;
	int			len_num;
	long long	carry;
	long long	ucarry;

	res = 0;
	carry = cast(vl, &(d->conf));
	if (d->conf.prec == 1 && carry == 0)
		return (0);
	ucarry = (carry > 0) ? carry : -carry;
	len_num = ft_lltob_base(ucarry, 10, (char *)&d->tmp, 0);
	padding(d, &d->conf, carry, len_num);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	if (d->conf.rpad > (unsigned int)(len_num + 1))
	{
		ft_memset(&d->buff[d->idx + res], ' ', d->conf.rpad - len_num);
		res += d->conf.rpad - len_num;
	}
	return (res);
}
