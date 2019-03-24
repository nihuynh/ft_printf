/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:13:30 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/24 16:56:10 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(char *bf, long long value, t_config *conf)
{
	int res;

	(void)bf;
	(void)value;
	(void)conf;
	res = 1;
	return (res);
}

int	uconv(char *bf, unsigned long long value, t_config *conf)
{
	int res;
	(void)bf;
	(void)value;
	(void)conf;
	res = 1;
	return (res);
}
