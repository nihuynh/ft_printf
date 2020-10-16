/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:02 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/16 18:53:05 by nihuynh          ###   ########.fr       */
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
	padding(t_data *data, t_config *cfg, long long carry, unsigned int len_num)
{
	unsigned int len_local;
	unsigned int zero_pad;

	len_num += (((cfg->flags & FLAG_SHOWSIGN) && carry >= 0) || carry < 0);
	if (cfg->width && cfg->width > cfg->prec)
	{
		len_local = (cfg->prec > len_num) ? cfg->prec - 1 : len_num;
		ft_memset(&data->buff[data->idx], ' ', cfg->width - len_local);
		data->idx += cfg->width - len_local;
	}
	if (cfg->space)
	{
		ft_memset(&data->buff[data->idx], ' ', cfg->space);
		data->idx += cfg->space - ((cfg->flags & FLAG_SHOWSIGN) || carry < 0);
	}
	if (((cfg->flags & FLAG_SHOWSIGN) && carry >= 0) || carry < 0)
		data->buff[data->idx++] = (carry < 0) ? '-' : '+';
	if (cfg->prec > len_num)
	{
		zero_pad = cfg->prec - len_num - !(carry < 0);
		ft_memset(&data->buff[data->idx], '0', zero_pad);
		data->idx += zero_pad;
	}
	if (cfg->zpad > len_num)
	{
		ft_memset(&data->buff[data->idx], '0', cfg->zpad - len_num);
		data->idx += cfg->zpad - len_num;
	}
}

int
	form_integer(va_list vl, t_data *d)
{
	int					res;
	unsigned int		len_num;
	long long			carry;
	unsigned long long	ucarry;

	res = 0;
	carry = cast(vl, &(d->conf));
	if (d->conf.prec == 1 && carry == 0)
		return (0);
	ucarry = (carry > 0) ? carry : -carry;
	len_num = ft_ulltob_base(ucarry, 10, (char *)&d->tmp, 0);
	padding(d, &d->conf, carry, len_num);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	if (d->conf.rpad > (len_num + 1))
	{
		ft_memset(&d->buff[d->idx + res], ' ', d->conf.rpad - len_num - (carry < 0));
		res += d->conf.rpad - len_num - (carry < 0);
	}
	return (res);
}
