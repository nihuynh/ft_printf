/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:14 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/19 17:03:09 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"
#include "ftmem.h"

int        form_string(va_list vl, t_data *data)
{
    char            *str;
    unsigned int    res;
    unsigned int    lenstr;

	str = (char *)va_arg(vl, char*);
	if (str == NULL)
		str = "(null)";
	lenstr = ft_strlen(str);
	if ((data->conf.prec > 0) && (data->conf.prec < lenstr))
		lenstr = data->conf.prec;
	if (lenstr > PF_BUFF - data->idx)
		flush_buff(data);
	if (data->conf.width > lenstr)
	{
		ft_memset(&data->buff[data->idx], ' ', data->conf.width - lenstr);
		data->idx += data->conf.width - lenstr;
	}
	res = lenstr;
	ft_strncpy(&data->buff[data->idx], str, lenstr);
	if (data->conf.rpad > lenstr)
	{
		ft_memset(&data->buff[data->idx + res], ' ', data->conf.rpad - lenstr);
		data->idx += data->conf.rpad - lenstr;
    }
    return (res);
}
