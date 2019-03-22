/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwepifa <erwepifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:21:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/22 15:31:23 by erwepifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *format, ...);

int	weird_test()
{
	printf("%20.15d\n", 54321);
	printf("%-10d\n", 3);
	printf("% d\n", 3);
	printf("%+d\n", 3);
	printf("%010d\n", 1);
	return (0);
}

void	basic_test(void)
{
	/*
	ft_printf("Just a string\n");
	ft_printf("%s\n", "Just a string arg");
	ft_printf("Enterlace %s\n", "string");
	ft_printf("%d\n", 5000);
	ft_printf("Enterlace %d\n", 5000);
	ft_printf("%c\n", 'w');
	ft_printf("Enterlace %c\n", 'q');
	*/
	ft_printf("%5%");
	printf("%#x", 42);
	
}

int        main(void)
{
    //weird_test();
    basic_test();
    while (0)
        ;
    return (0);
}