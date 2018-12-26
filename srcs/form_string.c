/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:14 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/26 18:54:53 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ftstring.h"
#include "ft_printf.h"

int		form_string(va_list vl, t_data *data)
{
	char *tmp;

	tmp = (char *)va_arg(vl, char*);
	return (ft_strlcpy(&data->buff[data->idx], tmp, PF_BUFF - data->idx));
}