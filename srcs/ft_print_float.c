/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:33:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/25 13:33:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static void	ft_len_zero_handling_float(t_parameter *p, double n)
{
	if (p->width > p->precision)
		while (p->width-- > p->precision + 2)
			p->return_value = ft_print_char(' ');
	p->len = 1;
	n = n + 1;
	return ;
}

int	ft_print_float(t_parameter *p, va_list *ap)
{
	double	n;
	char	*nbr;

// precision = nbr of decimal to be printed
	n = va_arg(*ap, double);
	// printf("n = %f\n", n);
	if (!p->precision)
		p->precision = 6;
	nbr = split_float(n, p);
	p->len = 0;
	ft_len_zero_handling_float(p, n);
	p->return_value += ft_putnstr(nbr, (p->precision + 2));
	return (0);
}