/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:20:50 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/24 15:01:50 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ftmem.h"

int		form_character(va_list vl, t_data *data)
{
	if (data->conf.lpad)
	{
		ft_memset(&data->buff[data->idx], ' ', data->conf.lpad--);
		data->idx += data->conf.lpad;
	}
	data->buff[data->idx] = (char)va_arg(vl, int);
	if (data->conf.rpad)
		ft_memset(&data->buff[data->idx + 1], ' ', data->conf.rpad--);
	return (1 + data->conf.rpad);
}
