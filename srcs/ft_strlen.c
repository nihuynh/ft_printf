/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 10:22:40 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 06:16:34 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

size_t
	ft_strlen(char const *str)
{
	char *pstr;

	pstr = (char*)str;
	while (*pstr)
		pstr++;
	return ((size_t)(pstr - str));
}
