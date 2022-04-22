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

static int	ft_nbrlen(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

static int	ft_recursive_hex(t_parameter p, size_t n, size_t iteration)
{
	int		return_value;
	int		remainder;
	char	character;

	return_value = 0;
	if (n > 0 || (!iteration && (p.specifier != 'p' || !p.dot)))
	{
		remainder = n % 16;
		if (p.specifier != 'X')
			character = HEXALOWCASE[remainder];
		else
			character = HEXAUPCASE[remainder];
		n /= 16;
		iteration = 1;
		return_value += ft_recursive_hex(p, n, iteration);
		return_value += ft_print_char(character);
	}
	return (return_value);
}

int	ft_print_hex(t_parameter p, va_list args)
{
	int		return_value;
	int		n;
	int		len;
	
	return_value = 0;
	n = va_arg(args, int);
	len = ft_nbrlen(n, 16);
	if (!p.precision)
		p.precision = len;
	if (p.sharp == 1)
		p.width -= 2;
	if (p.width > p.precision)
		while (p.width-- - p.precision > 0)
			return_value += ft_print_char(' ');
	if (p.specifier == 'p' || p.sharp == 1)
		return_value += ft_putnstr("0x", 2);
	while (p.precision-- - len > 0)
		return_value += ft_print_char('0');
	return_value += ft_recursive_hex(p, n, n);
	return (return_value);
}

int	ft_print_hex_hh(t_parameter p, va_list args)
{
	int				return_value;
	unsigned char	n;
	int				len;
	
	return_value = 0;
	n = va_arg(args, int);
	len = ft_nbrlen(n, 16);
	if (!p.precision)
		p.precision = len;
	if (p.sharp == 1)
		p.width -= 2;
	if (p.width > p.precision)
		while (p.width-- - len > 0)
			return_value += ft_print_char(' ');
	if (p.specifier == 'p' || p.sharp == 1)
		return_value += ft_putnstr("0x", 2);
	while (p.precision-- - len > 0)
		return_value += ft_print_char('0');
	return_value += ft_recursive_hex(p, n, n);
	return (return_value);
}

int	ft_print_p(t_parameter p, va_list args)
{
	int				return_value;
	unsigned long	n;
	int				len;
	
	return_value = 0;
	n = va_arg(args, unsigned long);
	len = ft_nbrlen(n, 16);
	if (!p.precision)
		p.precision = len;
	if (p.specifier == 'p' || p.sharp)
		p.width -= 2;
	if (p.width > p.precision)
		while (p.width-- - len > 0)
			return_value += ft_print_char(' ');
	if (p.specifier == 'p' || p.sharp == 1)
		return_value += ft_putnstr("0x", 2);
	while (p.precision-- - len > 0)
		return_value += ft_print_char('0');
	return_value += ft_recursive_hex(p, n, n);
	return (return_value);
}
