/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(t_parameter p, va_list args)
{
	int n;
	int len;
	char *nbr;
	int return_value;

	return_value = 0;
	nbr = NULL;
//	printf("ici : %c\n", p.specifier);
	n = va_arg(args, int);
	printf("n = %d\n", n);
	if (p.plus == 1 && p.specifier != 'u')
		return_value += write (1, "+", 1);
	if (p.minus == 1 && p.specifier != 'u')
		return_value += write (1, "-", 1);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	return_value += write(1, nbr, len);
	return(return_value);
}
