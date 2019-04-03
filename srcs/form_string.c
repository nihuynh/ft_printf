/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:14 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/03 16:38:13 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"
#include "ftmem.h"

char		*ft_cut(char *str, int n)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (n >= len)
		return ("");
	new = ft_strnew(len - n);
	i = 0;
	while (i < (len - n))
	new[i++] = *str++;
		return (new);
}

int        form_string(va_list vl, t_data *data)
{
    char            *tmp;
    unsigned int    res;
    unsigned int    tmplen;
		char						*new;

		new = "";
		tmp = (char *)va_arg(vl, char*);
		tmplen = ft_strlen(tmp);
		if (data->conf.prec < tmplen)
			new = ft_cut(new, tmplen - data->conf.prec);
		if (data->conf.lpad > tmplen)
		{
			ft_memset(&data->buff[data->idx], ' ', data->conf.lpad - tmplen);
			data->idx += data->conf.lpad - tmplen;
		}
		res = ft_strlcpy(&data->buff[data->idx], tmp, PF_BUFF - data->idx);
		if (data->conf.rpad > tmplen)
		{
			ft_memset(&data->buff[data->idx + res], ' ', data->conf.rpad - tmplen);
			data->idx += data->conf.rpad - tmplen;
			//return (data->conf.rpad);
    }
    return (res);
}
