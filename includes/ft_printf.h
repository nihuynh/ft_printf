/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:32:54 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/25 06:05:02 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <string.h>

# define PF_BUFF	2048
# define CONF_FLAG	"#0+- "
# define MOD_FLAG	"hl"
# define END_FLAG	"diouxXDOUeEfFgGaACcSspn%"
# define MIN_FLAG	"cspdiouxXf%"

typedef struct	s_config
{
	int			space;
	int			left;
	int			showsign;
	int			is_long_double;
	int			is_short;
	int			is_char;
	int			is_long;
	int			width;
	int			prec;
	int			pad;
}				t_config;

typedef struct	s_data
{
	size_t		idx;
	size_t		carry;
	t_config	conf;
	char		buff[PF_BUFF];
	char		tmp[50];
}				t_data;

typedef struct	s_form
{
	char		token;
	int			(*convert)(va_list vl, t_data *data);
}				t_form;

#endif