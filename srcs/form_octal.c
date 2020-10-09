/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:05 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/19 13:33:21 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int
	form_octal(va_list vl, t_data *d)
{
	int	res;

	ft_itob_base((int)va_arg(vl, int), 8, (char *)&d->tmp, 0);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}
