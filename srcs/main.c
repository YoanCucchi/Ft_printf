/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:03:54 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/12 16:04:10 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
//	int a;
//	int *b;
//
//	a = 2545;
//	b = &a;
//	printf("%p\n", b);
//	ft_printf("%p\n", b);



printf("normal = %d", 50);
ft_printf("mine = %d", 50);

//	char *test, *test2;
//	int ret1, ret2;
//	test = "c'est beau :)";
//	test2 = "c'est pas beau :(";
//	ret1 = printf("real printf: %s\n", test);
//	ret2 = ft_printf("my printf: %s\n", test);
//	printf("%d %d\n", ret1, ret2);
//	printf("real printf: %c\n", 't');
//	ft_printf("my printf: %c\n", 't');

//	printf("%%\n");
//	ft_printf("%%\n");
//	system("leaks ft_printf");
	return(0);
}
