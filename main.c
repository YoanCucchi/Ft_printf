/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuustin <spuustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:29:13 by spuustin          #+#    #+#             */
/*   Updated: 2022/06/14 14:01:05 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>


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
	ret1 = printf("norm:%#08d\n", -42);
	ret2 = ft_printf("mine:%#08d\n", -42);
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
	ret1 = printf("norm:%03d\n", -0);
	ret2 = ft_printf("mine:%03d\n", -0);
	printf("%d %d\n", ret1, ret2);
}

static void i_test()
{
	int n = 4294967295;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%i\n", n);
	ret2 = ft_printf("mine:%i\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%i %i %i\n", 42242, -2442424, 0);
	ret2 = ft_printf("mine:%i %i %i\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#08i\n", -42);
	ret2 = ft_printf("mine:%#08i\n", -42);
	printf("%d %d\n", ret1, ret2);
}

static void u_test()
{
	int ret1, ret2;
	ret1 = printf("norm:%u\n", 4294967295);
	ret2 = ft_printf("mine:%u\n", 4294967295);
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
	ret1 = printf("norm:%-#6o\n", 2500);
	ret2 = ft_printf("mine:%-#6o\n", 2500);
	printf("%d %d\n", ret1, ret2);
}

static void x_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("norm:%x\n", n);
	ret2 = ft_printf("mine:%x\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%x\n", 4294967296);
	ret2 = ft_printf("mine:%x\n", 4294967296);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%10x\n", 42);
	ret2 = ft_printf("mine:%10x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#05.2X\n", 52);
	ret2 = ft_printf("mine:%#05.2X\n", 52);
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
	ret2  = ft_printf("%#x\n", 0);
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
	// ret1 = printf("norm:%X\n", n);
	// ret2 = ft_printf("mine:%X\n", n);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%X %X %X\n", 42242, -2442424, 0);
	// ret2 = ft_printf("mine:%X %X %X\n", 42242, -2442424, 0);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%#08.2X\n", 422424);
	// ret2 = ft_printf("mine:%#08.2X\n", 422424);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%#08x\n", 1);
	// ret2 = ft_printf("mine:%#08x\n", 1);
	// printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%#08.2x\n", 12);
	ret2 = ft_printf("mine:%#08.2x\n", 12);
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
	ret1 = printf("norm:%\n");
	ret2 = ft_printf("mine:%\n");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%%\n");
	ret2 = ft_printf("mine:%%\n");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%sjeccu\n", NULL);
	ret2 = ft_printf("mine:%sjeccu\n", NULL);
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
	ret1 = printf("norm:%-19p\n", &a);
	ret2 = ft_printf("mine:%-19p\n", &a);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%-5p\n", &a);
	ret2 = ft_printf("mine:%-5p\n", &a);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%4p\n", &s);
	ret2 = ft_printf("mine:%4p\n", &s);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("norm:%5p\n", 0);
	ret2 = ft_printf("mine:%5p\n", 0);
	printf("%d %d\n", ret1, ret2);
}

int main(void)
{
	// string_test();
	//char_test();
	//d_test();
	//i_test();
	//u_test();
	// x_test();
	// X_test();
	//percent_test();
	//xX_hash_test();
	// pointer_test();

	//o_test();
	//o_hash_test();
	// ellas_tests();
	// float_test();
//	int ret1, ret2;;
//	ret1 = printf("norm:%hu\n", -32768);
//	ret2 = ft_printf("mine:%hu\n", -32768);
	int ret1,ret2;
	// ret1 = printf("norm:{%u}\n", -742);
	// ret2 = ft_printf("mine:{%u}\n", -742);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("%12f\n", 1.935693569356);
	// ret2 = ft_printf("%12f\n", 1.935693569356);
	
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%05d\n", -42);
	// ret2 = ft_printf("mine:%05d\n", -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%03.2d}\n", -1);
	// ret2 = ft_printf("mine:{%03.2d}\n", -1);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%#05.2X\n", 52);
	// ret2 = ft_printf("mine:%#05.2X\n", 52);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%5p\n", 0);
	// ret2 = ft_printf("mine:%5p\n", 0);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%+-10.3d\n", 1234);
	// ret2 = ft_printf("mine:%+-10.3d\n", 1234);
	// printf("%d %d\n", ret1, ret2);
	
	// ret1 = printf("norm:%ld\n", 922337203685477580);
	// ret2 = ft_printf("mine:%ld\n", 922337203685477580);
	// printf("%d %d\n", ret1, ret2);
	
	// ret1 = printf("norm:%lld\n", -9223372036854775808);
	// ret2 = ft_printf("mine:%lld\n", -9223372036854775808);
	// printf("%d %d\n", ret1, ret2);
	
	// ret1 = printf("norm:%-015.8d\n", 1000000);
	// ret2 = ft_printf("mine:%-015.8d\n", 1000000);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.d %.0d\n", 42, 43);
	// ret2 = ft_printf("mine:%.d %.0d\n", 42, 43);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.d %.0d\n", 0, 0);
	// ret2 = ft_printf("mine:%.d %.0d\n", 0, 0);
	// printf("%d %d\n", ret1, ret2);

	// printf("mainostauko 1\n");
	// ret1 = printf("norm:'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	// ret2 = ft_printf("mine:'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	// ret2 = ft_printf("mine:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	// ret2 = ft_printf("mine:'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	// printf("%d %d\n", ret1, ret2);

	
	// ret1 = printf("norm:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	// ret2 = ft_printf("mine:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	// printf("%d %d\n", ret1, ret2);
	// printf("mainostauko 3\n");
	// ret1 = printf("norm:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	// ret2 = ft_printf("mine:'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%5.x %5.0x\n", 0, 0);
	// ret2 = ft_printf("mine:%5.x %5.0x\n", 0, 0);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.x %.0x\n", 0, 0);
	// ret2 = ft_printf("mine:%.x %.0x\n", 0, 0);
	// printf("%d %d\n", ret1, ret2);
	// ft_printf("%5.x %5.0x\n", 0, 0);
	// ret1 = printf("norm:%\n");
	// ret2 = ft_printf("mine:%\n");
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%%\n");
	// ret2 = ft_printf("mine:%%\n");
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%sjeccu\n", NULL);
	// ret2 = ft_printf("mine:%sjeccu\n", NULL);
	// printf("%d %d\n", ret1, ret2);
	// ft_printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.5s\n", NULL);
	// ret2 = ft_printf("mine:%.5s\n", NULL);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%s\n", NULL);
	// ret2 = ft_printf("mine:%s\n", NULL);
	// printf("%d %d\n", ret1, ret2);


	// ret1 = printf("norm:%f\n", 3.5);
	// ret2 = ft_printf("mine:%f\n", 3.5);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.0f\n", 5.5);
	// ret2 = ft_printf("mine:%.0f\n", 5.5);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.0f\n", 0.5);
	// ret2 = ft_printf("mine:%.0f\n", 0.5);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.2f\n", 2.56);
	// ret2 = ft_printf("mine:%.2f\n", 2.56);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:%.4f\n", 3.56);
	// ret2 = ft_printf("mine:%.4f\n", 3.56);
	// printf("%d %d\n", ret1, ret2);
	// ret1 = printf("norm:{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// ret2 = ft_printf("mine:{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%010.1lld\n", 150000);
	// ret2 = ft_printf("mine:%010.1lld\n", 150000);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%f\n", -0.0);
	// ret2 = ft_printf("mine:%f\n", -0.0);
	// printf("%d %d\n", ret1, ret2);
	
	// ret1 = printf("norm:%.2f\n", -958.125000);
	// ret2 = ft_printf("mine:%.2f\n", -958.125000);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%ho}\n", -42, -42, -42);
	// ret2 = ft_printf("mine:{%ho}\n", -42, -42, -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%o}\n", -42, -42, -42);
	// ret2 = ft_printf("mine:{%o}\n", -42, -42, -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%hho}\n", -42, -42, -42);
	// ret2 = ft_printf("mine:{%hho}\n", -42, -42, -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%o} {%ho} {%hho}\n", -42, -42, -42);
	// ret2 = ft_printf("mine:{%o} {%ho} {%hho}\n", -42, -42, -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%0.3d\n", -8462);
	// ret2 = ft_printf("mine:%0.3d\n", -8462);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%08.3d\n", -8473);
	// ret2 = ft_printf("mine:%08.3d\n", -8473);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%08.3i\n", 837);
	// ret2 = ft_printf("mine:%08.3i\n", 837);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%06.7d\n", -2375);
	// ret2 = ft_printf("mine:%06.7d\n", -2375);
	// printf("%d %d\n", ret1, ret2);

// static void *a12;

// 	ret1 = printf("norm:{%15p}\n", &a12);
// 	ret2 = ft_printf("mine:{%15p}\n", &a12);
// 	printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:{%-7p}\n", 412);
	// ret2 = ft_printf("mine:{%-7p}\n", 412);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%.5f\n", -958.12500);
	// ret2 = ft_printf("mine:%.5f\n", -958.12500);
	// printf("%d %d\n", ret1, ret2);

// %.3f: {-958.125}
//%.4f: {-958.1250}$
//%.5f: {-958.12500}$
	ret1 = printf("norm:%.17lf\n", 65465446.1844674407370955115);
	ret2 = ft_printf("mine:%.17lf\n", 65465446.1844674407370955115);
	printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%08.3d\n", -8473);
	// ret2 = ft_printf("mine:%08.3d", -8473);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%o %hho\n", -42, -42);
	// ret2 = ft_printf("mine:%o %hho\n", -42, -42);
	// printf("%d %d\n", ret1, ret2);

	// ret1 = printf("norm:%0i\n", -42);
	// ret2 = ft_printf("mine:%0i\n", -42);
	// printf("%d %d\n", ret1, ret2);

	// First line of code: {return test("%% *.5i 42 == |% *.5i|
	// First line of code: {return test("%0-3.3i", -8462);}
	// First line of code: {return test("%03.3i", -8462);}
	// First line of code: {return test("%0-3.3d", -8462);}
	// First line of code: {return test("%03.3d", -8462);}

	// system("leaks a.out");
	return (0);
}
