/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:21:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/03/23 19:49:12 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define PRINTF_TEST(fmt, ...) do { ft_printf(fmt, __VA_ARGS__); printf("$\033[30GExpected : "); printf(fmt, __VA_ARGS__); puts("$");} while (0)
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
	PRINTF_TEST("%s", "Just a string arg");
	PRINTF_TEST("Enterlace %s", "string");
	PRINTF_TEST("%d", 5000);
	PRINTF_TEST("Enterlace %d", 5000);
	PRINTF_TEST("%c", 'w');
	PRINTF_TEST("Enterlace %c", 'q');
	PRINTF_TEST("%5c", 'c');
	PRINTF_TEST("%-5c", 'c');
}

int        main(void)
{
    // weird_test();
    basic_test();
    //ft_printf("%5%\n");
    //ft_printf("%-5%\n");
	while (0)
        ;
    return (0);
}