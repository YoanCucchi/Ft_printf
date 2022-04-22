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
// PROBLEME AVEC HH LENGTH SPECIFIER A CAUSE DU CHANGEMENT EN CHAR.
// %[Flags][Width].[Precision][Length]
	printf("norm printf:%0#5.5llx\n", 4512);
	ft_printf("myfk printf:%0#5.5llx\n", 4512);
//	printf("real printf: %c\n", 't');
//	ft_printf("my printf: %c\n", 't');

// celui la bug
//	ret1 = printf("norm printf:%0#5.5hhx\n", 423);
//	ret2 = ft_printf("myfk printf:%0#5.5hhx\n", 423);

//	printf("%%\n");
//	ft_printf("%%\n");
//	system("leaks ft_printf");
	return(0);
}
