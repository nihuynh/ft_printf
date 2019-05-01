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

# define FLAG_H			(1UL)
# define FLAG_HH		(1UL << 1)
# define FLAG_L			(1UL << 2)
# define FLAG_LL		(1UL << 3)
# define FLAG_INTMAX	(1UL << 4)
# define FLAG_SIZE_T	(1UL << 5)
# define FLAG_UPCASE	(1UL << 6)
# define FLAG_SHOWSIGN	(1UL << 7)
# define FLAG_HASH		(1UL << 8)

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
