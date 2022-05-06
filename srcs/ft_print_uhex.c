/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 04:25:11 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/06 04:25:13 by ycucchi          ###   ########.fr       */
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

int	ft_print_uchar_hex(t_parameter *p, va_list *ap)
{
	int		n;
	int		len;

	n = va_arg(*ap, int);
	len = ft_nbrlen(n, 16);
	if (p->sharp && n != 0)
		p->width -= 2;
	if (!p->precision)
		p->precision = p->width;
	if (p->precision > len)
		while (p->width-- - p->precision > 0)
			p->return_value += ft_print_char(' ');
	while (p->precision-- - len > 0)
		p->return_value += ft_print_char(' ');
	if (p->sharp && n != 0)
		p->return_value += ft_putnstr("0x", 2);
	p->return_value += ft_recursive_hex(p, n, n);
	return (0);
}

int	ft_print_p(t_parameter *p, va_list *ap)
{
	unsigned long	n;
	int				len;

	n = va_arg(*ap, unsigned long);
	len = ft_nbrlen(n, 16);
	p->width -= 2;
	if (p->precision > len)
		while (p->width-- - p->precision > 0)
			p->return_value += ft_print_char(' ');
	p->return_value += ft_putnstr("0x", 2);
	while (p->precision-- - len > 0)
		p->return_value += ft_print_char('0');
	p->return_value += ft_recursive_hex(p, n, n);
	return (0);
}