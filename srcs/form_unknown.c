/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_unknown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 18:21:16 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/26 18:53:46 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		form_unknown(va_list vl, t_data *data)
{
	(void)vl;
	(void)data;
	return (1);
}