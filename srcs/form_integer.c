/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:02 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/26 18:54:34 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int		form_integer(va_list vl, t_data *d)
{
	int	res;

	ft_itob_base((int)va_arg(vl, int), 10, (char *)&d->tmp, 0);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}