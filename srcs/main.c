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

int	main(void)
{
//	int a;
//	int *b;
//	int c;

//	a = 2545;
//	b = &a;
//	c = 1111;
//	printf("normal : %d\n%d\n", a, c);
//	ft_printf("mine : %d\n%d\n", a, c );
//	printf("normal : %+i\n", a);
//	ft_printf("mine : %+i\n", a);
//	printf("normal : %+u\n", a);
//	ft_printf("mine : %+u\n", a);



//printf("normal = %d", 50);
//ft_printf("mine = %d", 50);

	char *test, *test2;
	int ret1, ret2;
	test = "c'est beau :)";
	test2 = "c'est pas beau :(";
	ret1 = printf("real printf: %s\n%s\n", test, test2);
	ret2 = ft_printf("my printf: %s\n%s\n", test, test2);
//	printf("%d %d\n", ret1, ret2);
//	printf("real printf: %c\n", 't');
//	ft_printf("my printf: %c\n", 't');

//	printf("%%\n");
//	ft_printf("%%\n");
//	system("leaks ft_printf");
	return(0);
}
