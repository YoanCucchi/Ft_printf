/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:55:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/10 15:56:00 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_recursive_octal(t_parameter *p, size_t n, size_t iteration)
{
	int		remainder;
	char	character;

	if (n > 0 || !iteration)
	{
		remainder = n % 8;
		character = OCTAL[remainder];
		n /= 8;
		iteration = 1;
		p->return_value += ft_recursive_octal(p, n, iteration);
		p->return_value += ft_print_char(character);
	}
	return (0);
}

void	ft_len_zero_handling_octal(t_parameter *p, long long n, int len)
{
	p->highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	if (n == 0 && p->dot && !p->sharp)
		len = 0;
	if (p->sharp && n != 0 && \
	(p->width >= p->precision || !p->precision || p->highest_value < len))
		p->highest_value--;
	if (p->width > p->precision && !p->minus)
	{
		while (p->highest_value-- > who_is_biggest_of_2(p->precision, len))
			if (p->width > len)
			{
				if (p->zero)
					p->return_value += ft_print_char('0');
				else
					p->return_value += ft_print_char(' ');
			}
	}
	if (p->precision > len)
		while (p->precision > len++)
			p->return_value += ft_print_char('0');
	else if (p->precision < len && p->sharp && n != 0)
		p->return_value += ft_print_char('0');
}
