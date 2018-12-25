/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:32:54 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 01:02:15 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>

# define BUFF_SIZE	2048

typedef struct	s_data
{
	size_t		idx;
	size_t		carry;
	char		buff[BUFF_SIZE];
	char		tmp[50];
}				t_data;

typedef struct	s_config
{
	char		token;
	int			(*convert)(va_list vl, t_data *data);
}				t_config;

#endif