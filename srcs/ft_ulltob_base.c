/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltob_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:13:30 by nihuynh           #+#    #+#             */
/*   Updated: 2019/05/01 11:39:39 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int
	ft_toupper(int c)
{
	return ((c >= 97 && c <= 122)) ? c - 32 : c;
}

int
	ft_ulltob_base(unsigned long long value, int base, char *bf, int upc)
{
	char				*bstr;
	int					idx;
	int					res;
	unsigned long long	carry;

	bstr = "0123456789abcdef";
	idx = 1;
	carry = value;
	if (base < 2 || base > 16)
		return (-1);
	while (carry /= base)
		idx++;
	carry = value;
	res = idx;
	bf[idx] = '\0';
	bf[0] = bstr[0];
	while (carry)
	{
		bf[--idx] = (upc) ? ft_toupper(bstr[carry % base]) : bstr[carry % base];
		carry /= base;
	}
	return (res);
}
