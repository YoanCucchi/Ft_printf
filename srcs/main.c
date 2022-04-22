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
// %[Flags][Width].[Precision][Length]
	int ret1, ret2;
	ret1 = printf("norm printf:%10.10x\n", 4321);
	ret2 = ft_printf("myfk printf:%10.10x\n", 4321);
	printf("%d %d\n", ret1, ret2);
//	printf("real printf: %c\n", 't');
//	ft_printf("my printf: %c\n", 't');

// celui la bug
//	ret1 = printf("norm printf:%0#20.8x\n", 423);
//	ret2 = ft_printf("myfk printf:%0#20.8x\n", 423);

//	printf("%%\n");
//	ft_printf("%%\n");
//	system("leaks ft_printf");
	return(0);
}
