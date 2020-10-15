/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:32:54 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/01 11:45:26 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>

# define PF_BUFF	2048
# define END_FLAG	"cspdiouxXf%"

# define FLAG_H			1
# define FLAG_HH		2
# define FLAG_L			4
# define FLAG_LL		8
# define FLAG_INTMAX	16
# define FLAG_SIZE_T	32
# define FLAG_UPCASE	64
# define FLAG_SHOWSIGN	128
# define FLAG_HASH		256

typedef struct s_data	t_data;

typedef struct		s_config
{
	char			conv;
	int				flags;
	unsigned int	space;
	unsigned int	prec;
	unsigned int	width;
	unsigned int	rpad;
	unsigned int	zpad;
}					t_config;

struct				s_data
{
	size_t			idx;
	size_t			carry;
	t_config		conf;
	char			buff[PF_BUFF];
	char			tmp[50];
};

void				flush_buff(t_data *data);
int					ft_itob_base(int value, int base, char *buff, int upcase);
int					ft_lltob_base(long long value, int base, char *bf, int upc);
int					ft_ulltob_base(unsigned long long value, int base, char *bf,
	int upc);

#endif
