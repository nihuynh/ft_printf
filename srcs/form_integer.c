/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:02 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/22 12:44:39 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"
#include "ftmem.h"

int		form_integer(va_list vl, t_data *d)
{
	int			res;
	int			len_num;
	long long	carry;

	res = 0;
	if (d->conf.conv == 'D' || (d->conf.flags & FLAG_LL))
		carry = va_arg(vl, long long);
	else if (d->conf.flags & FLAG_L)
		carry = va_arg(vl, long);
	else if (d->conf.flags & FLAG_H)
		carry = (short)va_arg(vl, int);
	else if (d->conf.flags & FLAG_HH)
		carry = (char)va_arg(vl, int);
	else
		carry = va_arg(vl, int);
	len_num = ft_lltob_base(carry, 10, (char *)&d->tmp, 0);
	if (d->conf.space)
	{
		ft_memset(&d->buff[d->idx], ' ', d->conf.space);
		d->idx += d->conf.space;
	}
	if ((d->conf.flags & FLAG_SHOWSIGN) && carry >= 0)
		d->buff[d->idx++] = '+';
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}
