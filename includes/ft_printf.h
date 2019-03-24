/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 04:32:54 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/24 16:01:17 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>

# define PF_BUFF	2048
# define END_FLAG	"cspdiouxXf%"

# define FLAG_HALF		(1UL)
# define FLAG_HALFHALF	(1UL << 1)
# define FLAG_LONG		(1UL << 2)
# define FLAG_LONGLONG	(1UL << 3)
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
	unsigned int	width;
	unsigned int	prec;
	unsigned int	lpad;
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

int					ft_itob_base(int value, int base, char *buff, int upcase);
int					conv(char *bf, long long value, t_config *conf);
int					uconv(char *bf, unsigned long long value, t_config *conf);


#endif
