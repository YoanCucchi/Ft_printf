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
	ret1 = printf("printing a string from pointer: %s\n", str1);
	ret2 = ft_printf("printing a string from pointer: %s\n", str1);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("printing null: %s\n", NULL);
	ret2 = ft_printf("printing null: %s\n", NULL);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("printing two strings: %s%s\n", str1, str2);
	ret2 = ft_printf("printing two strings: %s%s\n", str1, str2);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.2s is a string\n", "this");
	ret2 = ft_printf("%.2s is a string\n", "this");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.2s is a string\n", "");
	ret2 = ft_printf("%.2s is a string\n", "");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%-.2s is a string\n", "this");
	ret2 = ft_printf("%-.2s is a string\n", "this");
	printf("%d %d\n", ret1, ret2);
}
static void char_test()
{
	char a = 'a';
	char b = 'b';
	int ret1, ret2;
	ret1 = printf("%c\n", a);
	ret2 = ft_printf("%c\n", a);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("printing two chars: %c %c\n", a, b);
	ret2 = ft_printf("printing two chars: %c %c\n", a, b);
	printf("%d %d\n", ret1, ret2);
}

static void d_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("%d\n", n);
	ret2 = ft_printf("%d\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%d %d %d\n", 42242, -2442424, 0);
	ret2 = printf("%d %d %d\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%0+5d\n", 42);
	ret2 = ft_printf("%0+5d\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%5d\n", -42);
	ret2 = ft_printf("%5d\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%0+5d\n", -42);
	ret2 = ft_printf("%0+5d\n", -42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%03.2d\n", 0);
	ret2 = ft_printf("%03.2d\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("{%0-3d}\n", 0);
	ret2 = ft_printf("{%0-3d}\n", 0);
	printf("%d %d\n", ret1, ret2);
}

static void i_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("%i\n", n);
	ret2 = ft_printf("%i\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%i %i %i\n", 42242, -2442424, 0);
	ret2 = printf("%i %i %i\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
}

static void u_test()
{
	int ret1, ret2;
	ret1 = printf("% u\n", 4294967295);
	ret2 = ft_printf("% u\n", 4294967295);
	printf("%d %d\n", ret1, ret2);
}

static void o_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("%o\n", n);
	ret2 = ft_printf("%o\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%-#6o\n", 2500);
	ret2 = ft_printf("%-#6o\n", 2500);
	printf("%d %d\n", ret1, ret2);
}

static void x_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("%x\n", n);
	ret2 = ft_printf("%x\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%x\n", 4294967296);
	ret2 = ft_printf("%x\n", 4294967296);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%10x\n", 42);
	ret2 = ft_printf("%10x\n", 42);
	printf("%d %d\n", ret1, ret2);
	
}

static void o_hash_test()
{
	int ret1, ret2;
	ret1 = printf("@moulitest: %#x %#o\n", 0, 0);
	ret2 = ft_printf("@moulitest: %#x %#o\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ret2 = ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%#x\n", 0);
	ret2  = ft_printf("%#x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("@moulitest: %#.x %#.0x|\n", 0, 0);
	ret2 = ft_printf("@moulitest: %#.x %#.0x|\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
}

static void xX_hash_test()
{
	int ret1, ret2;
	ret1 = printf("%#x\n", 0);
	ret2 = ft_printf("%#x\n", 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%#8x\n", 42);
	ret2 = ft_printf("%#8x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ret2 = ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("@moulitest: %.x %.0x\n", 0, 0);
	ret2 = ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("@moulitest: %5.x %5.0x\n", 0, 0);
	ret2 = ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%#08x\n", 42);
	ret2 = ft_printf("%#08x\n", 42);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%#-08x\n", 42);
	ret2 = ft_printf("%#-08x\n", 42);
	printf("%d %d\n", ret1, ret2);
}

static void X_test()
{
	int n = 42;
	int m = -42;
	int ret1, ret2;
	ret1 = printf("%X\n", n);
	ret2 = ft_printf("%X\n", n);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%X %X %X\n", 42242, -2442424, 0);
	ret2 = printf("%X %X %X\n", 42242, -2442424, 0);
	printf("%d %d\n", ret1, ret2);
}
static void percent_test()
{
	int ret1, ret2;
	ret1 = printf("%%\n");
	ret2 = ft_printf("%%\n");
	printf("%d %d\n", ret1, ret2);
}
static void ellas_tests()
{
	int ret1,ret2;

	ret1 = printf("%ld\n", 922337203685477580);
	ret2 = ft_printf("%ld\n", 922337203685477580);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("%lld\n", -922337203685477580);
	ret2 = ft_printf("%lld\n", -922337203685477580);
	printf("%d %d\n", ret1, ret2);
	
	ret1 = printf("%-015.8d\n", 1000000);
	ret2 = ft_printf("%-015.8d\n", 1000000);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.d %.0d\n", 42, 43);
	ret2 = ft_printf("%.d %.0d\n", 42, 43);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.d %.0d\n", 0, 0);
	ret2 = ft_printf("%.d %.0d\n", 0, 0);
	printf("%d %d\n", ret1, ret2);

	printf("mainostauko 1\n");
	ret1 = printf("'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("'%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-17.11x' '%#-17.11X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("'%%#-10.10' '%#-17.17o' '%-17.17u' '%#-11.17x' '%#-11.17X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);

	
	ret1 = printf("'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	ret2 = ft_printf("'%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
	printf("%d %d\n", ret1, ret2);
	printf("mainostauko 3\n");
	ret1 = printf("'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	ret2 = ft_printf("'%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%5.x %5.0x\n", 0, 0);
	ret2 = ft_printf("%5.x %5.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.x %.0x\n", 0, 0);
	ret2 = ft_printf("%.x %.0x\n", 0, 0);
	printf("%d %d\n", ret1, ret2);
	ft_printf("%5.x %5.0x\n", 0, 0);
	ret1 = printf("%\n");
	ret2 = ft_printf("%\n");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%%\n");
	ret2 = ft_printf("%%\n");
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%sjeccu\n", NULL);
	ret2 = ft_printf("%sjeccu\n", NULL);
	printf("%d %d\n", ret1, ret2);
	ft_printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.5s\n", NULL);
	ret2 = ft_printf("%.5s\n", NULL);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%s\n", NULL);
	ret2 = ft_printf("%s\n", NULL);
	printf("%d %d\n", ret1, ret2);
}
void	float_test()
{
	int ret1, ret2;
	ret1 = printf("%f\n", 3.5);
	ret2 = ft_printf("%f\n", 3.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.0f\n", 3.5);
	ret2 = ft_printf("%.0f\n", 3.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.0f\n", 2.5);
	ret2 = ft_printf("%.0f\n", 2.5);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.2f\n", 2.56);
	ret2 = ft_printf("%.2f\n", 2.56);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("%.4f\n", 2.56);
	ret2 = ft_printf("%.4f\n", 2.56);
	printf("%d %d\n", ret1, ret2);
	ret1 = printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	ret2 = ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	printf("%d %d\n", ret1, ret2);
	// ret1 = printf("%8.4f\n", 2.56);
	// ret2 = ft_printf("%8.4f\n", 2.56);
	// printf("%d %d\n", ret1, ret2);
	//ft_printf("%.15f\n", 3.141593);
	//ft_printf("%#f %#.f\n", (double)-56.2012685, (double)-56.2012685);
}

void	pointer_test()
{
	int a = 42;
	int *i = &a;
	char *s = "abcde";
	int ret1, ret2;
	ret1 = printf("%#2.9x\n", 1234);
	ret2 = ft_printf("%#2.9x\n", 1234);
	printf("%d %d\n", ret1, ret2);
}

int main(void)
{
	//string_test();
	//char_test();
	//d_test();
	//i_test();
//	o_test();
//	u_test();
//	 x_test();
	// X_test();
	//o_hash_test();
	//xX_hash_test();
	//percent_test();
	//ellas_tests();
	//float_test();
//	pointer_test();
int ret1, ret2;
	ret1 = printf("norm:%#0llp\n", 42);
	ret2 = ft_printf("mine:%#08llp\n", 42);
	printf("%d %d\n", ret1, ret2);
	system("leaks ft_printf");
	return (0);
}
