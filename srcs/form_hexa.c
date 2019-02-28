/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:20:58 by nihuynh           #+#    #+#             */
/*   Updated: 2019/02/28 15:59:51 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int		form_hexa(va_list vl, t_data *d)
{
	int	res;

	ft_itob_base((int)va_arg(vl, int),
					16,
					(char *)&d->tmp,
					!(d->conf.flags & FLAG_UPCASE));
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}
