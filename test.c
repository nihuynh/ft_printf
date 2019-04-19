/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:21:43 by nihuynh           #+#    #+#             */
/*   Updated: 2019/04/19 17:05:33 by nihuynh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define PRINTF_TEST(fmt, ...) do { 											\
	int res = ft_printf(fmt, __VA_ARGS__);									\
	printf("$\033[50Gres = %d\033[70Gformat : %s\n", res, fmt);				\
	int epres = printf(fmt, __VA_ARGS__);									\
	printf("$\033[40G(printf)\033[50Gres = %d", epres);						\
	printf("\033[70GReturn value is %s\n", (res == epres) ? "good" : "bad");\
} while (0)
int	ft_printf(const char *format, ...);

int	weird_test()
{
	PRINTF_TEST("%20.15d\n", 54321);
	PRINTF_TEST("%-10d\n", 3);
	PRINTF_TEST("% d\n", 3);
	PRINTF_TEST("%+d\n", 3);
	PRINTF_TEST("%010d\n", 1);
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
	// s
	PRINTF_TEST("%.5s", "coco et titi");
	PRINTF_TEST("%15.3s", "Hello");
	PRINTF_TEST("%-15s", "Hello");
	// p
	PRINTF_TEST("%p", (void*) &var);
}

int        main(void)
{
    // weird_test();
    // basic_test();
	wip_test();
	while (0)
        ;
    return (0);
}
