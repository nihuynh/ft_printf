/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:11 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/23 18:10:34 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ftstring.h"
#include "ft_printf.h"
#include "ftmem.h"

int
	form_pointer(va_list vl, t_data *d)
{
	int				res;
	unsigned int	lenstr;

	lenstr = 2 + ft_lltob_base((long long)va_arg(vl, uintptr_t),
		16, (char *)&d->tmp, 0);
	if (d->conf.width > lenstr)
	{
		ft_memset(&d->buff[d->idx], ' ', d->conf.width - lenstr);
		d->idx += d->conf.width - lenstr;
	}
	d->idx += ft_strlcpy(&d->buff[d->idx], "0x", PF_BUFF - d->idx);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	if (d->conf.rpad > lenstr)
	{
		ft_memset(&d->buff[d->idx + res], ' ', d->conf.rpad - lenstr);
		d->idx += d->conf.rpad - lenstr;
    }
	return (res);
}
