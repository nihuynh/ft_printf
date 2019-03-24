/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:02 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/24 16:29:37 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int		form_integer(va_list vl, t_data *d)
{
	int	res;
	int carry;

	res = 0;
	carry = (int)va_arg(vl, int);
	ft_itob_base(carry, 10, (char *)&d->tmp, 0);
	if ((d->conf.flags & FLAG_SHOWSIGN) && carry > 0)
		d->buff[d->idx++] = '+';
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}
