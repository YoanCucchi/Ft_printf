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
	n = va_arg(args, int);
	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	return_value += write(1, nbr, len);
	return(return_value);
}