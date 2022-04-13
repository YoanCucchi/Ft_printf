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

char *test;
test = "c'est beau % :)";
	printf("%s\n", test);
	ft_printf("%s\n", test);
	printf("%i", 353234);

//	system("leaks ft_printf");
	return(0);	
}
