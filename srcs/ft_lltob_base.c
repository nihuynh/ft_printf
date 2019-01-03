/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltob_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:13:30 by nihuynh           #+#    #+#             */
/*   Updated: 2018/12/27 15:01:54 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_toupper(int c)
{
	return ((c >= 97 && c <= 122)) ? c - 32 : c;
}

int					ft_lltob_base(long long value, int base, char *bf, int upc)
{
	char				*bstr;
	int					idx;
	int					res;
	unsigned long long	carry;

	bstr = "0123456789abcdef";
	idx = (value < 0 && base == 10) ? 2 : 1;
	carry = (value > 0) ? value : -value;
	if (base < 2 || base > 16)
		return (-1);
	while (carry /= base)
		idx++;
	carry = (value > 0) ? value : -value;
	res = idx;
	bf[idx] = '\0';
	bf[0] = (value < 0 && base == 10) ? '-' : bstr[0];
	while (carry)
	{
		bf[--idx] = (upc) ? ft_toupper(bstr[carry % base]) : bstr[carry % base];
		carry /= base;
	}
	return (res);
}
