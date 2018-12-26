/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:08 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/26 18:47:38 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		form_percent(va_list vl, t_data *data)
{
	(void)vl;
	data->buff[data->idx] = '%';
	return (1);
}