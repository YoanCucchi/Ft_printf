/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:01 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_recursive_hex(t_parameter *p, size_t n, size_t iteration)
{
	int		remainder;
	char	character;

	if (n > 0 || (!iteration && (p->specifier != 'p' || !p->dot)))
	{
		remainder = n % 16;
		if (p->specifier != 'X')
			character = HEXALOWCASE[remainder];
		else
			character = HEXAUPCASE[remainder];
		n /= 16;
		iteration = 1;
		p->return_value += ft_recursive_hex(p, n, iteration);
		p->return_value += ft_print_char(character);
	}
	return (0);
}

void	ft_len_zero_handling_hex(t_parameter *p, long long n, int len)
{
	int	highest_value;

	highest_value = 0;
	highest_value = who_is_biggest_of_3(p->precision, p->width, len);
	if (p->sharp && n != 0)
		highest_value -= 2;
	if (p->width - p->precision > 0)
	{
		while (highest_value-- > who_is_biggest_of_2(p->precision, len))
		{
			if (p->zero && (p->precision > len || !p->precision) && n != 0)
				p->return_value += ft_print_char('0');
			else
				p->return_value += ft_print_char(' ');
		}
	}
	if (p->sharp && n != 0)
		p->return_value += ft_putnstr("0x", 2);
	while (p->precision-- - len >= 0)
		p->return_value += ft_print_char('0');
}

int	ft_print_hex(t_parameter *p, va_list *ap)
{
	unsigned int	n;
	int				len;

	n = (unsigned int)va_arg(*ap, unsigned int);
	len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n, len);
	if (n == 0 && p->dot && p->precision <= 0)
		return(0);
	else
		p->return_value += ft_recursive_hex(p, n, n);
	return (0);
}
