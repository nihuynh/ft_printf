/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:20:50 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/26 18:45:41 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		form_character(va_list vl, t_data *data)
{
	data->buff[data->idx] = (char)va_arg(vl, int);
	return (1);
}