/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:29:13 by spuustin          #+#    #+#             */
/*   Updated: 2022/04/13 12:51:17 by spuustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>


static void string_test()
{
	char *str1 = "vaapukka";
	char *str2 = "mehu";
	 int ret1, ret2;
	ret1 = printf("norm:printing a string from pointer: %s\n", str1);
	ret2 = ft_printf("mine:printing a string from pointer: %s\n", str1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:printing null: %s\n", NULL);
	ret2 = ft_printf("mine:printing null: %s\n", NULL);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:printing two strings: %s%s\n", str1, str2);
	ret2 = ft_printf("mine:printing two strings: %s%s\n", str1, str2);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.2s is a string\n", "this");
	ret2 = ft_printf("mine:%.2s is a string\n", "this");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.2s is a string\n", "");
	ret2 = ft_printf("mine:%.2s is a string\n", "");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%-.2s is a string\n", "this");
	ret2 = ft_printf("mine:%-.2s is a string\n", "this");
	printf("%d %d\n", ret1, ret2);
}
static void char_test()
{
	char a = 'a';
	char b = 'b';
	int ret1, ret2;
	ret1 = printf("norm:%c\n", a);
	ret2 = ft_printf("mine:%c\n", a);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:printing two chars: %c %c\n", a, b);
	ret2 = ft_printf("mine:printing two chars: %c %c\n", a, b);
	printf("%d %d\n", ret1, ret2);
}

static void d_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%d\n", n);
	ret2 = ft_printf("mine:%d\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%d %d %d\n", 42242, -2442424, 0);
	ret2 = ft_printf("mine:%d %d %d\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8d\n", -42);
	ret2 = ft_printf("mine:%8d\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5d\n", -42);
	ret2 = ft_printf("mine:%5d\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0+5d\n", -42);
	ret2 = ft_printf("mine:%0+5d\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1d\n", 1);
	ret2 = ft_printf("mine:%03.1d\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3d\n", -0);
	ret2 = ft_printf("mine:%3d\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void dl_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%ld\n", n);
	ret2 = ft_printf("mine:%ld\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%ld %.0ld %.ld\n", 0, -0, 0);
	ret2 = ft_printf("mine:%ld %.0ld %.ld\n", 0, -0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8ld\n", 42121212121212);
	ret2 = ft_printf("mine:%8ld\n", 42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5ld\n", -42121212121212);
	ret2 = ft_printf("mine:%5ld\n", -42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0+5ld\n", -42);
	ret2 = ft_printf("mine:%0+5ld\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1ld\n", 1);
	ret2 = ft_printf("mine:%03.1ld\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3ld\n", -0);
	ret2 = ft_printf("mine:%3ld\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void dll_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%lld\n", n);
	ret2 = ft_printf("mine:%lld\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%lld %.0lld %.lld\n", 0, -0, 0);
	ret2 = ft_printf("mine:%lld %.0lld %.lld\n", 0, -0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8lld\n", -42);
	ret2 = ft_printf("mine:%8lld\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5lld\n", 42121212121212);
	ret2 = ft_printf("mine:%5lld\n", 42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%05lld\n", -42121212121212);
	ret2 = ft_printf("mine:%05lld\n", -42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1lld\n", 1);
	ret2 = ft_printf("mine:%03.1lld\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3lld\n", -0);
	ret2 = ft_printf("mine:%3lld\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void dh_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%hd\n", n);
	ret2 = ft_printf("mine:%hd\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%hd %.0hd %.hd\n", 0, -0, 0);
	ret2 = ft_printf("mine:%hd %.0hd %.hd\n", 0, -0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8hd\n", -42);
	ret2 = ft_printf("mine:%8hd\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5hd\n", 42121212121212);
	ret2 = ft_printf("mine:%5hd\n", 42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%05hd\n", -42121212121212);
	ret2 = ft_printf("mine:%05hd\n", -42121212121212);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1hd\n", 1);
	ret2 = ft_printf("mine:%03.1hd\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3hd\n", -0);
	ret2 = ft_printf("mine:%3hd\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void dhh_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%hhd\n", m);
	ret2 = ft_printf("mine:%hhd\n", m);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%hhd %.0hhd %.hhd\n", 0, -0, 0);
	ret2 = ft_printf("mine:%hhd %.0hhd %.hhd\n", 0, -0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8hhd\n", -42);
	ret2 = ft_printf("mine:%8hhd\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5hhd\n", 1212121121221);
	ret2 = ft_printf("mine:%5hhd\n", 1212121121221);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.hhd\n", -1212121121221);
	ret2 = ft_printf("mine:%.hhd\n", -1212121121221);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1hhd\n", 1);
	ret2 = ft_printf("mine:%03.1hhd\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3hhd\n", -0);
	ret2 = ft_printf("mine:%3hhd\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void i_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%i\n", n);
	ret2 = ft_printf("mine:%i\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%i %i %i\n", 42242, -2442424, 0);
	ret2 = ft_printf("mine:%i %i %i\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8i\n", -42);
	ret2 = ft_printf("mine:%8i\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5i\n", -42);
	ret2 = ft_printf("mine:%5i\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0+5i\n", -42);
	ret2 = ft_printf("mine:%0+5i\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1i\n", 1);
	ret2 = ft_printf("mine:%03.1i\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3i\n", -0);
	ret2 = ft_printf("mine:%3i\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void u_test()
{
	int ret1, ret2;
	ret1 = printf("norm:%u\n", 4294967295);
	ret2 = ft_printf("mine:%u\n", 4294967295);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%u\n", -4294967295);
	ret2 = ft_printf("mine:%u\n", -4294967295);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8u\n", -42);
	ret2 = ft_printf("mine:%8u\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5u\n", -42);
	ret2 = ft_printf("mine:%5u\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0+5u\n", -42);
	ret2 = ft_printf("mine:%0+5u\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%03.1u\n", 1);
	ret2 = ft_printf("mine:%03.1u\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3u\n", -0);
	ret2 = ft_printf("mine:%3u\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void o_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%o\n", n);
	ret2 = ft_printf("mine:%o\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5o\n", 2500);
	ret2 = ft_printf("mine:%5o\n", 2500);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%2.5o\n", 0);
	ret2 = ft_printf("mine:%2.5o\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%o\n", n);
	ret2 = ft_printf("mine:%o\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%o\n", 214748364793324242);
	ret2 = ft_printf("mine:%o\n", 214748364793324242);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%10o\n", 42);
	ret2 = ft_printf("mine:%10o\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#12.12o\n", 2323232);
	ret2 = ft_printf("mine:%0#12.12o\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%4.5o\n", 343434);
	ret2 = ft_printf("mine:%4.5o\n", 343434);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3o\n", 2323232);
	ret2 = ft_printf("mine:%0#10.3o\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3.10o\n", 2323232);
	ret2 = ft_printf("mine:%3.10o\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3o\n", 0);
	ret2 = ft_printf("mine:%0#10.3o\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3o\n", 0);
	ret2 = ft_printf("mine:%3o\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#.o\n", 0);
	ret2 = ft_printf("mine:%#.o\n", 0);
	printf("%d %d\n", ret1, ret2);
}

static void ohh_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%hho\n", n);
	ret2 = ft_printf("mine:%hho\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5hho\n", 2500);
	ret2 = ft_printf("mine:%5hho\n", 2500);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%2.5hho\n", 0);
	ret2 = ft_printf("mine:%2.5hho\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%hho\n", n);
	ret2 = ft_printf("mine:%hho\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%hho\n", 214748364793324242);
	ret2 = ft_printf("mine:%hho\n", 214748364793324242);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%10hho\n", 42);
	ret2 = ft_printf("mine:%10hho\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#12.12hho\n", 2323232);
	ret2 = ft_printf("mine:%0#12.12hho\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%4.5hho\n", 343434);
	ret2 = ft_printf("mine:%4.5hho\n", 343434);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3hho\n", 2323232);
	ret2 = ft_printf("mine:%0#10.3hho\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3.10hho\n", 2323232);
	ret2 = ft_printf("mine:%3.10hho\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3hho\n", 0);
	ret2 = ft_printf("mine:%0#10.3hho\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3hho\n", 0);
	ret2 = ft_printf("mine:%3hho\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%hho\n", 0);
	ret2 = ft_printf("mine:%hho\n", 0);
	printf("%d %d\n", ret1, ret2);
}

static void x_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%2.5x\n", 0);
	ret2 = ft_printf("mine:%2.5x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%x\n", n);
	ret2 = ft_printf("mine:%x\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%x\n", 4294967296);
	ret2 = ft_printf("mine:%x\n", 4294967296);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%10x\n", 42);
	ret2 = ft_printf("mine:%10x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.10x\n", 2323232);
	ret2 = ft_printf("mine:%0#10.10x\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#10.x\n", 2323232);
	ret2 = ft_printf("mine:%#10.x\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3x\n", 2323232);
	ret2 = ft_printf("mine:%0#10.3x\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#3.10x\n", 2323232);
	ret2 = ft_printf("mine:%#3.10x\n", 2323232);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%0#10.3x\n", 0);
	ret2 = ft_printf("mine:%0#10.3x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%3x\n", 0);
	ret2 = ft_printf("mine:%3x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%x\n", 0);
	ret2 = ft_printf("mine:%x\n", 0);
	printf("%d %d\n", ret1, ret2);
}

static void o_hash_test()
{
	int ret1, ret2;
	ret1 = printf("norm:@moulitest: %#x %#o\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %#x %#o\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:@moulitest: %#.o %#.0o\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %#.o %#.0o\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#x\n", 0);
	ret2  = ft_printf("mine:%#x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:@moulitest: %#.x %#.0x|\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %#.x %#.0x|\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
}

static void xX_hash_test()
{
	int ret1, ret2;
	ret1 = printf("norm:%#x\n", 0);
	ret2 = ft_printf("mine:%#x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#8x\n", 42);
	ret2 = ft_printf("mine:%#8x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:@moulitest: %#.x %#.0x\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %#.x %#.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:@moulitest: %.x %.0x\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %.x %.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:@moulitest: %5.x %5.0x\n", 0, 0);
	ret2 = ft_printf("mine:@moulitest: %5.x %5.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#08x\n", 42);
	ret2 = ft_printf("mine:%#08x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#-08x\n", 42);
	ret2 = ft_printf("mine:%#-08x\n", 42);
	printf("%d %d\n", ret1, ret2);
}

static void X_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%X\n", n);
	ret2 = ft_printf("mine:%X\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%X %X %X\n", 42242, -2442424, 0);
	ret2 = ft_printf("mine:%X %X %X\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
}
static void percent_test()
{
	int ret1, ret2;
	ret1 = printf("norm:%%\n");
	ret2 = ft_printf("mine:%%\n");
	printf("%d %d\n", ret1, ret2);
}
static void ellas_tests()
{
	int ret1,ret2;

	ret1 = printf("norm:%ld\n", 922337203685477580);
	ret2 = ft_printf("mine:%ld\n", 922337203685477580);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("norm:%lld\n", -922337203685477580);
	ret2 = ft_printf("mine:%lld\n", -922337203685477580);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("norm:%-015.8d\n", 1000000);
	ret2 = ft_printf("mine:%-015.8d\n", 1000000);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%.d %.0d\n", 42, 43);
	ret2 = ft_printf("mine:%.d %.0d\n", 42, 43);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%.d %.0d\n", 0, 0);
	ret2 = ft_printf("mine:%.d %.0d\n", 0, 0);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("mine:'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("mine:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("mine:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("norm:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	ret2 = ft_printf("mine:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("norm:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("mine:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%5.x %5.0x\n", 0, 0);
	ret2 = ft_printf("mine:%5.x %5.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%.x %.0x\n", 0, 0);
	ret2 = ft_printf("mine:%.x %.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%5.x %5.0x\n", 0, 0);
	ret2 = ft_printf("mine:%5.x %5.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%\n");
	ret2 = ft_printf("mine:%\n");
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%%\n");
	ret2 = ft_printf("mine:%%\n");
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%stest\n", NULL);
	ret2 = ft_printf("mine:%stest\n", NULL);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("norm:%.5s\n", NULL);
	ret2 = ft_printf("mine:%.5s\n", NULL);
	printf("%d %d\n", ret1, ret2);

	ret1 = printf("norm:%s\n", NULL);
	ret2 = ft_printf("mine:%s\n", NULL);
	printf("%d %d\n", ret1, ret2);
}

void	float_test()
{
	int ret1, ret2;
	ret1 = printf("norm:%f\n", 3.5);
	ret2 = ft_printf("mine:%f\n", 3.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.0f\n", 3.5);
	ret2 = ft_printf("mine:%.0f\n", 3.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.0f\n", 2.5);
	ret2 = ft_printf("mine:%.0f\n", 2.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.2f\n", 2.56);
	ret2 = ft_printf("mine:%.2f\n", 2.56);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.4f\n", 2.56);
	ret2 = ft_printf("mine:%.4f\n", 2.56);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	ret2 = ft_printf("mine:{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%8.4f\n", 2.56);
	ret2 = ft_printf("mine:%8.4f\n", 2.56);
	printf("%d %d\n", ret1, ret2);
	// ft_printf("%.15f\n", 3.141593);
	// ft_printf("%#f %#.f\n", (double)-56.2012685, (double)-56.2012685);
}

void	pointer_test()
{
	int a = 42;
	int *i = &a;
	char *s = "abcde";
	int ret1, ret2;
	ret1 = printf("norm:%2.5p\n", 123456789);
	ret2 = ft_printf("mine:%2.5p\n", 123456789);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5.2p\n", 123456789);
	ret2 = ft_printf("mine:%5.2p\n", 123456789);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%4.4p\n", 123456789);
	ret2 = ft_printf("mine:%4.4p\n", 123456789);
	ret1 = printf("norm:%2.5p\n", 0);
	ret2 = ft_printf("mine:%2.5p\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5.2p\n", 0);
	ret2 = ft_printf("mine:%5.2p\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%4.4p\n", 0);
	ret2 = ft_printf("mine:%4.4p\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5p\n", 1);
	ret2 = ft_printf("mine:%5p\n", 1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%.p\n", 0);
	ret2 = ft_printf("mine:%.p\n", 0);
	printf("%d %d\n", ret1, ret2);
}

int main(void)
{
	// string_test();
	// char_test();
	// d_test();
	// dl_test();
	// dll_test();
	// dh_test();
	// dhh_test();
	// i_test();
	// u_test();
	// x_test();
	// X_test();
	// percent_test();
	// xX_hash_test();
	// pointer_test();
	// o_test();
	// ohh_test();
	// o_hash_test();

	// ellas_tests();
	//float_test();

	int ret1, ret2;
	ret1 = printf("mine:%-8d\n", -42);
	ret2 = ft_printf("mine:%-8d\n", -42);
	printf("%d %d\n", ret1, ret2);
	// system("leaks ft_printf");
	return (0);
}
