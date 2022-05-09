/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:13:14 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/09 10:13:16 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_recursive_octal(t_parameter *p, size_t n, size_t iteration)
{
	int		remainder;
	char	character;

	if (n > 0 || (!iteration && (p->specifier != 'p' || !p->dot)))
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

int	ft_print_octal(t_parameter *p, va_list *ap)
{
	unsigned int	n;
	int				len;

	n = va_arg(*ap, unsigned int);
	len = ft_nbrlen(n, 8);
	ft_len_zero_handling(p, n, len);
	if (n == 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_long_o(t_parameter *p, va_list *ap, unsigned long n)
{
	int	len;

	len = ft_nbrlen(n, 8);
	ft_len_zero_handling(p, n, len);
	if (n == 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_llong_o(t_parameter *p, va_list *ap, unsigned long long n)
{
	int	len;

	len = ft_nbrlen(n, 8);
	ft_len_zero_handling(p, n, len);
	if (n == 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_short_o(t_parameter *p, va_list *ap, unsigned short n)
{
	int	len;

	len = ft_nbrlen(n, 8);
	ft_len_zero_handling(p, n, len);
	if (n == 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}

int	ft_print_char_octal(t_parameter *p, va_list *ap, unsigned short n)
{
	int	len;

	len = ft_nbrlen(n, 8);
	ft_len_zero_handling(p, n, len);
	if (n != 0 && p->precision <= 0 && !p->sharp)
		p->return_value += ft_recursive_octal(p, n, n);
	else if (n != 0 && p->precision < 0 && p->sharp)
		p->return_value += ft_print_char(' ');
	else
		p->return_value += ft_recursive_octal(p, n, n);
	return (0);
}