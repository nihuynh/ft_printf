/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:05 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/03 15:56:28 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int		form_octal(va_list vl, t_data *d)
{
	int		res;

	ft_itob_base((int)va_arg(vl, int), 8, (char *)&d->tmp, 0);
	res = ft_strlcpy(&d->buff[d->idx], (const char *)&d->tmp, PF_BUFF - d->idx);
	return (res);
}
/*
void		print_o(t_bag *bag, va_list args, int *i)
{
	int len;
	char *str;
	char *res;
	long input;

	input = va_arg(args, long);
	if (input < 0)
		input = (unsigned long)input;
	str = ft_itoa2(input);
	printf("TRYING TO PRINT 4294967286: %s\n", str);
	len = ft_strlen(str);
	res = print_octal(str, &len);
	*i += len;
	write(1, res, len);
}

*/
