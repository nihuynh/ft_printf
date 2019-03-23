/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:20:50 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/23 19:56:02 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ftmem.h"

int		form_character(va_list vl, t_data *data)
{
	ft_memset(&data->buff[data->idx], ' ', data->conf.rpad + data->conf.lpad + 1);
	data->buff[data->idx + data->conf.lpad] = (char)va_arg(vl, int);
	return (1 + data->conf.lpad + data->conf.rpad);
}
