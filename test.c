/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:21:43 by nihuynh           #+#    #+#             */
/*   Updated: 2020/10/16 18:48:15 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define LEAK 0

#define PRINTF_TEST(fmt, ...) do { 											\
	int res = ft_printf(fmt, __VA_ARGS__);									\
	printf("$\033[50Gres = %d\033[70Gformat : %s\n", res, fmt);				\
	int epres = printf(fmt, __VA_ARGS__);									\
	printf("$\033[40G(printf)\033[50Gres = %d", epres);						\
	printf("\033[70GReturn value is %s\n-------------------------------\n", \
	(res == epres) ? "\033[0;32mgood\033[0m" : "\033[;31mbad\033[0m");		\
} while (0)
int	ft_printf(const char *format, ...);

int	weird_test()
{
	PRINTF_TEST("%-10d\n", 3);
	PRINTF_TEST("% d\n", 3);
	PRINTF_TEST("%+d\n", 3);
	PRINTF_TEST("%010d\n", 1);
	return (0);
}

int	moulitest()
{
	// PRINTF_TEST("%5d", 42);
	// PRINTF_TEST("%05d", 42);
	// PRINTF_TEST("%5d", -741);
	// PRINTF_TEST("%08i", -71);
	// PRINTF_TEST("%.5d", -421);
	// PRINTF_TEST("%.12d", 1144);
	// PRINTF_TEST("%0+5d", 42);
	// PRINTF_TEST("%0+5d", -42);
	// PRINTF_TEST("%-5d", -42);
	// PRINTF_TEST("%-7d", 7789);

	PRINTF_TEST("%-7d", 7789);
	PRINTF_TEST("%-7d", 7789);
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

void	wip_test(void)
{
	int var;

	var = 42;
	// diD
	// PRINTF_TEST("%.d", 0);
	PRINTF_TEST("%+12.5d", 140);
	PRINTF_TEST("%00+10.4d", 0);
	PRINTF_TEST("%20.ld et %.4hhi !", 0x11ffaa147, (signed char)-8);
	PRINTF_TEST("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345);
	PRINTF_TEST("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
}

void	segv_test(void)
{
	int var;

	var = 42;
	// diD
	// PRINTF_TEST("%00+10.4d", 0);s
}

int        main(void)
{
	// moulitest();
	// basic_test();
	// weird_test();
	wip_test();
	// segv_test();
	while (LEAK)
		;
	return (0);
}
